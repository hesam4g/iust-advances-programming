#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QLineEdit>
#include <QtGui/QMainWindow>
#include<string>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QLineEdit *text1;
    QLineEdit *text2;
    char inttostr(long int a);
    int strtoint(char b,int k);

private slots:
    void code();
    void decode();
    void quit();
};

#endif // MAINWINDOW_H
