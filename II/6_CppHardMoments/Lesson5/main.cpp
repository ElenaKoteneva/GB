// Урок 5. Ассоциативные контейнеры STL. Котенева Е.В.

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <array>
#include <list>
#include <set>
#include <map>
#include <string>
#include <iterator>

/* 1. Создать шаблонную функцию, которая принимает итераторы на начало и конец последовательности слов,
 * и выводящую в консоль список уникальных слов (если слово повторяется больше 1 раза,
 * то вывести его надо один раз). Продемонстрировать работу функции, передав итераторы различных типов.
 * */

template <class Iterator>
void uniqWord(Iterator begin, Iterator end)
{
    std::set<std::string> temp{};
    std::for_each(begin, end, [&temp](const std::string& s){temp.insert(s);});
    copy(temp.begin(), temp.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
}

int main()
{
   std::cout << "----------- 1 Unique word ----------" << std::endl;

    std::cout << "Vector: ";
    std::vector<std::string> v = {"hot", "cold", "hot", "map"};
    uniqWord(v.begin(), v.end());

    std::cout << "List: ";
    std::list l {"hot", "cold", "hot", "map"};
    uniqWord(l.begin(), l.end());

    std::cout << "Deque: ";
    std::deque d {"hot", "cold", "hot", "map"};
    uniqWord(d.begin(), d.end());

    std::cout << "Array: ";
    std::array ar {"hot", "cold", "hot", "map"};
    uniqWord(ar.begin(), ar.end());


    /* 2. Используя ассоциативный контейнер, напишите программу, которая будет считывать данные,
     *  введенные пользователем из стандартного потока ввода и разбивать их на предложения.
     *  Далее программа должна вывести пользователю все предложения, отсортировав их по длине.
     * */

    std::cout << "----------- 2 ----------" << std::endl;

    std::map<uint16_t, std::string> text;
    std::string data = "";
    std::string temp = "";
    std::cout << "Enter text -> " << std::endl;
    std::getline(std::cin, data);
    for (char c : data)
    {
        temp += c;
        if ((c == '.') || (c == '!') || (c == '?'))
        {
            text.try_emplace(temp.size(), temp);
            temp = "";
        }
    }
    std::cout << "Result:" << std::endl;
    for (auto& [key, dat] : text) std::cout << dat << std::endl;

    return 0;
}

