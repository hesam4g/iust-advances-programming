#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QGraphicsView>
#include "ascene.h"
#include"aabigparticle.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QGraphicsView* view;
    AScene* scene;
    AABigParticle *centerparticle;
};

#endif // MAINWINDOW_H
