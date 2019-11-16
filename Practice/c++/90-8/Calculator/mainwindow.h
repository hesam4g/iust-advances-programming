#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QLineEdit>
#include <QPushButton>

#include "abutton.h"

class ACalculator : public QWidget
{
    Q_OBJECT

public:
    int acc;
    bool isTyping;

    QLineEdit* display;
    ANumberButton* digits[10];

    QPushButton *add, *minus, *equal;

    ACalculator(QWidget *parent = 0);
    ~ACalculator();
public slots:
    void addSlot();
    void minusSlot();
    void equalSlot();
};

#endif // MAINWINDOW_H
