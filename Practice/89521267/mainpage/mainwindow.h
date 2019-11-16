#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <qlineedit.h>
#include <qlabel.h>
#include <QWidget>
#include <qradiobutton.h>
#include <QHBoxLayout>
#include <qscrollarea.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void allpasenger();
    void allpasenger1();
    void helpallpasenger1();
    void pasengerserch();
    void all();
    void save();
    void information();
    void cancelaction();
    void buy();
    void newfly();
    void edit();
    void info();
    void cancel();
    void edit1();
    void edit2();
    void buyticket();
    void dateserch();
    void helpdateserch();
    void dateserch1();
    void cityserch();
    void helpcityserch();
    void cityserch1();
    void pasengern();
    void helppasengern();
    void pasengern1();
    void pasengerj();
    void helppasengerj();
    void pasengerj1();
    void pasengerinformation();
    void pasengerinformation2();
    void pasengerinformation1();

public:
    QLineEdit *txt1;
    QLineEdit *txt2;
    QLineEdit *txt3;
    QLineEdit *txt4;
    QLineEdit *txt5;
    QLineEdit *txt6;
    QLineEdit *txt7;
    QLineEdit *txt12;
    QLineEdit *txt13;
    QLineEdit *txt14;
    QLineEdit *txt15;
    QLineEdit *txt16;
    QLineEdit *txt17;
    QLineEdit *txt;
    QLabel *lab;
    QLineEdit *txtdate;
    QLabel *labdate;
    QLineEdit *txtedit;
    QWidget *w1;
    QWidget *w2;
    QWidget *w3;
    QWidget *w4;
    QWidget *w5;
    QWidget *w6;
    QWidget *w7;
    QWidget *wnew;
    QWidget *wbuy;
    QLineEdit *txt21;
    QLineEdit *txtk;
    QLineEdit *txt22;
    QLineEdit *txt23;
    QLineEdit *txt24;
    QLineEdit *txt25;
    QLineEdit *txt26;
    QLineEdit *txt27;
    QLineEdit *txtcancel;
    QRadioButton * radi;
    QScrollArea *sco;
    QHBoxLayout *vb;
    QScrollArea *sco1;
    QHBoxLayout *vb1;
    QScrollArea *sco1inf;
    QHBoxLayout *vbinf;
    QLineEdit *txtcity;
    QLineEdit *txtcity1;
    QLineEdit *txtserchn;
    QLineEdit *txtserchj;
    QLineEdit *txtserchn1;
    QLineEdit *txtinf;
    QLabel *labinf;
    QLabel *labn;
    QLabel *labserchj;
    QLabel *labserchn;
    QLabel *labcity;
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H






































