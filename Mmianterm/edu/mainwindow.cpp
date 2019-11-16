#include <QTextBlock>
#include "mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *box = new QVBoxLayout(this);
    QHBoxLayout *h1 = new QHBoxLayout();

    QTextEdit *text=new QTextEdit;
    QHBoxLayout *h = new QHBoxLayout();

    box->addLayout(h);
    _text=text;
    _text->setText(QString::fromUtf8("?? ??? ???.\n."));

    QPushButton * profile =new QPushButton(QString::fromUtf8("??????"));
    QPushButton * akhz=new QPushButton(QString::fromUtf8(" ??? ???? "));
    h1->addWidget(profile);
    h1->addWidget(akhz);
    box->addLayout(h1);

    QHBoxLayout *h2 = new QHBoxLayout();

    QPushButton * lessons =new QPushButton(QString::fromUtf8(" ???? "));
    QPushButton * marks =new QPushButton(QString::fromUtf8(" ????? "));
    h2->addWidget(lessons);
    h2->addWidget(marks);
    box->addLayout(h2);

    QHBoxLayout *h3 = new QHBoxLayout();

    QPushButton * exit =new QPushButton(QString::fromUtf8(" ???? "));
    h3->addWidget(exit);
    box->addLayout(h3);

    QHBoxLayout *h4= new QHBoxLayout();

    h4->addWidget(text);
    box->addLayout(h4);

    setLayout(box);
    connect(profile, SIGNAL(clicked()),this,SLOT(profileClick()));
    connect(lessons, SIGNAL(clicked()),this,SLOT(lessonsClick()));
    connect(marks, SIGNAL(clicked()),this,SLOT(marksClick()));
    connect(exit, SIGNAL(clicked()),this,SLOT(exitClick()));
}

void MainWindow::profileClick()
    {

    _text->setText(QString::fromUtf8("???? ????"));
    }

void MainWindow::lessonsClick()
    {

    _text->setText(QString::fromUtf8("????"));
    }
void MainWindow::marksClick()
    {

    _text->setText(QString::fromUtf8("?????"));
    }
void MainWindow::exitClick()
    {

    exit(0);
    }

MainWindow::~MainWindow()
{

}
