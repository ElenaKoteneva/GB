// Урок 6. Параллельное программирование. Многопоточность. Котенева Е.В.

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <set>

//#include <algorithm>

using namespace std::chrono_literals;


/* 1. Создайте потокобезопасную оболочку для объекта cout. Назовите ее pcout. Необходимо,
 * чтобы несколько потоков могли обращаться к pcout и информация выводилась в консоль.
 * Продемонстрируйте работу pcout.
 * */

std::mutex lock_cout;
void pcout(std::string data)
{
    std::lock_guard lg(lock_cout);
    std::cout << data << std::endl;
}

/* 2. Реализовать функцию, возвращающую i-ое простое число (например, миллионное простое число равно 15485863).
 * Вычисления реализовать во вторичном потоке. В консоли отображать прогресс вычисления.
 * */

std::mutex lockPrime;
bool isPrime(uint32_t number)
{
    bool result = true;
    for (uint32_t counter = 2; counter <= number / 2; ++counter)
    {
        if (number % counter == 0)
        {
            result = false;
            break;
        }
    }
    return result;
}

void findPrime(uint32_t serialNumber, std::pair<size_t, uint32_t> prime)
{
    uint32_t i{};
    for (i = 2; prime.first < serialNumber; ++i)
    {
        if (isPrime(i))
        {
            lockPrime.lock();
            prime.first++;
            int percent = 100 * prime.first / serialNumber;
            std::cout << "\rCalculate - " << percent << " %";
            lockPrime.unlock();
        }
    }
    prime.second = i - 1;
    std::cout << std::endl;
    std::cout << serialNumber << " simple number is " << prime.second << std::endl;
}

/* 3. Промоделировать следующую ситуацию. Есть два человека (2 потока): хозяин и вор.
 * Хозяин приносит домой вещи (функция добавляющая случайное число в вектор с периодичностью 1 раз в секунду).
 * При этом у каждой вещи есть своя ценность. Вор забирает вещи (функция, которая находит наибольшее
 * число и удаляет из вектора с периодичностью 1 раз в 0.5 секунд), каждый раз забирает вещь с
 * наибольшей ценностью.
 * */
std::mutex lock_things;
bool stop = false;//флаг, что удалили все вещи
void Owner(std::multiset<int>& things)
{
    while (!stop)
    {
        std::this_thread::sleep_for(1s);
        std::lock_guard lg(lock_things);
        things.insert(rand() % 100);
        for (auto thing : things)
        {
            std::cout << thing << " ";
        }
        std::cout << "\n";
    }

}

void Thief(std::multiset<int>& things)
{
    while (!things.empty())
    {
        std::this_thread::sleep_for(500ms);
        std::lock_guard lg(lock_things);
        things.erase(--things.end());
        if (things.size() == 0) stop = true;
        for (auto thing : things)
        {
            std::cout << thing << " ";
        }
        std::cout << "\n";

    }
}

int main()
{
   std::cout << "----------- 1 ----------" << std::endl;
   std::thread th1(pcout, "thread_1");
   std::thread th2(pcout, "thread_2");
   std::thread th3(pcout, "thread_3");
   th1.join();
   th2.join();
   th3.join();

   std::cout << "----------- 2 ----------" << std::endl;
   uint32_t serialNumber = 557;
   std::pair<size_t, uint32_t> prime{};
   std::thread thCalc(findPrime, serialNumber, ref(prime));
   thCalc.join();

   std::cout << "----------- 3 ----------" << std::endl;
   std::multiset<int> things{};
   for (size_t i = 0; i < 10; ++i)
       things.insert(rand() % 100);
   for (auto thing : things)
   {
       std::cout << thing << " ";
   }
   std::cout << std::endl;
   std::thread owner(Owner, ref(things));
   std::thread thief(Thief, ref(things));
   owner.join();
   thief.join();

   return 0;
}

