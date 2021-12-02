#include <iostream>
#include <cstdint>

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
    const int m_red, m_green, m_blue, m_alpha;

public:

    RGBA(int _red = 0, int _green = 0,
         int _blue = 0, int _alpha = 255)
        : m_red(_red), m_green(_green), m_blue(_blue), m_alpha(_alpha)
    {
       
    }

    void print()
    {
        std::cout << m_red << " " << m_green << " " << m_blue << " "
                  << m_alpha << "\n";
    }
};

class Stack
{
    int m_length = 0;
    int m_stack[10] = {};
    
public:

    Stack()
    {
        std::cout << "Stack ready\n";
    }
    
    void reset()
    {
       //сбрасывать длину и все значения элементов на 0;
        m_length = 0;
        for (int i = 0; i < 10; i++)
        {
            m_stack[i] = 0;
        }
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

    RGBA rgba(2,4,5,0);
    rgba.print();
    
    //-----3-----
    
    Stack st;
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
