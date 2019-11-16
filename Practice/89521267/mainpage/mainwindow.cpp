#include "mainwindow.h"
#include <qwidget.h>
#include <qpushbutton.h>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <qlineedit.h>
#include <qfile.h>
#include <qstring>
#include <fstream>
#include <string>
#include <QCoreApplication>
#include <QTextStream>
#include <qradiobutton.h>
#include <QScrollBar>
#include <QScrollArea>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

QPushButton *info =new QPushButton("Fight information");
QPushButton *buy =new QPushButton("Buy ticket");
QPushButton *cancel =new QPushButton("Cancel ticket");
QPushButton *newfly =new QPushButton("Make new fight");
QPushButton *edit =new QPushButton("Edit fight information");
QPushButton *all =new QPushButton("See All fight");
QPushButton *exit =new QPushButton("Exit");
QPushButton *pasengerserch =new QPushButton("Search");
QPushButton *allpasenger =new QPushButton("See all pasenger");
QPushButton *pasengerinfo =new QPushButton("Pasenger information");
QWidget *w=new QWidget(this);
w->resize(400,200);
w->setWindowTitle("Main page");
QHBoxLayout *v1=new QHBoxLayout();
v1->addWidget(info);
v1->addWidget(buy);
v1->addWidget(cancel);
QHBoxLayout *v2=new QHBoxLayout();
v2->addWidget(newfly);
v2->addWidget(edit);
v2->addWidget(all);
QHBoxLayout *v3=new QHBoxLayout();
v3->addWidget(allpasenger);
v3->addWidget(pasengerserch);
v3->addWidget(pasengerinfo);
QHBoxLayout *v4=new QHBoxLayout();
v4->addWidget(exit);
QVBoxLayout *h1=new QVBoxLayout(this);
h1->addLayout(v1);
h1->addLayout(v2);
h1->addLayout(v3);
h1->addLayout(v4);
w->setLayout(h1);
connect(buy,SIGNAL(clicked()),this,SLOT(buy()));
connect(all,SIGNAL(clicked()),this,SLOT(all()));
connect(exit,SIGNAL(clicked()),this,SLOT(close()));
connect(newfly,SIGNAL(clicked()),this,SLOT(newfly()));
connect(cancel,SIGNAL(clicked()),this,SLOT(cancel()));
connect(info,SIGNAL(clicked()),this,SLOT(info()));
connect(edit,SIGNAL(clicked()),this,SLOT(edit()));
connect(allpasenger,SIGNAL(clicked()),this,SLOT(allpasenger()));
connect(pasengerserch,SIGNAL(clicked()),this,SLOT(pasengerserch()));
connect(pasengerinfo,SIGNAL(clicked()),this,SLOT(pasengerinformation()));
}
void MainWindow::pasengerinformation()
{
    QPushButton *click=new QPushButton("Information with pasenger number");
    QPushButton *click1=new QPushButton("Back");
    QPushButton *click2=new QPushButton("Information with pasenger name");
    QLineEdit *text=new QLineEdit();
    QLabel *lable=new QLabel();
    QLabel *lable1=new QLabel("Pleas enter pasenger number or pasenger name");
    QHBoxLayout *l=new QHBoxLayout();
    QHBoxLayout *l1=new QHBoxLayout();
    QHBoxLayout *l2=new QHBoxLayout();
    QHBoxLayout *l3=new QHBoxLayout();
    QHBoxLayout *l4=new QHBoxLayout();
    QScrollArea *scroll =new QScrollArea();

    l2->addWidget(click2);
    l3->addWidget(click);
    l4->addWidget(click1);
    l->addWidget(text);
    l->addWidget(lable1);
    QWidget *w=new QWidget();
    w->resize(400,200);
    QVBoxLayout *h=new QVBoxLayout();
    h->addLayout(l);
    h->addLayout(l2);
    h->addLayout(l3);
    h->addLayout(l4);
    h->addLayout(l1);
    w->setLayout(h);
    labinf=lable;
    txtinf=text;
    sco1inf=scroll;
    vbinf=l1;
    w->setWindowTitle("Pasenger infomation");
    w->show();
    w4=w;
    connect(click1,SIGNAL(clicked()),w,SLOT(close()));
    connect(click,SIGNAL(clicked()),this,SLOT(pasengerinformation1()));
    connect(click2,SIGNAL(clicked()),this,SLOT(pasengerinformation2()));

}
void MainWindow::pasengerinformation1()
{
    QFile file1("allpasengernumber.txt");
    file1.open(QIODevice::ReadOnly|QIODevice::Text);
    QString d=file1.readAll();
    if(d.indexOf((" "+txtinf->text()+" "))!=-1)
    {
    QString adress,d;
    adress=txtinf->text();
    adress=adress+".txt";
    QFile file(adress);
    file.open(QIODevice::ReadWrite| QIODevice::Text);
    d=file.readAll();
    labinf->setText(d);
    sco1inf->setWidget(labinf);
    vbinf->addWidget(sco1inf);
    w4->resize(400,400);
    file.close();
}
    else
    {
        QWidget *w5=new QWidget();
        QPushButton *Ok2=new QPushButton("Ok");
        QLabel *lab2=new QLabel("Pasenger number is wrong");
        QVBoxLayout *v2=new QVBoxLayout();
        w5->resize(400,75);
        v2->addWidget(lab2);
        v2->addWidget(Ok2);
        w5->setLayout(v2);
        w5->show();
        connect(Ok2,SIGNAL(clicked()),w5,SLOT(close()));
    }
}
void MainWindow::pasengerinformation2()
{
    QFile file1("allpasenger.txt");
    file1.open(QIODevice::ReadOnly|QIODevice::Text);
    bool r=true;
    int count=0;
    QString d=file1.readAll(),a,c="";
   QStringList k,m;
   k=d.split("\n");
   for(int i=0;i<k.length();i++)
   {
       a=k[i];
       a.replace("   "," ");
       a.replace("  "," ");
       a.replace("    "," ");
       m=a.split(" ");
       a.replace((m[0]+" "),"");
       if(a==(txtinf->text()))
       {
           r=false;
           QFile file(m[0]+".txt");
           file.open(QIODevice::ReadWrite| QIODevice::Text);
           d=file.readAll();
           c=c+d+"\n\n\n";
           file.close();
       }
   }

   if(!r){
   labinf->setText(c);
    sco1inf->setWidget(labinf);
    vbinf->addWidget(sco1inf);
    w4->resize(400,400);
}
    else
    {
        QWidget *w5=new QWidget();
        QPushButton *Ok2=new QPushButton("Ok");
        QLabel *lab2=new QLabel("Pasenger name is't found");
        QVBoxLayout *v2=new QVBoxLayout();
        w5->resize(400,75);
        v2->addWidget(lab2);
        v2->addWidget(Ok2);
        w5->setLayout(v2);
        w5->show();
        connect(Ok2,SIGNAL(clicked()),w5,SLOT(close()));
    }
    }
void MainWindow::allpasenger()
{
    QPushButton *click=new QPushButton("See information");
    QPushButton *click1=new QPushButton("Back");
    QPushButton *click2=new QPushButton("Help");
    QLineEdit *text=new QLineEdit();
    QLabel *lable=new QLabel();
    QLabel *lable1=new QLabel("Pleas enter fight number");
    QHBoxLayout *l=new QHBoxLayout();
    QHBoxLayout *l1=new QHBoxLayout();
    QScrollArea *scroll =new QScrollArea();
    scroll->verticalScrollBar();
    l->addWidget(click2);
    l->addWidget(click1);
    l->addWidget(click);
    l->addWidget(text);
    l->addWidget(lable1);
    QWidget *w=new QWidget();
    w->resize(400,100);
    QVBoxLayout *h=new QVBoxLayout();
    h->addLayout(l);
    h->addLayout(l1);
    w->setLayout(h);
    w->setWindowTitle("All pasenger");
    txtk=text;
    w2=w;
    sco=scroll;
    vb=l1;
    labn=lable;
    w->show();
    connect(click1,SIGNAL(clicked()),w,SLOT(close()));
    connect(click,SIGNAL(clicked()),this,SLOT(allpasenger1()));
    connect(click2,SIGNAL(clicked()),this,SLOT(helpallpasenger1()));

}
void MainWindow::helpallpasenger1()
{
    QWidget *w=new QWidget();
    w->setWindowTitle("Help");
    QLabel *lab=new QLabel("in ghesmat hameye mosaferan parvaz ra neshan midahad\nbaraye in kar bayad shomare parvaz ra vared konid va roye dOkmeye see information click konid");
    QVBoxLayout *v=new QVBoxLayout();
    v->addWidget(lab);
    w->setLayout(v);
    w->show();
            }
void MainWindow::allpasenger1()
{

    QFile file1("allnumber.txt");
    file1.open(QIODevice::ReadOnly|QIODevice::Text);
    QString d=file1.readAll();
    if(d.indexOf((" "+txtk->text()+" "))!=-1)
    {
    QString adress,d;
    adress=txtk->text();
    adress=adress+"p.txt";
    QFile file(adress);
    file.open(QIODevice::ReadWrite| QIODevice::Text);

    d=file.readAll();
    sco->setMaximumSize(400,d.count("\n"));

    d.replace("*\n","");
    labn->setText(d);
    sco->setWidget(labn);
    vb->addWidget(sco);

    w2->resize(400,600);
    file.close();
}
    else
    {
        QWidget *w2=new QWidget();
        QPushButton *Ok2=new QPushButton("Ok");
        QLabel *lab2=new QLabel("Fight number is wrong");
        QVBoxLayout *v2=new QVBoxLayout();
        v2->addWidget(lab2);
        v2->addWidget(Ok2);
        w2->setLayout(v2);
        w2->show();
        connect(Ok2,SIGNAL(clicked()),w2,SLOT(close()));

    }
}
void MainWindow::pasengerserch()
{
QWidget *w=new QWidget();
QPushButton *click1=new QPushButton("Date serch");
QPushButton *click2=new QPushButton("City serch");
QPushButton *click3=new QPushButton("Pasenger name serch");
QPushButton *click4=new QPushButton("Pasenger number serch");
QPushButton *click5=new QPushButton("Back");
QVBoxLayout *h=new QVBoxLayout();
QHBoxLayout *v1=new QHBoxLayout();
QHBoxLayout *v2=new QHBoxLayout();
QHBoxLayout *v3=new QHBoxLayout();
w->setWindowTitle("Pasenger serch");
v1->addWidget(click1);
v1->addWidget(click2);
v2->addWidget(click3);
v2->addWidget(click4);
v3->addWidget(click5);
h->addLayout(v1);
h->addLayout(v2);
h->addLayout(v3);
w->resize(400,160);
w->setLayout(h);
w->show();
connect(click1,SIGNAL(clicked()),this,SLOT(dateserch()));
connect(click2,SIGNAL(clicked()),this,SLOT(cityserch()));
connect(click3,SIGNAL(clicked()),this,SLOT(pasengern()));
connect(click4,SIGNAL(clicked()),this,SLOT(pasengerj()));
connect(click5,SIGNAL(clicked()),w,SLOT(close()));
}
void MainWindow::dateserch()
{
    QPushButton *click=new QPushButton("See fight");
    QPushButton *click1=new QPushButton("Back");
    QPushButton *click2=new QPushButton("Help");
    QLineEdit *text=new QLineEdit();
    QLabel *lable=new QLabel();
    QLabel *lable1=new QLabel("Pleas enter date");
    QHBoxLayout *l=new QHBoxLayout();
    QHBoxLayout *l1=new QHBoxLayout();
    QScrollArea *scroll =new QScrollArea();
    scroll->setWidget(lable);
    l->addWidget(click2);
    l->addWidget(click1);
    l->addWidget(click);
    l->addWidget(text);
    l->addWidget(lable1);
    lable->resize(400,500);
    QWidget *w=new QWidget();
    w->setWindowTitle("Date figh serch");
    w->resize(400,600);
    l1->addWidget(scroll);
    QVBoxLayout *h=new QVBoxLayout();
    h->addLayout(l);
    h->addLayout(l1);
    w->setLayout(h);
    labdate=lable;
    txtdate=text;
    w->show();
    connect(click1,SIGNAL(clicked()),w,SLOT(close()));
    connect(click,SIGNAL(clicked()),this,SLOT(dateserch1()));
    connect(click2,SIGNAL(clicked()),this,SLOT(helpdateserch()));
}
void MainWindow::helpdateserch()
{
    QWidget *w=new QWidget();
    w->setWindowTitle("Help");
    QLabel *lab=new QLabel("in ghesmat hameye parvazhaye tarikh mad nazar ra neshan midahad\nbaraye in kar bayad tarihk parvaz ra da kadr vared konid va bar ruye dOkme see fight click konid");
    QVBoxLayout *v=new QVBoxLayout();
    v->addWidget(lab);
    w->setLayout(v);
    w->show();

}
void MainWindow::dateserch1()
{
QFile file("allnumber.txt");
file.open(QIODevice::ReadWrite | QIODevice::Text);
QString a,b,c,d,e,f="";
QStringList k,m,n,o,p;


a=file.readAll();
k=a.split(" ");


for(int i=0;i<((k.length())/4);i++)
{
    b=k[(4*i)+1];

    QFile file1(b+".txt");
    file1.open(QIODevice ::ReadWrite|QIODevice::Text);
    c=file1.readAll();
    m=c.split("\n");
    d=m[4];
    d.replace("tarikh parvaz : ","");
    if(d==txtdate->text())
    f=f+m[0]+"\n";
    file1.close();
}
if(f=="")
    f="No date filnd!!!";
else
    f="Fight number : \n"+f;
f.replace("shomare parvaz : ","");
labdate->setText(f);
}
void MainWindow::cityserch()
{
    QPushButton *click=new QPushButton("See fight");
    QPushButton *click1=new QPushButton("Back");
     QPushButton *click2=new QPushButton("Help");
    QLineEdit *text=new QLineEdit();
    QLineEdit *text1=new QLineEdit();
    QLabel *lable=new QLabel();
    QLabel *lable2=new QLabel("Destination");
    QLabel *lable1=new QLabel("Offset");
    QHBoxLayout *l=new QHBoxLayout();
    QHBoxLayout *l1=new QHBoxLayout();
    QHBoxLayout *l2=new QHBoxLayout();
    QHBoxLayout *l3=new QHBoxLayout();
    QScrollArea *scroll =new QScrollArea();
    scroll->setWidget(lable);
    l3->addWidget(click2);
    l3->addWidget(click1);
    l3->addWidget(click);
    l->addWidget(text);
    l->addWidget(lable1);
    l2->addWidget(text1);
    l2->addWidget(lable2);
    lable->resize(400,500);
    QWidget *w=new QWidget();
    w->setWindowTitle("Offset and Destination serch");
    w->resize(400,600);
    l1->addWidget(scroll);
    QVBoxLayout *h=new QVBoxLayout();
    h->addLayout(l);
    h->addLayout(l2);
    h->addLayout(l3);
    h->addLayout(l1);
    w->setLayout(h);
    labcity=lable;
    txtcity=text;
    txtcity1=text1;
    w->show();
    connect(click1,SIGNAL(clicked()),w,SLOT(close()));
    connect(click,SIGNAL(clicked()),this,SLOT(cityserch1()));
    connect(click2,SIGNAL(clicked()),this,SLOT(helpcityserch()));
}
void MainWindow::helpcityserch()
{QWidget *w=new QWidget();
    w->setWindowTitle("Help");
    QLabel *lab=new QLabel("in ghesmat hameye parvazhaye beyn do shahr ra neshan midahad\nbaraye in kar bayad mabda va maghsad ra dar kadr vared konid va bar ruye dOkme see fight click konid");
    QVBoxLayout *v=new QVBoxLayout();
    v->addWidget(lab);
    w->setLayout(v);
    w->show();
}
void MainWindow::cityserch1()
{
QFile file("allnumber.txt");
file.open(QIODevice::ReadWrite | QIODevice::Text);
QString a,b,c,d,e,f="",g;
QStringList k,m,n,o,p;
a=file.readAll();
k=a.split(" ");
for(int i=0;i<((k.length())/4);i++)
{
    b=k[(4*i)+1];
    QFile file1(b+".txt");
    file1.open(QIODevice ::ReadWrite|QIODevice::Text);
    c=file1.readAll();
    m=c.split("\n");
    d=m[1];
    g=m[2];
    d.replace("mabda : ","");
    g.replace("maghsad : ","");
    if(d==txtcity->text() && g==txtcity1->text())
    f=f+m[0]+"\n";
    file1.close();
}
if(f=="")
    f="No date filnd!!!";
else
    f="Fight number : \n"+f;
f.replace("shomare parvaz : ","");
labcity->setText(f);
}
void MainWindow::pasengerj()
{
    QPushButton *click=new QPushButton("See fight");
    QPushButton *click1=new QPushButton("Back");
    QPushButton *click2=new QPushButton("help");
    QLineEdit *text=new QLineEdit();
    QLabel *lable=new QLabel();
    QLabel *lable1=new QLabel("Pleas enter date");
    QHBoxLayout *l=new QHBoxLayout();
    QHBoxLayout *l1=new QHBoxLayout();
    QScrollArea *scroll =new QScrollArea();
    scroll->setWidget(lable);
    l->addWidget(click2);
    l->addWidget(click1);
    l->addWidget(click);
    l->addWidget(text);
    l->addWidget(lable1);
    lable->resize(400,500);
    QWidget *w=new QWidget();
    w->setWindowTitle("Fight serch with passenger number");
    w->resize(400,600);
    l1->addWidget(scroll);
    QVBoxLayout *h=new QVBoxLayout();
    h->addLayout(l);
    h->addLayout(l1);
    w->setLayout(h);
    labserchj=lable;
    txtserchj=text;
    w->show();
    connect(click1,SIGNAL(clicked()),w,SLOT(close()));
    connect(click,SIGNAL(clicked()),this,SLOT(pasengerj1()));
    connect(click2,SIGNAL(clicked()),this,SLOT(helppasengerj()));
}
void MainWindow::helppasengerj()
{
    QWidget *w=new QWidget();
    w->setWindowTitle("Help");
    QLabel *lab=new QLabel("in ghesmat shomare mosafer ra migirad va shomare parvazhayi ra ke ou gharar darad ra na mayesh midahad\nbaraye in kar bayad shomare mosafer ra dar kadr vared konid va bar ruye dOkme see fight click konid");
    QVBoxLayout *v=new QVBoxLayout();
    v->addWidget(lab);
    w->setLayout(v);
    w->show();
}
void MainWindow::pasengerj1()
{
QFile file("allnumber.txt");
file.open(QIODevice::ReadWrite | QIODevice::Text);
QString a,b,c,d,f="";
QStringList k,m,n,o,p;
a=file.readAll();
k=a.split(" ");
for(int i=0;i<((k.length())/4);i++)
{
    b=k[(4*i)+1];
    QFile file1(b+"p1.txt");
    file1.open(QIODevice ::ReadWrite|QIODevice::Text);
    c=file1.readAll();
    m=c.split("\n");
    for(int j=0;j<(m.length());j++)
    {
    d=m[j];
    n=d.split(" ");
    d.replace(n[0],"");

    if(d==(" "+txtserchj->text()))
        {
        f=f+b+"\n";
        break;
    }
    }
    file1.close();
}
if(f=="")
    f="No date filnd!!!";
else
    f="Fight number : \n"+f;
f.replace("shomare parvaz : ","");
labserchj->setText(f);
}
void MainWindow::pasengern()
{
    QPushButton *click=new QPushButton("See fight");
    QPushButton *click1=new QPushButton("Back");
    QPushButton *click2=new QPushButton("Help");
    QLineEdit *text=new QLineEdit();
    QLineEdit *text1=new QLineEdit();
    QLabel *lable=new QLabel();
    QLabel *lable2=new QLabel("Last Name");
    QLabel *lable1=new QLabel("Name");
    QHBoxLayout *l=new QHBoxLayout();
    QHBoxLayout *l1=new QHBoxLayout();
    QHBoxLayout *l2=new QHBoxLayout();
    QHBoxLayout *l3=new QHBoxLayout();
    QScrollArea *scroll =new QScrollArea();
    scroll->setWidget(lable);
    l3->addWidget(click2);
    l3->addWidget(click1);
    l3->addWidget(click);
    l->addWidget(text);
    l->addWidget(lable1);
    l2->addWidget(text1);
    l2->addWidget(lable2);
    lable->resize(400,500);
    QWidget *w=new QWidget();
    w->setWindowTitle("Fight serch with passenger name");
    w->resize(400,600);
    l1->addWidget(scroll);
    QVBoxLayout *h=new QVBoxLayout();
    h->addLayout(l);
    h->addLayout(l2);
    h->addLayout(l3);
    h->addLayout(l1);
    w->setLayout(h);
    labserchn=lable;
    txtserchn=text;
    txtserchn1=text1;
    w->show();
    connect(click1,SIGNAL(clicked()),w,SLOT(close()));
    connect(click,SIGNAL(clicked()),this,SLOT(pasengern1()));
    connect(click2,SIGNAL(clicked()),this,SLOT(helppasengern()));
}
void MainWindow::helppasengern()
{
    QWidget *w=new QWidget();
    w->setWindowTitle("Help");
    QLabel *lab=new QLabel("in ghesmat hameye parvaz haye mosafer ra midahad\nbaraye in kar bayad name mosafer ra da kadr vared konid va bar ruye dOkme see fight click konid");
    QVBoxLayout *v=new QVBoxLayout();
    v->addWidget(lab);
    w->setLayout(v);
    w->show();
}
void MainWindow::pasengern1()
{
QFile file("allnumber.txt");
file.open(QIODevice::ReadWrite | QIODevice::Text);
QString a,b,c,d,f="";
QStringList k,m,n,o,p;
a=file.readAll();
k=a.split(" ");
for(int i=0;i<((k.length())/4);i++)
{
    b=k[(4*i)+1];
    QFile file1(b+"p.txt");
    file1.open(QIODevice ::ReadWrite|QIODevice::Text);
    c=file1.readAll();
    m=c.split("\n");
    for(int j=0;j<(m.length());j++)
    {
    d=m[j];
    n=d.split(" ");
    d.replace(n[0],"");

    if(d==(" "+txtserchn->text()+" "+txtserchn1->text()))
        {
        f=f+b+"\n";
        break;
    }
    }
    file1.close();
}
if(f=="")
    f="No date filnd!!!";
else
    f="Fight number : \n"+f;
f.replace("shomare parvaz : ","");
labserchn->setText(f);
}
void MainWindow::buy()
{
    QPushButton *click=new QPushButton("Buy");
    QPushButton *click1=new QPushButton("Cancel");
    QLabel *lable1=new QLabel("Name : ");
    QLabel *lable2=new QLabel("Last name : ");
    QLabel *lable3=new QLabel("Pasenger number : ");
    QLabel *lable4=new QLabel("Nationli(shenasname!) number : ");
    QLabel *lable5=new QLabel("Fight number");
    QLabel *lable6=new QLabel("How many ticket");
    QLabel *lable7=new QLabel("continuose ?");
    QLineEdit *text1=new QLineEdit();
    QLineEdit *text2=new QLineEdit();
    QLineEdit *text3=new QLineEdit();
    QLineEdit *text4=new QLineEdit();
    QLineEdit *text5=new QLineEdit();
    QLineEdit *text6=new QLineEdit();
    QRadioButton *radio=new QRadioButton("Yes");
    QRadioButton *radio1=new QRadioButton("No");
    QHBoxLayout *l1=new QHBoxLayout();
    l1->addWidget(lable1);
    l1->addWidget(text1);
    QHBoxLayout *l2=new QHBoxLayout();
    text2->resize(15,60);
    l2->addWidget(lable2);
    l2->addWidget(text2);
    QHBoxLayout *l3=new QHBoxLayout();
    text3->resize(15,60);
    l3->addWidget(lable3);
    l3->addWidget(text3);
    QHBoxLayout *l4=new QHBoxLayout();
    text4->resize(15,60);
    l4->addWidget(lable4);
    l4->addWidget(text4);
    QHBoxLayout *l5=new QHBoxLayout();
    text5->resize(15,60);
    l5->addWidget(lable5);
    l5->addWidget(text5);
    QHBoxLayout *l6=new QHBoxLayout();
    text6->resize(15,60);
    l6->addWidget(lable6);
    l6->addWidget(text6);
    QHBoxLayout *l7=new QHBoxLayout();
    l7->addWidget(lable7);
    l7->addWidget(radio);
    l7->addWidget(radio1);
    QHBoxLayout *l8=new QHBoxLayout();
    l8->addWidget(click);
    l8->addWidget(click1);
    QWidget *w=new QWidget();
    w->resize(200,400);
    QVBoxLayout *h=new QVBoxLayout();
    h->addLayout(l1);
    h->addLayout(l2);
    h->addLayout(l3);
    h->addLayout(l4);
    h->addLayout(l5);
    h->addLayout(l6);
    h->addLayout(l7);
    h->addLayout(l8);
    w->setLayout(h);
    w->setWindowTitle("Buy");
    w->show();
    wbuy=w;
    radi=radio;
    txt21=text1;
    txt22=text2;
    txt23=text3;
    txt24=text4;
    txt25=text5;
    txt26=text6;
    connect(click1,SIGNAL(clicked()),w,SLOT(close()));
    connect(click,SIGNAL(clicked()),this,SLOT(buyticket()));
}
void MainWindow::buyticket()
        {
            int x=0,y=0,z=0,w=0,t,s,i;
            QFile file("allnumber.txt");
            file.open(QIODevice::ReadOnly | QIODevice::Text);

            QString d,e,c,a,b="",f,g,p,p1;
            QStringList k,m,n;
            d=file.readAll();
            if(d.indexOf((" "+txt25->text()+" "))!=-1 || d.indexOf((" "+txt25->text()+"\n"))!=-1)
            {
                QFile file1(txt25->text()+".txt");
                file1.open(QIODevice::ReadWrite | QIODevice::Text);
                QTextStream in(& file1);

                QFile filep(txt25->text()+"p.txt");
                filep.open(QIODevice::ReadWrite | QIODevice::Text);

                QFile filep11(txt25->text()+"p1.txt");
                filep11.open(QIODevice::ReadWrite | QIODevice::Text);

                p=filep.readAll();
                p1=filep11.readAll();
                e=file1.readAll();

                k=e.split("*");
                f=k[0];
                e=k[1];
                c=e;

                c.replace("\n","\n ");
                e.replace("\n"," ");
                e.replace("       "," ");
                e.replace("      "," ");
                e.replace("     "," ");
                e.replace("    "," ");
                e.replace("  "," ");
                e.replace("  "," ");




                m=e.split(" ");

                for(i=0;i<m.length();i++)
                {
                    if(m[i]!="XX" && m[i]!="" && m[i]!=" " && m[i]!="  ")
                    {
                        x++;
                        z++;
                    }
                    else
                    {
                        if(y<x)
                        {
                            t=i-1;
                            y=x;
                            x=0;
                        }
                        else
                        {
                            x=0;
                        }

                    }
                }
                if(y<x)
                {
                    t=i-1;
                    y=x;
                    x=0;
                }
                //z=tedad sandalihaye khali
                //y=tedad bishtarin sandali posht sa ham khali
                if((txt26->text()).toInt()>z)
                {
                    QWidget *w2=new QWidget();
                    QPushButton *Ok2=new QPushButton("Ok");
                    QLabel *lab2=new QLabel("Dont have enough chair ");
                    QVBoxLayout *v2=new QVBoxLayout();
                    v2->addWidget(lab2);
                    v2->addWidget(Ok2);
                    w2->setWindowTitle("Masage");
                    w2->setLayout(v2);
                    w2->show();
                    connect(Ok2,SIGNAL(clicked()),w2,SLOT(close()));

                }
                else
                {
                    if(radi->isChecked())
                    {
                       if((txt26->text()).toInt()>y)
                        {
                           QWidget *w3=new QWidget();
                           QPushButton *Ok3=new QPushButton("Ok");
                           QLabel *lab3=new QLabel("dont have enough chair motevali");
                           QVBoxLayout *v3=new QVBoxLayout();
                           v3->addWidget(lab3);
                           v3->addWidget(Ok3);
                           w3->setLayout(v3);
                           w3->setWindowTitle("Masage");
                           w3->show();
                           connect(Ok3,SIGNAL(clicked()),w3,SLOT(close()));

                       }
                       else
                       {
                           for(int j=t;j>(t-((txt26->text()).toInt()));j--)
                           {
                              c.replace(" "+(m[j]+" ")," XX ");
                              c.replace(" "+(m[j]+"\n")," XX\n");
                              b=b+" "+m[j];
                              p.replace(("\n"+m[j]+"\n"),("\n"+m[j]+" "+(txt21->text())+" "+(txt22->text())+"\n"));
                              p1.replace(("\n"+m[j]+"\n"),("\n"+m[j]+" "+(txt23->text())+"\n"));

                           }
                           filep.remove();
                           filep11.remove();
                           QFile filep1(txt25->text()+"p.txt");
                           filep1.open(QIODevice::ReadWrite | QIODevice::Text);
                           QTextStream inp(& filep1);
                           inp<<p;
                           QFile filep12(txt25->text()+"p1.txt");
                           filep12.open(QIODevice::ReadWrite | QIODevice::Text);
                           QTextStream inp2(& filep12);
                           inp2<<p1;
                           QFile file2("allpasengernumber.txt");
                           file2.open(QIODevice::ReadWrite|QIODevice::Text);
                           QTextStream in1(& file2);
                           a=file2.readAll();
                           if(a.indexOf(" "+(txt23->text())+" ")==-1)
                           {
                               QFile file3(((txt23->text()+".txt")));
                               file3.open(QIODevice::ReadWrite|QIODevice::Text);
                               QTextStream in2(&file3);
                               in2<<"name : "<<txt21->text()<<"\nlast name : "<<txt22->text()<<"\npassenger number : "<<txt23->text()<<"\nshomare shenasname : "<<txt24->text()<<"\nshomare parvaz : "<<txt25->text()<<"\ntedad bilit : "<<txt26->text()<<"\n shomare sandaliha : "<<b;
                           in1<<" "<<txt23->text()<<" ";
                           QFile file4("allpasenger.txt");
                           file4.open(QIODevice::ReadWrite|QIODevice::Text);
                           QTextStream in3(& file4);
                           g=file4.readAll();
                           in3<<txt23->text()<<" "<<txt21->text()<<"  "<<txt22->text()<<"\n";
                           file1.remove();
                           QFile file1(txt25->text()+".txt");
                           file1.open(QIODevice::ReadWrite | QIODevice::Text);
                           QTextStream in(& file1);
                           c.replace("\n ","\n");
                           QWidget *w5=new QWidget();
                           QPushButton *Ok5=new QPushButton("Ok");
                           QLabel *lab5=new QLabel("tickets to buyed sucsesfully");
                           QVBoxLayout *v5=new QVBoxLayout();
                           v5->addWidget(lab5);
                           v5->addWidget(Ok5);
                           w5->setWindowTitle("Masage");
                           w5->setLayout(v5);
                           w5->show();
                           connect(Ok5,SIGNAL(clicked()),w5,SLOT(close()));
                           connect(Ok5,SIGNAL(clicked()),wbuy,SLOT(close()));

                           in<<f<<"*\n"<<c;

                       }
                       else
                           {
                           QWidget *w4=new QWidget();
                           QPushButton *Ok4=new QPushButton("Ok");
                           QLabel *lab4=new QLabel("this pasenger number dont right pleas chang that");
                           QVBoxLayout *v4=new QVBoxLayout();
                           v4->addWidget(lab4);
                           v4->addWidget(Ok4);
                           w4->setWindowTitle("Masage");
                           w4->setLayout(v4);
                           w4->show();
                           connect(Ok4,SIGNAL(clicked()),w4,SLOT(close()));


                       }
                       }


                    }
                    else
                    {
                        for (int i=0;i<m.length();i++){
                            if(m[i]!="XX"&&m[i]!=""&&m[i]!=" "&&m[i]!="  ")
                            {
                                w++;
                                b=b+" "+m[i];
                                c.replace((" "+m[i]+" ")," XX ");
                                c.replace(("\n"+m[i]+" ")," XX ");
                                c.replace((" "+m[i]+"\n")," XX ");
                                p.replace(("\n"+m[i]+"\n"),("\n"+m[i]+" "+(txt21->text())+" "+(txt22->text())+"\n"));
                                p1.replace(("\n"+m[i]+"\n"),("\n"+m[i]+" "+(txt23->text())+"\n"));

                             }
                             filep.remove();
                             QFile filep1(txt25->text()+"p.txt");
                             filep1.open(QIODevice::ReadWrite | QIODevice::Text);
                             QTextStream inp(& filep1);
                             inp<<p;
                             filep11.remove();
                             QFile filep12(txt25->text()+"p1.txt");
                             filep12.open(QIODevice::ReadWrite | QIODevice::Text);
                             QTextStream inp1(& filep12);
                             inp1<<p1;
                            if(w==(txt26->text()).toInt())
                                break;
                        }

                        QFile file2("allpasengernumber.txt");
                        file2.open(QIODevice::ReadWrite|QIODevice::Text);
                        QTextStream in1(& file2);
                        a=file2.readAll();
                        if(a.indexOf(" "+(txt23->text())+" ")==-1)
                        {
                            QFile file3(((txt23->text()+".txt")));
                            file3.open(QIODevice::ReadWrite|QIODevice::Text);
                            QTextStream in2(&file3);
                            in2<<"name : "<<txt21->text()<<"\nlast name : "<<txt22->text()<<"\npassenger number : "<<txt23->text()<<"\nshomare shenasname : "<<txt24->text()<<"\nshomare parvaz : "<<txt25->text()<<"\ntedad bilit : "<<txt26->text()<<"\n shomare sandaliha : "<<b;
                        in1<<" "<<txt23->text()<<" ";
                        QFile file4("allpasenger.txt");
                        file4.open(QIODevice::ReadWrite|QIODevice::Text);
                        QTextStream in3(& file4);
                        g=file4.readAll();
                        in3<<txt23->text()<<" "<<txt21->text()<<"  "<<txt22->text()<<"\n";
                        file1.remove();
                        QFile file1(txt25->text()+".txt");
                        file1.open(QIODevice::ReadWrite | QIODevice::Text);
                        QTextStream in(& file1);
                        c.replace("\n ","\n");
                        QWidget *w5=new QWidget();
                        QPushButton *Ok5=new QPushButton("Ok");
                        QLabel *lab5=new QLabel("tickets be buyed sucsesfully");
                        QVBoxLayout *v5=new QVBoxLayout();
                        v5->addWidget(lab5);
                        v5->addWidget(Ok5);
                        w5->setWindowTitle("Masage");
                        w5->setLayout(v5);
                        w5->show();
                        connect(Ok5,SIGNAL(clicked()),w5,SLOT(close()));
                        connect(Ok5,SIGNAL(clicked()),wbuy,SLOT(close()));

                        in<<f<<"*\n"<<c;

                    }
                    else
                        {
                        QWidget *w4=new QWidget();
                        QPushButton *Ok4=new QPushButton("Ok");
                        QLabel *lab4=new QLabel("this pasenger number is wrong");
                        QVBoxLayout *v4=new QVBoxLayout();
                        v4->addWidget(lab4);
                        v4->addWidget(Ok4);
                        w4->setWindowTitle("Masage");
                        w4->setLayout(v4);
                        w4->show();
                        connect(Ok4,SIGNAL(clicked()),w4,SLOT(close()));


                    }
                    }
                    }









            }
            else
            {

                QWidget *w1=new QWidget();
                QPushButton *Ok1=new QPushButton("Ok");
                QLabel *lab1=new QLabel("fight number is wrong pleas change it");
                QVBoxLayout *v1=new QVBoxLayout();
                v1->addWidget(lab1);
                v1->addWidget(Ok1);
                w1->setWindowTitle("Massage");
                w1->setLayout(v1);
                w1->show();
                connect(Ok1,SIGNAL(clicked()),w1,SLOT(close()));
            }



        }
void MainWindow::edit()
{


    QWidget *w=new QWidget();
QPushButton *edit=new QPushButton("Ok");
QLabel *lable=new QLabel("Enter fight number");
QLineEdit *text=new QLineEdit();
QHBoxLayout *h=new QHBoxLayout();
w->setWindowTitle("Fight edit");
h->addWidget(lable);

h->addWidget(text);
h->addWidget(edit);
w->setLayout(h);
w->resize(400,100);
w->show();



txtedit=text;

connect(edit,SIGNAL(clicked()),this,SLOT(edit1()));
connect(edit,SIGNAL(clicked()),w,SLOT(close()));


}
void MainWindow::edit1()
{      
    QFile file1("allnumber.txt");
    file1.open(QIODevice::ReadOnly|QIODevice::Text);
    QString d=file1.readAll();
    if(d.indexOf((" "+txtedit->text()+" "))!=-1)
    {
        QFile file(txtedit->text()+".txt");
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QString a,b,c,d;
        QStringList k;
        a=file.readAll();
        k=a.split("\n");
        QWidget *w=new QWidget();
        QLabel *lable1=new QLabel(("Fight number : "+txtedit->text()));
        QLabel *lable2=new QLabel("Offset : ");
        QLabel *lable3=new QLabel("Destination : ");
        QLabel *lable4=new QLabel("Airplan model : ");
        QLabel *lable5=new QLabel("Fight date");
        QLabel *lable6=new QLabel("How many rows? ");
        QLabel *lable7=new QLabel("How many chair in each row? ");
        b=k[1];
        QLineEdit *text2 = new QLineEdit(b.replace("mabda : ",""));
        b=k[2];
        QLineEdit *text3 = new QLineEdit(b.replace("maghsad : ",""));
        b=k[3];
        QLineEdit *text4 = new QLineEdit(b.replace("model havapeyma : ",""));
        b=k[4];
        QLineEdit *text5 = new QLineEdit(b.replace("tarikh parvaz : ",""));
        b=k[5];
        QLineEdit *text6 = new QLineEdit(b.replace("tedad radif : ",""));
        b=k[6];
        QLineEdit *text7 = new QLineEdit(b.replace("tedad sandali dar har radif : ",""));
        txt12=text2;
        txt13=text3;
        txt14=text4;
        txt15=text5;
        txt16=text6;
        txt17=text7;
        QPushButton *click=new QPushButton("Save changes");
        QPushButton *click1=new QPushButton("Cancel");
        QHBoxLayout *v1=new QHBoxLayout();
        QHBoxLayout *v2=new QHBoxLayout();
        QHBoxLayout *v3=new QHBoxLayout();
        QHBoxLayout *v4=new QHBoxLayout();
        QHBoxLayout *v5=new QHBoxLayout();
        QHBoxLayout *v6=new QHBoxLayout();
        QHBoxLayout *v7=new QHBoxLayout();
        QHBoxLayout *v8=new QHBoxLayout();
        v1->addWidget(lable1);
        v2->addWidget(lable2);
        v2->addWidget(text2);
        v3->addWidget(lable3);
        v3->addWidget(text3);
        v4->addWidget(lable4);
        v4->addWidget(text4);
        v5->addWidget(lable5);
        v5->addWidget(text5);
        v6->addWidget(lable6);
        v6->addWidget(text6);
        v7->addWidget(lable7);
        v7->addWidget(text7);
        v8->addWidget(click);
        v8->addWidget(click1);
        QVBoxLayout *h=new QVBoxLayout();
        h->addLayout(v1);
        h->addLayout(v2);
        h->addLayout(v3);
        h->addLayout(v4);
        h->addLayout(v5);
        h->addLayout(v6);
        h->addLayout(v7);
        h->addLayout(v8);
        w->setLayout(h);
        w->resize(200,600);
        w->show();
        connect(click,SIGNAL(clicked()),this,SLOT(edit2()));
        connect(click1,SIGNAL(clicked()),w,SLOT(close()));
        w1=w;
    }

    else
    {
        QWidget *w2=new QWidget();
        QPushButton *Ok2=new QPushButton("Ok");
        QLabel *lab2=new QLabel("in shomare parvaz vojod nadarad");
        QVBoxLayout *v2=new QVBoxLayout();
        v2->addWidget(lab2);
        v2->addWidget(Ok2);
        w2->setLayout(v2);
        w2->setWindowTitle("Masage");
        w2->show();
        connect(Ok2,SIGNAL(clicked()),w2,SLOT(close()));

    }
}
void MainWindow::edit2()
{

    char b[10];


    QFile file1((txtedit->text()+".txt"));
    QFile filep1((txtedit->text()+"p.txt"));
    filep1.open(QIODevice::ReadWrite|QIODevice::Text);
    file1.open(QIODevice::ReadWrite| QIODevice::Text);
    file1.remove();
    filep1.remove();

    QFile file((txtedit->text()+".txt"));
    QFile filep((txtedit->text()+"p.txt"));
    filep.open(QIODevice::ReadWrite|QIODevice::Text);
    QTextStream inp(&filep);
    QString f="",k,g,p="";
    file.open(QIODevice::ReadWrite| QIODevice::Text);
    f="shomare parvaz : "+txtedit->text()+"\n"+"mabda : "+txt12->text()+"\n"+"maghsad : "+txt13->text()+"\n"+"model havapeyma : "+txt14->text()+"\n"+"tarikh parvaz : "+txt15->text()+"\n"+"tedad radif : "+txt16->text()+"\n"+"tedad sandali dar har radif : "+txt17->text()+"\n"+"*\n\n";




    for(int i=0;i<((txt16->text()).toInt());i++)
    {

        for(int j=0;j<((txt17->text()).toInt());j++)
        {
            if(i*((txt17->text()).toInt())+j<10)
            {
                itoa(i*((txt17->text()).toInt())+j,b,10);
                f=f+QString(b)+"   ";
            }
            if((i*((txt17->text()).toInt())+j)>9 && (i*((txt17->text()).toInt())+j)<100 )
            {
                itoa(i*((txt17->text()).toInt())+j,b,10);
                f=f+QString(b)+"  ";
            }
            if((i*((txt17->text()).toInt())+j)>99  )
            {
                itoa(i*((txt17->text()).toInt())+j,b,10);
                f=f+QString(b)+" ";
            }

        p=p+QString(b)+"\n";
        }
        f=f+"\n";
    }


    QTextStream out(&file);

    inp<<p;

    out << f;


    QWidget *masage=new QWidget();
    QLabel *labl=new QLabel("Information edited sucsesfuly");
    QPushButton *Ok=new QPushButton("Ok");
    QVBoxLayout *m=new QVBoxLayout();
    m->addWidget(labl);
    m->addWidget(Ok);
    masage->resize(400,100);
    Ok->resize(20,10);
    masage->setLayout(m);
    masage->setWindowTitle("Masage");
    masage->show();
    connect(Ok,SIGNAL(clicked()),masage,SLOT(close()));
    connect(Ok,SIGNAL(clicked()),w1,SLOT(close()));

}
void MainWindow::info()
{
QPushButton *click=new QPushButton("see information");
QPushButton *click1=new QPushButton("back");
QLineEdit *text=new QLineEdit();
QLabel *lable=new QLabel();
QLabel *lable1=new QLabel("pleas enter fight number");
QHBoxLayout *l=new QHBoxLayout();
QHBoxLayout *l1=new QHBoxLayout();
QScrollArea *scroll =new QScrollArea();
//scroll->setWidget(lable);
l->addWidget(click1);
l->addWidget(click);
l->addWidget(text);
l->addWidget(lable1);
//lable->resize(400,00);
QWidget *w=new QWidget();
w->resize(400,100);
//l1->addWidget(scroll);
QVBoxLayout *h=new QVBoxLayout();
h->addLayout(l);
h->addLayout(l1);
w->setLayout(h);
lab=lable;
txt=text;
sco1=scroll;
vb1=l1;
w->setWindowTitle("Fight information");
w->show();
w3=w;
connect(click1,SIGNAL(clicked()),w,SLOT(close()));
connect(click,SIGNAL(clicked()),this,SLOT(information()));
}
void MainWindow::information()
{
    QFile file1("allnumber.txt");
    file1.open(QIODevice::ReadOnly|QIODevice::Text);
    QString d=file1.readAll();
    if(d.indexOf((" "+txt->text()+" "))!=-1)
    {
    QString adress,d;
    adress=txt->text();
    adress=adress+".txt";
    QFile file(adress);
    file.open(QIODevice::ReadWrite| QIODevice::Text);

    d=file.readAll();
    d.replace("*\n","");


    lab->setText(d);
    sco1->setWidget(lab);
    vb1->addWidget(sco1);
    w3->resize(400,600);

    file.close();
}
    else
    {
        QWidget *w2=new QWidget();
        QPushButton *Ok2=new QPushButton("Ok");
        QLabel *lab2=new QLabel("flight number is wrong");
        QVBoxLayout *v2=new QVBoxLayout();
        v2->addWidget(lab2);
        v2->addWidget(Ok2);
        w2->setLayout(v2);
        w2->setWindowTitle("Massage");
        w2->show();
        connect(Ok2,SIGNAL(clicked()),w2,SLOT(close()));

    }

}
void MainWindow::cancel()
{
    QWidget *w=new QWidget;
    QHBoxLayout *l=new QHBoxLayout(w);
    QPushButton *click=new QPushButton("Delet");
    QLabel *lable=new QLabel("pleas enter pasenger number");
    QLineEdit *text=new QLineEdit();
    l->addWidget(lable);
    l->addWidget(text);
    l->addWidget(click);
    txtcancel=text;
    w->setWindowTitle("Fight cancel");
    w->setLayout(l);
   w->resize(400,100);
   w6=w;
   w->show();
    connect(click,SIGNAL(clicked()),this,SLOT(cancelaction()));

}
void MainWindow::cancelaction()
{
    QString a,b,c,d,e,f,g,h,l="\n",ptxt,ptxt1,q,r1,s;
    QStringList k,m,n,o,p,pl,pl1,pl2;

    QFile file(txtcancel->text()+".txt");
    file.open(QIODevice::ReadWrite|QIODevice::Text);

    a=file.readAll();
    k=a.split("\n");
    b=k[4];
    w6->close();
    b.replace("shomare parvaz : ","");
    c=k[6];
    c.replace(" shomare sandaliha :  ","");
    m=c.split(" ");
    a=k[0]+"\n"+k[1]+"\n"+k[2]+"\n"+k[3]+"\n"+k[4]+"\ntedad bilit : 0\n"+" shomare sandaliha : ";
    file.remove();
    QFile file2((txtcancel->text()+".txt"));
    file2.open(QIODevice::ReadWrite|QIODevice::Text);
    QTextStream in(&file2);
    in<<a;
    QFile filep(b+"p.txt");
    QFile filep1(b+"p1.txt");
    filep.open(QIODevice::ReadWrite | QIODevice::Text);
    filep1.open(QIODevice::ReadWrite | QIODevice::Text);

    QFile file1(b+".txt");
    file1.open(QIODevice::ReadWrite | QIODevice::Text);

    e=file1.readAll();

    n=e.split("*");
    f=n[0];
    e=n[1];
    c.replace("\n","\n ");
    e.replace("\n"," ");
    e.replace("       "," ");
    e.replace("      "," ");
    e.replace("     "," ");
    e.replace("    "," ");
    e.replace("  "," ");
    e.replace("  "," ");
    o=e.split(" ");
    QString w[(o.length())];
    for(int i=0;i<o.length();i++)
    {
        w[i]=o[i];
    }
    for(int i=0;i<m.length();i++)
    {
        d=m[i];
        w[d.toInt()]=m[i];
    }
    p=f.split("\n");
    g=p[5];
    g.replace("tedad radif : ","");
    h=p[6];
    h.replace("tedad sandali dar har radif : ","");
    h.replace("ad sandali dar har radif : ","");
    int r=0;
    for(int i=0;i<g.toInt();i++)
    {
        for(int j=0;j<h.toInt();j++)
        {
            l=l+w[r]+"   ";
            r++;

        }
        l=l+"\n";
    }
    file1.remove();
    QFile file3(b+".txt");
    file3.open(QIODevice::ReadWrite | QIODevice::Text);
    QTextStream in1(& file3);
    in1<<f<<"*\n"<<l;
    ptxt=filep.readAll();
    ptxt1=filep1.readAll();
    pl=ptxt.split("\n");
    pl1=ptxt1.split("\n");
    for(int i=0;i<m.length();i++)
    {

        d=m[i];
        q=pl[d.toInt()];
        pl2=q.split(" ");
        pl[d.toInt()]=pl2[0];
        pl1[d.toInt()]=pl2[0];


    }
    r1="";
    s="";
    for(int i=0;i<(pl.length()-1);i++)
    {
        r1=r1+pl[i]+"\n";
        s=s+pl1[i]+"\n";
    }
    filep.remove();
    filep1.remove();
    QFile filep11(b+"p.txt");
    QFile filep12(b+"p1.txt");
    filep11.open(QIODevice::ReadWrite | QIODevice::Text);
    filep12.open(QIODevice::ReadWrite | QIODevice::Text);
    QTextStream inp(&filep11);
    QTextStream inp1(&filep12);
    inp<<r1;
    inp1<<s;

}
void MainWindow::all()
{
    QFile file("all.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString k=file.readAll();
    k.replace("be",QString::fromUtf8("به"));

    QWidget *w=new QWidget();
    QLabel *lable=new QLabel();
    QVBoxLayout *v=new QVBoxLayout();
    QScrollArea *scroll=new QScrollArea();
    lable->setText(k);
    v->addWidget(scroll);
    scroll->setWidget(lable);
    w->setLayout(v);
    w->setWindowTitle("All fight");
    w->resize(400,600);


    w->show();
    file.close();
}
void MainWindow::newfly()
{
    QPushButton *click=new QPushButton("save");
    QPushButton *click1=new QPushButton("cancel");


QLabel *lable1=new QLabel("Fight number");
QLabel *lable2=new QLabel("Offset");
QLabel *lable3=new QLabel("Destination");
QLabel *lable4=new QLabel("Airplan model");
QLabel *lable5=new QLabel("filght date");
QLabel *lable6=new QLabel("how many row ");
QLabel *lable7=new QLabel("how many chair in each row");
QLineEdit *text1=new QLineEdit();
QLineEdit *text2=new QLineEdit();
QLineEdit *text3=new QLineEdit();
QLineEdit *text4=new QLineEdit();
QLineEdit *text5=new QLineEdit();
QLineEdit *text6=new QLineEdit();
QLineEdit *text7=new QLineEdit();



    QHBoxLayout *l1=new QHBoxLayout();

    l1->addWidget(lable1);
    l1->addWidget(text1);
    QHBoxLayout *l2=new QHBoxLayout();
    text2->resize(15,60);
    l2->addWidget(lable2);
    l2->addWidget(text2);
    QHBoxLayout *l3=new QHBoxLayout();
    text3->resize(15,60);
    l3->addWidget(lable3);
    l3->addWidget(text3);
    QHBoxLayout *l4=new QHBoxLayout();
    text4->resize(15,60);
    l4->addWidget(lable4);
    l4->addWidget(text4);
    QHBoxLayout *l5=new QHBoxLayout();
    text5->resize(15,60);
    l5->addWidget(lable5);
    l5->addWidget(text5);
    QHBoxLayout *l6=new QHBoxLayout();
    text6->resize(15,60);
    l6->addWidget(lable6);
    l6->addWidget(text6);
    QHBoxLayout *l7=new QHBoxLayout();
    text7->resize(15,60);
    l7->addWidget(lable7);
    l7->addWidget(text7);
    QHBoxLayout *l8=new QHBoxLayout();

    l8->addWidget(click);
    l8->addWidget(click1);



    QWidget *w=new QWidget();
    w->resize(200,400);
    wnew=w;
w->setWindowTitle("Make new fight");
    QVBoxLayout *h=new QVBoxLayout();
    h->addLayout(l1);
    h->addLayout(l2);
    h->addLayout(l3);
    h->addLayout(l4);
    h->addLayout(l5);
    h->addLayout(l6);
    h->addLayout(l7);
    h->addLayout(l8);
    w->setLayout(h);

    txt1=text1;
    txt2=text2;
    txt3=text3;
    txt4=text4;
    txt5=text5;
    txt6=text6;
    txt7=text7;
    w->show();
    connect(click1,SIGNAL(clicked()),w,SLOT(close()));
    connect(click,SIGNAL(clicked()),this,SLOT(save()));
}
void MainWindow::save()
{
    char b[10];
    QFile file2("allnumber.txt");
    QFile file1("all.txt");
    QFile file((txt1->text()+".txt"));
    QFile filep((txt1->text()+"p.txt"));
    filep.open(QIODevice::ReadWrite|QIODevice::Text);
    QTextStream inp(&filep);
    QFile filep1((txt1->text()+"p1.txt"));
    filep1.open(QIODevice::ReadWrite|QIODevice::Text);
    QTextStream inp1(&filep1);
    QString f="",k,g,p="";
    file2.open(QIODevice::ReadWrite| QIODevice::Text);
    g=file2.readAll();
    if(g.indexOf(txt1->text())==-1)
    {
    file.open(QIODevice::ReadWrite| QIODevice::Text);
    file1.open(QIODevice::ReadWrite| QIODevice::Text);
    f="shomare parvaz : "+txt1->text()+"\n"+"mabda : "+txt2->text()+"\n"+"maghsad : "+txt3->text()+"\n"+"model havapeyma : "+txt4->text()+"\n"+"tarikh parvaz : "+txt5->text()+"\n"+"tedad radif : "+txt6->text()+"\n"+"tedad sandali dar har radif : "+txt7->text()+"\n"+"*\n\n";
    k=file1.readAll();



    for(int i=0;i<((txt6->text()).toInt());i++)
    {

        for(int j=0;j<((txt7->text()).toInt());j++)
        {
            if(i*((txt7->text()).toInt())+j<10)
            {
                itoa(i*((txt7->text()).toInt())+j,b,10);
                f=f+QString(b)+"   ";
            }
            if((i*((txt7->text()).toInt())+j)>9 && (i*((txt7->text()).toInt())+j)<100 )
            {
                itoa(i*((txt7->text()).toInt())+j,b,10);
                f=f+QString(b)+"  ";
            }
            if((i*((txt7->text()).toInt())+j)>99  )
            {
                itoa(i*((txt7->text()).toInt())+j,b,10);
                f=f+QString(b)+" ";
            }

        p=p+QString(b)+"\n";
        }
        f=f+"\n";
    }
    k=txt1->text()+ "  "+txt2->text()+" be "+txt3->text()+"\n";


    QTextStream out(&file);
    QTextStream out1(&file1);
    QTextStream out2(&file2);
    inp<<p;
    inp1<<p;
    out2 <<" "<<txt1->text()<<" "<<txt1->text()<<"p"<<" "<<txt1->text()<<"p1"<<" ";
    out << f;
    out1<< k;
    k=k+"\n";
    QWidget *masage=new QWidget();
    QLabel *labl=new QLabel("information saved sucsesfuly");
    QPushButton *Ok=new QPushButton("Ok");
    QVBoxLayout *m=new QVBoxLayout();
    m->addWidget(labl);
    m->addWidget(Ok);
    masage->resize(400,100);
    Ok->resize(20,10);
    masage->setLayout(m);
    masage->show();
    file.close();
    file1.close();
    file2.close();
    connect(Ok,SIGNAL(clicked()),masage,SLOT(close()));
    connect(Ok,SIGNAL(clicked()),wnew,SLOT(close()));
}
    else
    {
        QWidget *masag=new QWidget();
        QLabel *labl=new QLabel("fight nuber is wring pleas chang that");
        QPushButton *Ok=new QPushButton("Ok");
        QVBoxLayout *m=new QVBoxLayout();
        m->addWidget(labl);
        m->addWidget(Ok);
        masag->resize(400,100);
        Ok->resize(20,10);
        masag->setLayout(m);
        masag->setWindowTitle("Masage");
        masag->show();
        connect(Ok,SIGNAL(clicked()),masag,SLOT(close()));

    }


}
MainWindow::~MainWindow()
{

}
