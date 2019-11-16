#ifndef AABIGPARTICLE_H
#define AABIGPARTICLE_H

#include <QGraphicsEllipseItem>

class AABigParticle :public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    explicit AABigParticle(QObject *parent = 0);

signals:

public slots:

};

#endif // AABIGPARTICLE_H
