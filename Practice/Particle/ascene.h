#ifndef ASCENE_H
#define ASCENE_H

#include <QGraphicsScene>

class AScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit AScene(QObject *parent = 0);

signals:

public slots:

protected:
  void mouseReleaseEvent ( QGraphicsSceneMouseEvent * mouseEvent )   ;

};

#endif // ASCENE_H
