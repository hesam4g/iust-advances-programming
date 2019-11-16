#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QLineEdit>
#include <QtGui/QMainWindow>
#include<string>
using namespace std;

class MainWindow : public QWidget
{
    Q_OBJECT

    QLineEdit *t;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void khoruj();
    void print1();
    void print2();
    void print3();
    void print4();
    void print5();
    void print6();
    void print7();
    void print8();
    void print9();
    void print0();
    void printDOT();
    void addition();

};

#endif // MAINWINDOW_H
