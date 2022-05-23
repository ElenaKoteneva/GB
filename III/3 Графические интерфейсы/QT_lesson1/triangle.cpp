#include "triangle.h"
#include "ui_mainwindow.h"

#include <QtMath>
#include <QDebug>

double Triangle::calculate(int side1, int side2, int angle)
{
    if (ui->radioButtonDegrees->isChecked())
    {

    }
    m_side = qSqrt(qPow(side1, 2) + qPow(side2, 2) - 2 * side1 * side2 * qCos(angle * M_PI / 180));
    return m_side;
}
/*
double Triangle::getSide() const
{
    return m_side;
}
*/
