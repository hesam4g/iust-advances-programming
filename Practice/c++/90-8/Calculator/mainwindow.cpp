#include "mainwindow.h"
#include <QGridLayout>

ACalculator::ACalculator(QWidget *parent)
    : QWidget(parent)
{
    acc = 0;
    isTyping = false;

    QGridLayout* lay = new QGridLayout();

    display = new QLineEdit();
    //display->setAlignment(Qt::AlignRight);
    lay->addWidget(display,0,0,1,4);

    for(int i=0;i<10;i++){
        digits[i] = new ANumberButton(this);
        digits[i]->setText(QString::number(i));
    }

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            lay->addWidget(digits[i*3+j+1],i+1,j);
    lay->addWidget(digits[0],4,1);

    add = new  QPushButton("+");
    connect(add,SIGNAL(clicked()),this,SLOT(addSlot()));

    minus = new QPushButton("-");
    connect(minus,SIGNAL(clicked()),this,SLOT(minusSlot()));

    equal = new QPushButton("=");
    connect(equal,SIGNAL(clicked()),this,SLOT(equalSlot()));


    lay->addWidget(add,1,3);
    lay->addWidget(minus,2,3);
    lay->addWidget(equal,3,3);

    setLayout(lay);

}


void ACalculator::addSlot(){
    isTyping = false;

    int lacc = acc;
    acc = display->text().toInt();
    display->setText(QString::number(lacc + acc));
}

void ACalculator::minusSlot(){
    isTyping = false;

}

void ACalculator::equalSlot(){
    isTyping = false;

}

ACalculator::~ACalculator()
{

}
