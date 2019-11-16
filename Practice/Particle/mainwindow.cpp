#include "mainwindow.h"
#include <QGraphicsLineItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    scene = new AScene();
    view = new QGraphicsView(scene);
    centerparticle = new AABigParticle(scene);
    scene->addItem(centerparticle);
    setCentralWidget(view);
}

MainWindow::~MainWindow()
{

}
