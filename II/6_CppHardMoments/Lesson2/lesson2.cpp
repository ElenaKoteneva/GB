//Урок 2. Cpp. Сложные моменты. Котенева Е.В.

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <string>

using namespace std;

class Timer
{
private:
      using clock_t = std::chrono::high_resolution_clock;
      using second_t = std::chrono::duration<double, std::ratio<1> >;

      std::string m_name;
      std::chrono::time_point<clock_t> m_beg;
      double elapsed() const
      {
            return std::chrono::duration_cast<second_t>(clock_t::now() -m_beg).count();
      }

public:
      Timer() : m_beg(clock_t::now()) { }
      Timer(std::string name) : m_name(name), m_beg(clock_t::now()) { }

      void start(std::string name) {
            m_name = name;
            m_beg = clock_t::now();
      }
      void print() const {
            std::cout << m_name << ":\t" << elapsed() * 1000 << " ms" << '\n';
      }
};


/* 1. Реализовать шаблонную функцию Swap, которая принимает 2 указателя и обменивает местами значения,
 * на которые указывают эти указатели (нужно обменивать именно указатели, переменные должны оставаться
 * в тех же адресах памяти).
 * */

template <typename T>
void Swap(T** a, T** b)
{
    T* temp = *a;
    *a = *b;
    *b = temp;
}

/* 2.
 * Реализовать шаблонную функции SortPointers, которая принимает вектор указателей и сортирует
 * указатели по значениям, на которые они указывают.
 * */

template <typename T>
void SortPointers(vector<T*>& v)
{
    sort(v.begin(),v.end(),[](T* lhs, T* rhs){return *lhs < *rhs;});
}

template <typename T>
void printVector(vector<T*>& v)
{
    for (T* i : v)
    {
        cout << *i << " ";
    }
    cout << endl;
}

/* 3.
 * Подсчитать количество гласных букв в книге "Война и мир". Для подсчета использовать 4 способа:
 * - count_if и find
 * - count_if и цикл for
 * - цикл for и find
 * - 2 цикла for
 * Замерить время каждого способа подсчета.
 * */

uint64_t countifFind(string& vowels, ifstream& file)
{
    const Timer timer("Count_if - Find");
    uint64_t counter = 0;
    string buf;
    while (!file.eof())
    {
        getline(file, buf);
        counter += count_if(buf.begin(), buf.end(), [&vowels](char n) {return (int)vowels.find(n) != -1;});
    }
    timer.print();
    return counter;
}

uint64_t countifFor(string& vowels, ifstream& file)
{
    const Timer timer("Count_if - For");
    uint64_t counter = 0;
    string buf;
    while (!file.eof())
    {
        getline(file, buf);
        for (const char ch : vowels)
        {
            counter += count_if(buf.begin(), buf.end(), [&ch](char n) {return ch == n; });
        }
    }
    timer.print();
    return counter;
}

uint64_t forFind(string& vowels, ifstream& file)
{
    const Timer timer("For - Find");
    uint64_t counter = 0;
    string buf;
    while (!file.eof())
    {
        getline(file, buf);
        for(char s : buf)
        {
            if (vowels.find(s) != std::string::npos) ++counter;
        }
    }
    timer.print();
    return counter;
}

uint64_t forFor(string& vowels, ifstream& file)
{
    const Timer timer("For - For");
    uint64_t counter = 0;
    string buf;
    while (!file.eof())
    {
        getline(file, buf);
        for(char s : buf)
        {
            for(char ch : vowels)
                if(s == ch) ++counter;
        }
    }
    timer.print();
    return counter;
}

int main()
{
    /*cout << "---------- 1. Swap----------" << endl;

    int a, b, *pa, *pb, **ppa, **ppb;
    a = 1; b = 2;
    pa = &a; pb = &b;
    ppa = &pa; ppb = &pb;
    cout << "a=" << a << " " << "pa=" << pa << endl;
    cout << "b=" << b << " " << "pb=" << pb << endl;
    Swap(ppa, ppb);
    cout << "Swap:" << endl;
    cout << "a=" << a << " " << "pa=" << pa << endl;
    cout << "b=" << b << " " << "pb=" << pb << endl;

    cout << "---------- 2. Sort ----------" << endl;

    srand(time(NULL));
    vector<int *> numbers;
    for(size_t i=0; i<10; ++i)
        numbers.push_back(new int(rand()%100));
    printVector(numbers);
    SortPointers(numbers);
    cout << "Sorted vector:\n";
    printVector(numbers);
*/
    cout << "---------- 3. War and Peace ----------" << endl;

    ifstream file("War and peace.txt");
    if (!file)
    {
        cout << "Fail reading a file!\n";
    }
    else
    {
        string str;
        string vowels = {"aeiouyAEIOUY"};

        cout << forFor(vowels, file) << endl;
        file.clear();
        file.seekg(0);

        cout << forFind(vowels, file) << endl;
        file.clear();
        file.seekg(0);

        cout << countifFor(vowels, file) << endl;
        file.clear();
        file.seekg(0);

        cout << countifFind(vowels, file) << endl;
    }

    return 0;
}

