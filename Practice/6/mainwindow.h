#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QGraphicsView *view;
    QGraphicsScene *scene;
};

#endif // MAINWINDOW_H
