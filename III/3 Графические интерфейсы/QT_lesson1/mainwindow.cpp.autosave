#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtMath>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonCalculateRoots_clicked()
{
    QString root1, root2;
    int result;
    Quadratic quadratic;

    QString a_str = ui->lineEditRatioA->text();
    QString b_str = ui->lineEditRatioB->text();
    QString c_str = ui->lineEditRatioC->text();
    qreal a = a_str.toDouble();
    qreal b = b_str.toDouble();
    qreal c = c_str.toDouble();

    result = quadratic.calculate(a, b, c);

    if (result < 0)
    {
        ui->lineEditResultRoots->setText("Нет действ. корней.");
    }
    else if (result > 0)
    {
        root1.setNum(quadratic.getRoot1());
        root2.setNum(quadratic.getRoot2());
        ui->lineEditResultRoots->setText("x1 =" + root1 + ", x2 = " + root2);
    }
    else
    {
        root1.setNum(quadratic.getRoot1());
        ui->lineEditResultRoots->setText("x1 =" + root1);
    }
}

void MainWindow::on_pushButtonCalculateTriangle_clicked()
{
    QString side_str;
    qreal side;

    QString side1_str = ui->lineEditSide1->text();
    QString side2_str = ui->lineEditSide2->text();
    QString angle_str = ui->lineEditAngle->text();
    qreal side1 = side1_str.toDouble();
    qreal side2 = side2_str.toDouble();
    qreal angle = angle_str.toDouble();

    if (ui->radioButtonDegrees->isChecked())
    {
        side = qSqrt(qPow(side1, 2) + qPow(side2, 2) - 2 * side1 * side2 * qCos(angle * M_PI / 180));
        side_str.setNum(side);
        ui->lineEditResultTriangle->setText(side_str);
    }

    if (ui->radioButtonRadians->isChecked())
    {
        side = qSqrt(qPow(side1, 2) + qPow(side2, 2) - 2 * side1 * side2 * qCos(angle));
        side_str.setNum(side);
        ui->lineEditResultTriangle->setText(side_str);
    }
}


void MainWindow::on_pushButtonAdd_clicked()
{
    QString text1, text2;
    text1 = ui->plainTextEdit_1->toPlainText();
    text2 = ui->plainTextEdit_2->toPlainText();

    ui->plainTextEdit_1->insertPlainText(text2);
    ui->plainTextEdit_2->insertPlainText(text1);
}

void MainWindow::on_pushButtonReplace_clicked()
{
    QString text1, text2;
    text1 = ui->plainTextEdit_1->toPlainText();
    text2 = ui->plainTextEdit_2->toPlainText();

    ui->plainTextEdit_1->setPlainText(text2);
    ui->plainTextEdit_2->setPlainText(text1);
}

void MainWindow::on_pushButtonInsertHTML_clicked()
{
    ui->plainTextEdit_1->appendHtml("<font color='red'>Hello</font>");
}
