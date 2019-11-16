#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QTextEdit>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    QTextEdit *_text ;
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void profileClick();
    void lessonsClick();
    void marksClick();
    void exitClick();
};

#endif // MAINWINDOW_H
