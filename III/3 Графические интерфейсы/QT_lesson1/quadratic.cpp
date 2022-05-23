#include "quadratic.h"

#include <QtMath>

int Quadratic::calculate(int a, int b, int c)
{
    m_D = qPow(b, 2) - 4 * a * c;

    if (a != 0)
    {
        if (m_D == 0)
        {
            m_x1 = -(b / 2 * a);
            return 0;
        }
        else if (m_D > 0)
        {
            m_x1 = (-b + qSqrt(m_D)) / 2 * a;
            m_x2 = (-b - qSqrt(m_D)) / 2 * a;
            return 1;
        }
        else return -1;
    }
    else
    {
        m_x1 = -(c / b);
        return 0;
    }

}

double Quadratic::getRoot1() const
{
    return m_x1;
}

double Quadratic::getRoot2() const
{
    return m_x2;
}
