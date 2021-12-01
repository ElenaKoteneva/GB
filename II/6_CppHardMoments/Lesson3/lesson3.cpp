// Урок 3. Последовательные контейнеры STL. Котенева Е.В.

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <math.h>


/* 1. Написать функцию, добавляющую в конец списка вещественных чисел элемент, значение которого
 * равно среднему арифметическому всех его элементов.
 * */

void addAverage(std::list<float>& l)
{
    float average = 0;
    for (auto element : l)
    {
        average += element;
    }
    average /= l.size();
    l.push_back(average);
}

/* 2. Создать класс, представляющий матрицу. Реализовать в нем метод, вычисляющий определитель матрицы.*/

class Matrix
{
private:
    size_t n{};
    std::vector<std::vector<int>> matrix;
public:

    Matrix(std::vector<std::vector<int>>& _matrix)
    {
        n = _matrix.size();
        matrix.resize(n);
        std::cout << "n = " << n << std::endl;
        for (size_t i = 0; i < n; ++i)
        {
            for (size_t j = 0; j < n; ++j)
            {
                matrix = _matrix;
            }
        }
    };

    ~Matrix()
    {
        matrix.resize(0);
    };

    void printMatrix() const
    {
        for (auto row : matrix)
        {
            std::cout << '[';
            for (int el : row)
            {
                std::cout << el << ' ';
            }
            std::cout << ']';
            std::cout << std::endl;
        }
    }

    int determinant(std::vector<std::vector<int>> matrix, size_t n) const
    {
        int result{};
        switch(n)
        {
            case 0: return 0;
            case 1: return matrix[0][0];
            case 2: return result = matrix[n-2][n-2] * matrix[n-1][n-1] -
                                    matrix[n-2][n-1] * matrix[n-1][n-2];
            default:
                {
                    for (size_t j = 0; j < n; ++j)
                    {
                        std::vector<std::vector<int>> minor((n - 1), std::vector<int>((n - 1)));
                        for (size_t row = 1; row < n; ++row)     // заполняем минор
                        {
                            size_t k = 0;                        // новый индекс для минорной матрицы
                            for (size_t col = 0; col < n; ++col)
                            {

                                if (col == j) continue;         // пропускаем j-ый столбец
                                minor[row - 1][k] = matrix[row][col];
                                ++k;
                            }
                        }
                        result += pow(-1, 2 + j) * matrix[0][j] * determinant(minor, n - 1);
                    }
                    return result;
                }
        }
    };

};

/* 3. Реализовать собственный класс итератора, с помощью которого можно будет проитерироваться
 * по диапазону целых чисел в цикле for-range-based.
 */

class Iterator
{
private:
    std::vector<int> m_vector;
    int* m_begin;
    int* m_end;
public:
    Iterator(std::vector<int>& _vector) : m_vector(_vector)
    {
        m_begin = &m_vector[0];
        m_end = &m_vector[m_vector.size()];
    };

    ~Iterator()
    {
        m_vector.resize(0);
    };

    int* begin() const
    {
        return m_begin;
    }

    int* end() const
    {
        return m_end;
    }

    bool operator !=(int* rhs)
    {
        return m_begin != rhs;
    };

    int* operator ++()
    {
        return m_begin + 1;
    };

    int operator *()
    {
        return *m_begin;
    };

};

int main()
{
    std::cout << "----------- 1 Add Average ----------" << std::endl;
    std::list<float> l = {0.25, 2.54, 6.87};
    addAverage(l);
    for (auto i : l)
    {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    std::cout << "----------- 2 Matrix ----------" << std::endl;
    std::vector<std::vector<int>> m = { {1, 2, 3},
                                        {4, 3, 6},
                                        {7, 8, 9}};//d=24
    Matrix matrix(m);
    matrix.printMatrix();
    std::cout << "Determinant = " << matrix.determinant(m, 3) << std::endl;

    std::cout << "----------- 3 Iterator ----------" << std::endl;
    std::vector<int> v {10, 20, 30, 40, 50};
    Iterator it(v);
    for (int element : it)
    {
        std::cout << element << ' ';
    }
    std::cout << std::endl;
    return 0;
}

