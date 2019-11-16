#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <qstring.h>
#include<QLineEdit>
#include <QtGui/QMainWindow>
#include <string>
using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void coding();
    void decoding();

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int strtoint(char b,int k);
    char inttostr(long int a);
    QLineEdit *code;
    QLineEdit *decode;
};

#endif // MAINWINDOW_H




