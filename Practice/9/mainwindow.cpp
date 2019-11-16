#include "mainwindow.h"
#include<QPushButton>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QWidget>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *e = new QWidget(this);
    QVBoxLayout *a = new QVBoxLayout(this);
    QPushButton *s = new QPushButton("a");
    s->resize(90,40);
    s->setText("salam");
    e->resize(200,200);
    QLineEdit *d = new QLineEdit(0);
    a->addWidget(s);
    a->addWidget(d);
    e->setLayout(a);

}

MainWindow::~MainWindow()
{

}
