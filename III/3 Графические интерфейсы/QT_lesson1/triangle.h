#ifndef TRIANGLE_H
#define TRIANGLE_H


class Triangle
{
private:
    //int m_side1, m_side2, m_angle;
    double m_side;

public:
    Triangle() {}
/*
    Triangle(int _side1, int _side2, int _angle)
        : m_side1(_side1), m_side2(_side2), m_angle(_angle) {}
*/
    ~Triangle() {}

    double calculate(int a, int b, int c);

    double getSide() const;

};

#endif // TRIANGLE_H
