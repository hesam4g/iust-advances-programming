#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QTextEdit>

#include <QtGui/QMainWindow>

class MainWindow : public QWidget
{
    Q_OBJECT

    QTextEdit *t1;
    QTextEdit *t2;
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void khoruj();
};

#endif // MAINWINDOW_H
