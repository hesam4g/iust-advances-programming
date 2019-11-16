#ifndef ABUTTON_H
#define ABUTTON_H

#include <QPushButton>


class ACalculator;
class ANumberButton : public QPushButton
{
    Q_OBJECT
public:
    ACalculator* screen;
    explicit ANumberButton(ACalculator* d,QWidget *parent = 0);

protected:
    void mouseReleaseEvent ( QMouseEvent * e );
signals:

public slots:

};

#endif // ABUTTON_H
