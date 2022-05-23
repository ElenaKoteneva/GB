#ifndef QUADRATIC_H
#define QUADRATIC_H


class Quadratic
{
private:
    //int m_a, m_b, m_c;
    double m_D, m_x1, m_x2;

public:
    Quadratic() {}
/*
    Quadratic(int _a, int _b, int _c)
        : m_a(_a), m_b(_b), m_c(_c) {}
*/
    ~Quadratic() {}

    int calculate(int a, int b, int c);

    double getRoot1() const;

    double getRoot2() const;
};

#endif // QUADRATIC_H
