#include "mainwindow.h"
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QString>
#include<QLineEdit>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *v1 = new QVBoxLayout(this);

    t = new QLineEdit();
    t->resize(100,200);
    QLineEdit *memory = new QLineEdit();
    QHBoxLayout *h1 = new QHBoxLayout();
    QHBoxLayout *h2 = new QHBoxLayout();
    QHBoxLayout *h3 = new QHBoxLayout();
    QHBoxLayout *h4 = new QHBoxLayout();
    QHBoxLayout *h5 = new QHBoxLayout();
    QHBoxLayout *h6 = new QHBoxLayout();
    QHBoxLayout *h7 = new QHBoxLayout();

    QPushButton *p1  = new QPushButton("1");
    QPushButton *p2  = new QPushButton("2");
    QPushButton *p3  = new QPushButton("3");
    QPushButton *p4  = new QPushButton("4");
    QPushButton *p5  = new QPushButton("5");
    QPushButton *p6  = new QPushButton("6");
    QPushButton *p7  = new QPushButton("7");
    QPushButton *p8  = new QPushButton("8");
    QPushButton *p9  = new QPushButton("9");
    QPushButton *p10 = new QPushButton(".");
    QPushButton *p11 = new QPushButton("0");
    QPushButton *p12 = new QPushButton("=");
    QPushButton *p13 = new QPushButton("+");
    QPushButton *p14 = new QPushButton("Exit");

    v1->addWidget(t);
    v1->addLayout(h1);
    v1->addLayout(h2);
    v1->addLayout(h3);
    v1->addLayout(h4);
    v1->addLayout(h5);
    v1->addLayout(h6);
    v1->addLayout(h7);

    h1->addWidget(p1);
    h1->addWidget(p2);
    h1->addWidget(p3);
    h2->addWidget(p4);
    h2->addWidget(p5);
    h2->addWidget(p6);
    h3->addWidget(p7);
    h3->addWidget(p8);
    h3->addWidget(p9);
    h4->addWidget(p10);
    h4->addWidget(p11);
    h4->addWidget(p12);
    h5->addWidget(p13);
    h6->addWidget(p14);
    h7->addWidget(memory);

    connect(p1,SIGNAL(clicked()),this,SLOT(print1()));
    connect(p2,SIGNAL(clicked()),this,SLOT(print2()));
    connect(p3,SIGNAL(clicked()),this,SLOT(print3()));
    connect(p4,SIGNAL(clicked()),this,SLOT(print4()));
    connect(p5,SIGNAL(clicked()),this,SLOT(print5()));
    connect(p6,SIGNAL(clicked()),this,SLOT(print6()));
    connect(p7,SIGNAL(clicked()),this,SLOT(print7()));
    connect(p8,SIGNAL(clicked()),this,SLOT(print8()));
    connect(p9,SIGNAL(clicked()),this,SLOT(print9()));
    connect(p10,SIGNAL(clicked()),this,SLOT(printDOT()));
    connect(p11,SIGNAL(clicked()),this,SLOT(print0()));
    connect(p13,SIGNAL(clicked()),this,SLOT(addition()))
    connect(p14,SIGNAL(clicked()),this,SLOT(khoruj()));

}

void MainWindow::khoruj(){
    exit(0);
}

void MainWindow::print1(){
    QString a = t->text();
    a = a+"1";
    t->setText(a);
}

void MainWindow::print2(){
    QString a = t->text();
    a = a+"2";
    t->setText(a);
}

void MainWindow::print3(){
    QString a = t->text();
    a = a+"3";
    t->setText(a);
}

void MainWindow::print4(){
    QString a = t->text();
    a = a+"4";
    t->setText(a);
}

void MainWindow::print5(){
    QString a = t->text();
    a = a+"5";
    t->setText(a);
}

void MainWindow::print6(){
    QString a = t->text();
    a = a+"6";
    t->setText(a);
}

void MainWindow::print7(){
    QString a = t->text();
    a = a+"7";
    t->setText(a);
}

void MainWindow::print8(){
    QString a = t->text();
    a = a+"8";
    t->setText(a);
}

void MainWindow::print9(){
    QString a = t->text();
    a = a+"9";
    t->setText(a);
}

void MainWindow::print0(){
    QString a = t->text();
    a = a+"0";
    t->setText(a);
}

void MainWindow::printDOT(){
    QString a = t->text();
    a = a+".";
    t->setText(a);
}

void MainWindow::addition(){

}

MainWindow::~MainWindow()
{

}
