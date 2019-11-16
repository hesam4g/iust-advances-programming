#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include<QLabel>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QLineEdit>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    QLineEdit *l;
    QLabel *label;
    QHBoxLayout *h1,*h2;
};

#endif // WIDGET_H
