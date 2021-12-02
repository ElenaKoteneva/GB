// Урок 4. Алгоритмы STL. Котенева Е.В.

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <time.h>
#include <math.h>
#include <iterator>
#include <numeric>
#include <deque>
#include <array>
#include <list>

/* 1. Имеется отсортированный массив целых чисел. Необходимо разработать функцию insert_sorted,
 * которая принимает вектор и новое число и вставляет новое число в определенную позицию в векторе,
 * чтобы упорядоченность контейнера сохранялась. Реализуйте шаблонную функцию insert_sorted,
 * которая сможет аналогично работать с любым контейнером, содержащим любой тип значения.
 * */

void insertSorted(std::vector<int>& v, int newNumber)
{
    if (*v.begin() < *(v.begin() + 1))
    {
        auto up = upper_bound(v.begin(), v.end(), newNumber);
        v.insert(up, newNumber);
    }
    else if (*v.begin() > *(v.begin() + 1))
    {
        auto low = lower_bound(v.rbegin(), v.rend(), newNumber);
        v.insert(low.base(), newNumber);
    }
}

template <typename Container, typename T>
void insertSorted(Container& container, T newNumber)
{
    std::vector<T> temp{};
    size_t size_container = container.size();

    for ( T el : container)
    {
        temp.push_back(el);
    }
    if (*temp.begin() < *(temp.begin() + 1))
    {
        auto up = upper_bound(temp.begin(), temp.end(), newNumber);
        temp.insert(up, newNumber);
    }
    else if (*temp.begin() > *(temp.begin() + 1))
    {
        auto low = lower_bound(temp.rbegin(), temp.rend(), newNumber);
        temp.insert(low.base(), newNumber);
    }
    container.resize(size_container + 1);
    copy(temp.begin(), temp.end(), container.begin());
}

int main()
{
    std::cout << "----------- 1 InsertSort ----------" << std::endl;

    std::vector<int> v = {20, 30, 40, 50};
    std::vector<int> v2 = {50, 40, 30, 20};
    std::cout << "Vector: ";
    insertSorted(v, 10);
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, "  "));
    std::cout << std::endl;

    std::cout << "List: ";
    std::list l {20, 30, 40, 50};
    std::list l2 {50, 40, 30, 20};
    insertSorted(l2, 25);
    std::copy(l2.begin(), l2.end(), std::ostream_iterator<int>(std::cout, "  "));
    std::cout << std::endl;

    std::cout << "Deque: ";
    std::deque d {20, 30, 40, 50};
    std::deque d2 {50, 40, 30, 20};
    insertSorted(d2,55);
    std::copy(d2.begin(), d2.end(), std::ostream_iterator<int>(std::cout, "  "));
    std::cout << std::endl;

    std::cout << "Array: ";
    std::deque ar {20, 30, 40, 50};
    std::deque ar2 {50, 40, 30, 20};
    insertSorted(ar2, 55);
    std::copy(ar2.begin(), ar2.end(), std::ostream_iterator<int>(std::cout, "  "));
    std::cout << std::endl;

	
/* 2. Сгенерируйте вектор a, состоящий из 100 вещественный чисел, представляющий собой значения
 * аналогового сигнала. На основе этого массива чисел создайте другой вектор целых чисел b,
 * представляющий цифровой сигнал, в котором будут откинуты дробные части чисел. Выведите получившиеся
 * массивы чисел. Посчитайте ошибку, которой обладает цифровой сигнал по сравнению с аналоговым
 * по формуле (указана в методичке).
 * */
	
    std::cout << "----------- 2 ----------" << std::endl;
    srand(time(NULL));
    std::vector<float> a(10);
    std::vector<int> b(10);
    std::generate(a.begin(), a.end(), [](){return ((float)(rand()%21)/5);});
    std::copy(a.begin(), a.end(), std::ostream_iterator<float>(std::cout, " "));
    std::cout << std::endl;
    std::copy(a.begin(), a.end(), b.begin());
    std::copy(b.begin(), b.end(), std::ostream_iterator<int>(std::cout, "  "));
    std::cout <<std::endl << "Error = ";
    std::cout << std::inner_product(a.begin(), a.end(), b.begin(), 0.0, std::plus<float>(),
                                    [&](float a, int b){return pow((a-b), 2);}) << std::endl;

    return 0;
}

