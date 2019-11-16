#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    void buy();
    void cancel();
    void seeAllPass();
    void seeAllFlight();
    void seeFlightInfo();
    void makeFlight();
    void editFlight();
    void searchPass();
    void buyATicket();
    void doCancel();
    void seeAllPass1();
    void save();
    void editWindow();
    void saveEdit();
    void information();
    void passWithNumber();
    void passWithName();

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
