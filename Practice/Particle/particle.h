#ifndef PARTICLE_H
#define PARTICLE_H

#include <QGraphicsLineItem>
#include <QTimer>

class particle : public QObject , public QGraphicsLineItem
{
    Q_OBJECT
public:
    particle(QObject *parent = 0);
private slots:
    void step();
private:
    QTimer* t;
};

#endif // PARTICLE_H
