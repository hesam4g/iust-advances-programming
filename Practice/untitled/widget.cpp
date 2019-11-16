#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    h1 = new QHBoxLayout(this);
    h2 = new QHBoxLayout(this);
    h1->addWidget(l);
    h2->addWidget(label);
}

Widget::~Widget()
{

}
