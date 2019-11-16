#include "ascene.h"
#include <QGraphicsSceneMouseEvent>
#include "particle.h"

AScene::AScene(QObject *parent) :
    QGraphicsScene(parent)
{
}

void AScene::mouseReleaseEvent ( QGraphicsSceneMouseEvent * mouseEvent )   {
    double x = mouseEvent->scenePos().x();
    double y = mouseEvent->scenePos().y();

    particle* p = new particle();
    p->setLine(x-10,y-10,x+10,y+10);

    addItem(p);
}
