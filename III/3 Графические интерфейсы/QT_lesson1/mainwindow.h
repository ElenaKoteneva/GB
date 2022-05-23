#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "quadratic.h"
#include "triangle.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonCalculate_clicked();

    void on_pushButtonCalculateTriangle_clicked();

    void on_pushButtonCalculateRoots_clicked();

    void on_pushButtonAdd_clicked();

    void on_pushButtonReplace_clicked();

    void on_pushButtonInsertHTML_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
