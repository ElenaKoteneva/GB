/*
Возможные типы комментариев:
    Стиль - несущественные замечания, помогающие улучшить визуальную составляющую кода
    УЗ - условия задания - нарушено условие задания
    Логика - нарушена логика программы и/или согласованность ее элеменов
    Хорошо - особая отметка хорошего решения
*/

#include <iostream>
#include <cstdint>
#include <cassert>

using namespace std;

class Power
{
private:

    // Стиль: m_first и m_second - неинформативные названия переменных.
    //        Намного лучше использовать: m_base и m_exponent/m_power
    float m_first;
    float m_second;

public:

    Power(float _first, float _second)
    {
        set(_first, _second);
        std::cout << m_first << "^" << m_second << "=";
    }

    void set(float _first, float _second)
    {
        m_first = _first;
        m_second = _second;
    }

    // Логика: лучше использовать std::pow()
    // Стиль: метод, не изменяющий состояние объекта, должен быть const
    void calculate()
    {
        int i = 1;
        float m_res = m_first;

        while (i < m_second)
        {
            m_res *= m_first;
            i++;
        }
        std::cout << m_res << "\n";
    }
};

class RGBA
{
    // Хорошо: инициализация однотипных объектов в одной строке
    std::uint8_t m_red, m_green, m_blue, m_alpha;

public:

    RGBA(std::uint8_t _red = 0, std::uint8_t _green = 0,
         std::uint8_t _blue = 0, std::uint8_t _alpha = 255)
         : m_red(_red), m_green(_green), m_blue(_blue), m_alpha(_alpha)
    {

    }

    // Стиль: метод, не изменяющий состояние объекта, должен быть const
    void print()
    {
        std::cout << (int)m_red << " " << (int)m_green << " " << (int)m_blue << " "
                  << (int)m_alpha << "\n";
    }
};

class Stack
{
    int m_length;
    int* m_stack;

public:

    // Стиль: комментарий "конструкто" не нужен, это и так очевидно :)
    Stack(int _length) //конструктор
    {
        // Логика: вы можете использовать size_t (либо иной беззнаковый) тип
        //         для определения длины. Тогда этот ассерт будет не нужен.
        assert(("Length can't possibly be negative!", _length >= 0));

        // Логика: значение m_length в данный момент НЕ ИНИЦИАЛИЗИРОВАНО!
        //         В лучшем случае там будет 0 и вы создадите массив длины 0!
        //         Но даже значение 0 НЕ ГАРАНТИРОВАНО, там может быть что угодно :)
        //         Полагаю, вы хотели написать new int[10], но тогда передавать значение _length
        //         в конструктор не нужно, да и название "length" немного сбивает с толку.
        m_stack = new int[m_length];
        m_length = _length;
    }

    // Стиль: комментарий "деструктор" не нужен, это и так очевидно :)
    ~Stack() //деструктор
    {
        //Динамически удаляем массив, который выделили ранее
        delete[] m_stack;
    }

    void reset()
    {
        for (int i = 0; i < m_length; i++)
        {
            // Хорошо: работа с арифметикой указателей!
            *(m_stack + i) = 0;
            std::cout << *(m_stack + i) << " ";
        }
        m_length = 0;
    }

    bool push(int _a)
    {
        //добавлять значение в стек. push() должен возвращать значение false,
        //если массив уже заполнен, и true в противном случае
        if (m_length < 10)
        {
            m_stack[m_length] = _a;
            m_length++;
            return true;
        }
        else return false; // Стиль: лучше return false перенести на новую строчку
    }

    int pop()
    {
        //для вытягивания и возврата значения из стека.
        //Если в стеке нет значений, то должно выводиться предупреждение
        if (!m_length)
        {
            std::cout << "Stack is empty\n";
        }
        else
        {
            // Логика: если у вас будет 10 элементов в массиве, то m_length = 10,
            //         а значит вы попробуете присвоить значение m_stack[10], но индексы
            //         массива у вас от 0 до 9!
            m_stack[m_length] = 0;
            m_length--;
        }
        // Логика: метод задекларирован как возвращающий int, но вы забыли вернуть значение
        //         (в методе нет return)
    }

    // Стиль: метод, не изменяющий состояние объекта, должен быть const
    void print()
    {
        //выводить все значения стека
        std::cout << "(";
        for (int i = 0; i < m_length; i++)
        {
            std::cout << m_stack[i];
        }
        std::cout << ")\n";
    }
};

int main()
{
    //-----1-----

    Power p(2, 3);
    p.calculate();

    //-----2-----

    RGBA rgba(2,3,20,5);
    rgba.print();

    //-----3-----

    Stack st(0);
    st.push(3);
    st.push(7);
    st.push(5);
    st.print();

    st.pop();
    st.print();

    st.pop();
    st.pop();
    st.print();

    return 0;
}