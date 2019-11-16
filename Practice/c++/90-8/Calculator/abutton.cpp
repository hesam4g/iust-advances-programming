#include "abutton.h"
#include "mainwindow.h"

ANumberButton::ANumberButton(ACalculator* d,QWidget *parent) :
    QPushButton(parent)
{
    screen = d;
}


void ANumberButton::mouseReleaseEvent ( QMouseEvent * e )
{
    if(!screen->isTyping)
        screen->display->clear();
   screen->isTyping = true;
   screen->display->setText( screen->display->text() + text() );
}
