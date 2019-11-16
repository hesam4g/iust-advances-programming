#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);
    setCentralWidget(view);
    QGraphicsLineItem *myline1 = scene->addLine(200,100,100,200);
    QGraphicsLineItem *myline = scene->addLine(200,110,110,200);
    myline->moveBy(100,0);
    myline1->rotate(30);
}

MainWindow::~MainWindow()
{

}
