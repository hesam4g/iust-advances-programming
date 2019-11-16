#include "mainwindow.h"
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QPushButton>
#include<Qstring>
#include<QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *v  = new QVBoxLayout(this);
    QHBoxLayout *h1 = new QHBoxLayout();

    t1 = new QTextEdit;
    t2 = new QTextEdit;

    QPushButton *p1 = new QPushButton("convert");
    QPushButton *p2 = new QPushButton("Quit");

    v->addWidget(t1);
    v->addLayout(h1);
    v->addWidget(t2);
    h1->addWidget(p1);
    h1->addWidget(p2);

    connect(p2,SIGNAL(clicked()),this,SLOT(khoruj()));
}

void MainWindow::khoruj(){
    exit(0);
}

MainWindow::~MainWindow()
{

}
