#include <iostream>
#include <cstdint>
#include <cassert>

using namespace std;

class Power
{
private:
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
    std::uint8_t m_red, m_green, m_blue, m_alpha;

public:

    RGBA(std::uint8_t _red = 0, std::uint8_t _green = 0,
         std::uint8_t _blue = 0, std::uint8_t _alpha = 255)
        : m_red(_red), m_green(_green), m_blue(_blue), m_alpha(_alpha)
    {
       
    }

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

    Stack(int _length)  //конструктор
    {
        assert(("Length can't possibly be negative!", _length >= 0));
        
        m_stack = new int[m_length];
        m_length = _length;
    }
    
    ~Stack()            //деструктор
    {
        //Динамически удаляем массив, который выделили ранее
        delete[] m_stack;
    }
    
    void reset()
    {
        for (int i = 0; i < m_length; i++)
        {
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
        else return false;
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
            m_stack[m_length] = 0;
            m_length--;
        }
    }
    
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
