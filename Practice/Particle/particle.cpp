#include "particle.h"

particle::particle(QObject *parent) :
    QGraphicsLineItem()
{
    t = new QTimer(this);
    connect(t,SIGNAL(timeout()),this,SLOT(step()));
    t->start(10);
}

void particle::step(){
    moveBy((qrand()*10)%3-1,(qrand()*10)%3-1);
}
