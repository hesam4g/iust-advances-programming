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
    QLabel *a = new QLabel("Welcome to Hesam Air Line");
    QPushButton *buy = new QPushButton("Buy a Ticket");
    QPushButton *cancel = new QPushButton("Cancel a Ticket (New)");
    QPushButton *seeAllPass = new QPushButton("See all passanger");
    QPushButton *seeAllFlight = new QPushButton("See all flight");
    QPushButton *seeFlightInfo = new QPushButton("See flight information");
    QPushButton *makeFlight = new QPushButton("Make a flight");
    QPushButton *editFlight = new QPushButton("Edit a flight");
    QPushButton *searchPass = new QPushButton("Search a passanger (Coming soon)");
    QPushButton *exit = new QPushButton("Exit");

    QWidget *w = new QWidget(this);
    w->setWindowTitle("Main part");
    w->resize(400,200);
    QHBoxLayout *h0 = new QHBoxLayout();
    QHBoxLayout *h1 = new QHBoxLayout();
    QHBoxLayout *h2 = new QHBoxLayout();
    QHBoxLayout *h3 = new QHBoxLayout();
    QHBoxLayout *h4 = new QHBoxLayout();
    QVBoxLayout *v = new QVBoxLayout();
    h0->addWidget(a);
    h0->setAlignment(Qt::AlignHCenter);
    h1->addWidget(buy);
    h1->addWidget(cancel);
    h1->addWidget(seeAllPass);
    h2->addWidget(seeAllFlight);
    h2->addWidget(seeFlightInfo);
    h3->addWidget(makeFlight);
    h3->addWidget(editFlight);
    h4->addWidget(searchPass);
    h4->addWidget(exit);
    v->addLayout(h0);
    v->addLayout(h1);
    v->addLayout(h2);
    v->addLayout(h3);
    v->addLayout(h4);
    w->setLayout(v);

    connect(buy,SIGNAL(clicked()),this,SLOT(buy()));
    connect(cancel,SIGNAL(clicked()),this,SLOT(cancel()));
    connect(seeAllPass,SIGNAL(clicked()),this,SLOT(seeAllPass()));
    connect(seeAllFlight,SIGNAL(clicked()),this,SLOT(seeAllFlight()));
    connect(seeFlightInfo,SIGNAL(clicked()),this,SLOT(seeFlightInfo()));
    connect(makeFlight,SIGNAL(clicked()),this,SLOT(makeFlight()));
    connect(editFlight,SIGNAL(clicked()),this,SLOT(editFlight()));
    connect(searchPass,SIGNAL(clicked()),this,SLOT(searchPass()));
    connect(exit,SIGNAL(clicked()),this,SLOT(close()));
}

void MainWindow::buy()
{
    QLabel *lb1 = new QLabel("First Name");
    QLabel *lb2 = new QLabel("Last Name");
    QLabel *lb3 = new QLabel("Passanger number");
    QLabel *lb4 = new QLabel("Nationality number");
    QLabel *lb5 = new QLabel("Flight number");
    QLabel *lb6 = new QLabel("How many ticket ?");
    QLabel *lb7 = new QLabel("Continuous ?");

    QLineEdit *t1=new QLineEdit();
    QLineEdit *t2=new QLineEdit();
    QLineEdit *t3=new QLineEdit();
    QLineEdit *t4=new QLineEdit();
    QLineEdit *t5=new QLineEdit();
    QLineEdit *t6=new QLineEdit();

    QRadioButton *r1=new QRadioButton("Yes");
    QRadioButton *r2=new QRadioButton("No");

    QPushButton *p1 = new QPushButton("Buy");
    QPushButton *p2 = new QPushButton("Back to main part");

    QHBoxLayout *hb1 = new QHBoxLayout();
    QHBoxLayout *hb2 = new QHBoxLayout();
    QHBoxLayout *hb3 = new QHBoxLayout();
    QHBoxLayout *hb4 = new QHBoxLayout();
    QHBoxLayout *hb5 = new QHBoxLayout();
    QHBoxLayout *hb6 = new QHBoxLayout();
    QHBoxLayout *hb7 = new QHBoxLayout();
    QHBoxLayout *hb8 = new QHBoxLayout();
    hb1->addWidget(lb1);
    hb1->addWidget(t1);
    hb2->addWidget(lb2);
    hb2->addWidget(t2);
    hb3->addWidget(lb3);
    hb3->addWidget(t3);
    hb4->addWidget(lb4);
    hb4->addWidget(t4);
    hb5->addWidget(lb5);
    hb5->addWidget(t5);
    hb6->addWidget(lb6);
    hb6->addWidget(t6);
    hb7->addWidget(lb7);
    hb7->addWidget(r1);
    hb7->addWidget(r2);
    hb8->addWidget(p1);
    hb8->addWidget(p2);

    QVBoxLayout *vb = new QVBoxLayout();
    vb->addLayout(hb1);
    vb->addLayout(hb2);
    vb->addLayout(hb3);
    vb->addLayout(hb4);
    vb->addLayout(hb5);
    vb->addLayout(hb6);
    vb->addLayout(hb7);
    vb->addLayout(hb8);

    QWidget *w = new QWidget();
    w->setWindowTitle("Buy Window");
    w->setLayout(vb);
    w->show();
    wbuy=w;
    radi=r1;
    txt21=t1;
    txt22=t2;
    txt23=t3;
    txt24=t4;
    txt25=t5;
    txt26=t6;
    connect(p1,SIGNAL(clicked()),this,SLOT(buyATicket()));
    connect(p2,SIGNAL(clicked()),w,SLOT(close()));
}

void MainWindow::buyATicket()
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
        if((txt26->text()).toInt()>z)
        {
            QWidget *w2=new QWidget();
            QPushButton *Ok2=new QPushButton("Ok");
            QLabel *lab2=new QLabel("Dont have enough chair ");
            QVBoxLayout *v2=new QVBoxLayout();
            v2->addWidget(lab2);
            v2->addWidget(Ok2);
            w2->resize(400,100);
            w2->setWindowTitle("Message");
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
                   w3->resize(400,100);
                   w3->setWindowTitle("Message");
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
                   w5->setWindowTitle("Message");
                   w5->setLayout(v5);
                   w5->resize(400,100);
                   w5->show();
                   connect(Ok5,SIGNAL(clicked()),w5,SLOT(close()));
                   connect(Ok5,SIGNAL(clicked()),wbuy,SLOT(close()));

                   in<<f<<"*\n"<<c;

               }
               else
                   {
                   QWidget *w4=new QWidget();
                   QPushButton *Ok4=new QPushButton("Ok");
                   QLabel *lab4=new QLabel("this passenger number dont right please change that");
                   QVBoxLayout *v4=new QVBoxLayout();
                   v4->addWidget(lab4);
                   v4->addWidget(Ok4);
                   w4->setWindowTitle("Message");
                   w4->setLayout(v4);
                   w4->resize(400,100);
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
                w5->setWindowTitle("Message");
                w5->setLayout(v5);
                w5->resize(100,100);
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
                w4->setWindowTitle("Message");
                w4->setLayout(v4);
                w4->resize(400,100);
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
        w1->resize(400,100);
        w1->show();
        connect(Ok1,SIGNAL(clicked()),w1,SLOT(close()));
    }
}

void MainWindow::cancel()
{
    QWidget *w = new QWidget;
    QHBoxLayout *l1 = new QHBoxLayout();
    QHBoxLayout *l2 = new QHBoxLayout();
    QPushButton *click1 = new QPushButton("Cancel");
    QPushButton *click2 = new QPushButton("Back to main part");
    QLabel *lable = new QLabel("please enter passenger number");
    QLineEdit *tc = new QLineEdit();
    l1->addWidget(lable);
    l1->addWidget(tc);
    l2->addWidget(click1);
    l2->addWidget(click2);
    txtcancel=tc;
    QVBoxLayout *v = new QVBoxLayout();
    v->addLayout(l1);
    v->addLayout(l2);
    w->resize(400,100);
    w->setLayout(v);
    w->setWindowTitle("Flight cancel");
    w6=w;
    w->show();
    connect(click1,SIGNAL(clicked()),this,SLOT(doCancel()));
    connect(click2,SIGNAL(clicked()),w,SLOT(close()));
}

void MainWindow::doCancel()
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
    QWidget *wcan = new QWidget();
    QLabel *lcan = new QLabel("Cancelled");
    QHBoxLayout *hcan = new QHBoxLayout(wcan);
    QPushButton *pcan = new QPushButton("ok");
    hcan->addWidget(lcan);
    hcan->addWidget(pcan);
    connect(pcan,SIGNAL(clicked()),wcan,SLOT(close()));
    wcan->resize(200,200);
    wcan->show();
    }

void MainWindow::seeAllPass()
{
    QLabel *lap1=new QLabel();
    QLabel *lap2=new QLabel("Pleas enter fight number");

    QPushButton *pap1=new QPushButton("See information");
    QPushButton *pap2=new QPushButton("Back to main part");

    QLineEdit *tap = new QLineEdit();

    QHBoxLayout *hap1 = new QHBoxLayout();
    QHBoxLayout *hap2 = new QHBoxLayout();
    QHBoxLayout *hap3 = new QHBoxLayout();
    QScrollArea *scroll = new QScrollArea();
    scroll->verticalScrollBar();

    hap1->addWidget(lap2);
    hap1->addWidget(tap);
    hap2->addWidget(pap1);
    hap2->addWidget(pap2);

    QVBoxLayout *vap = new QVBoxLayout();
    vap->addLayout(hap1);
    vap->addLayout(hap2);
    vap->addLayout(hap3);

    QWidget *w = new QWidget();
    w->resize(400,100);
    w->setLayout(vap);
    w->setWindowTitle("All pasenger");
    txtk=tap;
    w2=w;
    sco=scroll;
    vb=hap3;
    labn=lap1;
    w->show();
    connect(pap1,SIGNAL(clicked()),this,SLOT(seeAllPass1()));
    connect(pap2,SIGNAL(clicked()),w,SLOT(close()));
}

void MainWindow::seeAllPass1()
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
        w2->resize(300,300);
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

void MainWindow::seeAllFlight()
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

void MainWindow::seeFlightInfo()
{
    QLabel *lfi1 = new QLabel();
    QLabel *lfi2 = new QLabel("Please enter fight number");

    QLineEdit *tfi = new QLineEdit();

    QPushButton *pfi1 = new QPushButton("See information");
    QPushButton *pfi2 = new QPushButton("back to main part");

    QHBoxLayout *hfi1 = new QHBoxLayout();
    QHBoxLayout *hfi2 = new QHBoxLayout();
    QHBoxLayout *l1 = new QHBoxLayout();

    QScrollArea *scroll = new QScrollArea();

    hfi1->addWidget(lfi2);
    hfi1->addWidget(tfi);
    hfi2->addWidget(pfi1);
    hfi2->addWidget(pfi2);

    QWidget *w=new QWidget();
    w->resize(400,100);
    QVBoxLayout *vfi = new QVBoxLayout();
    vfi->addLayout(hfi1);
    vfi->addLayout(hfi2);
    vfi->addLayout(l1);
    w->setLayout(vfi);
    lab=lfi1;
    txt=tfi;
    sco1=scroll;
    vb1=l1;
    w->setWindowTitle("Fight information");
    w->show();
    w3=w;
    connect(pfi1,SIGNAL(clicked()),this,SLOT(information()));
    connect(pfi2,SIGNAL(clicked()),w,SLOT(close()));

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
        w3->resize(400,400);
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

void MainWindow::makeFlight()
{
    QLabel *lf1 = new QLabel("Flight number");
    QLabel *lf2 = new QLabel("Offset");
    QLabel *lf3 = new QLabel("Destination");
    QLabel *lf4 = new QLabel("How many row");
    QLabel *lf5 = new QLabel("How many chair in each row");

    QLineEdit *tf1 = new QLineEdit();
    QLineEdit *tf2 = new QLineEdit();
    QLineEdit *tf3 = new QLineEdit();
    QLineEdit *tf4 = new QLineEdit();
    QLineEdit *tf5 = new QLineEdit();

    QHBoxLayout *hf1 = new QHBoxLayout();
    QHBoxLayout *hf2 = new QHBoxLayout();
    QHBoxLayout *hf3 = new QHBoxLayout();
    QHBoxLayout *hf4 = new QHBoxLayout();
    QHBoxLayout *hf5 = new QHBoxLayout();
    QHBoxLayout *hf6 = new QHBoxLayout();

    QPushButton *pf1 = new QPushButton("Save");
    QPushButton *pf2 = new QPushButton("Cancel");

    hf1->addWidget(lf1);
    hf1->addWidget(tf1);
    hf2->addWidget(lf2);
    hf2->addWidget(tf2);
    hf3->addWidget(lf3);
    hf3->addWidget(tf3);
    hf4->addWidget(lf4);
    hf4->addWidget(tf4);
    hf5->addWidget(lf5);
    hf5->addWidget(tf5);
    hf6->addWidget(pf1);
    hf6->addWidget(pf2);

    QVBoxLayout *vf = new QVBoxLayout();
    vf->addLayout(hf1);
    vf->addLayout(hf2);
    vf->addLayout(hf3);
    vf->addLayout(hf4);
    vf->addLayout(hf5);
    vf->addLayout(hf6);

    QWidget *wf = new QWidget();
    wf->setWindowTitle("Make a flight");
    wf->setLayout(vf);
    wnew = wf;
    txt1=tf1;
    txt2=tf2;
    txt3=tf3;
    txt6=tf4;
    txt7=tf5;
    wf->show();
    connect(pf1,SIGNAL(clicked()),this,SLOT(save()));
    connect(pf2,SIGNAL(clicked()),wf,SLOT(close()));
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
    f="shomare parvaz : "+txt1->text()+"\n"+"mabda : "+txt2->text()+"\n"+"maghsad : "+txt3->text()+"\n"+"*\n\n";
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
    QWidget *massage=new QWidget();
    QLabel *labl=new QLabel("information saved sucsesfuly");
    QPushButton *Ok=new QPushButton("Ok");
    QVBoxLayout *m=new QVBoxLayout();
    m->addWidget(labl);
    m->addWidget(Ok);
    massage->resize(400,100);
    Ok->resize(20,10);
    massage->setLayout(m);
    massage->show();
    file.close();
    file1.close();
    file2.close();
    connect(Ok,SIGNAL(clicked()),massage,SLOT(close()));
    connect(Ok,SIGNAL(clicked()),wnew,SLOT(close()));
}
    else
    {
        QWidget *massage=new QWidget();
        QLabel *labl=new QLabel("fight nuber is wring pleas chang that");
        QPushButton *Ok=new QPushButton("Ok");
        QVBoxLayout *m=new QVBoxLayout();
        m->addWidget(labl);
        m->addWidget(Ok);
        massage->resize(400,100);
        Ok->resize(20,10);
        massage->setLayout(m);
        massage->setWindowTitle("Massage");
        massage->show();
        connect(Ok,SIGNAL(clicked()),massage,SLOT(close()));
    }
}

void MainWindow::editFlight()
{
    QLineEdit *tef = new QLineEdit();
    QLabel *lef =new QLabel("Enter flighr number ");
    QPushButton *pef1 = new QPushButton("Edit");
    QPushButton *pef2 = new QPushButton("Back to main part");

    QHBoxLayout *hef1 = new QHBoxLayout();
    QHBoxLayout *hef2 = new QHBoxLayout();
    hef1->addWidget(lef);
    hef1->addWidget(tef);
    hef2->addWidget(pef1);
    hef2->addWidget(pef2);

    QVBoxLayout *vef = new QVBoxLayout();
    vef->addLayout(hef1);
    vef->addLayout(hef2);

    QWidget *wef = new QWidget();
    wef->setLayout(vef);
    wef->setWindowTitle("Edit a flight");
    wef->show();
    txtedit = tef;
    connect(pef1,SIGNAL(clicked()),this,SLOT(editWindow()));
    connect(pef2,SIGNAL(clicked()),wef,SLOT(close()));
}

void MainWindow::editWindow()
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
        QLabel *lable6=new QLabel("How many rows? ");
        QLabel *lable7=new QLabel("How many chair in each row? ");
        b=k[1];
        QLineEdit *text2 = new QLineEdit(b.replace("mabda : ",""));
        b=k[2];
        QLineEdit *text3 = new QLineEdit(b.replace("maghsad : ",""));
        b=k[3];
        QLineEdit *text6 = new QLineEdit(b.replace("tedad radif : ",""));
        b=k[4];
        QLineEdit *text7 = new QLineEdit(b.replace("tedad sandali dar har radif : ",""));
        txt12=text2;
        txt13=text3;
        txt16=text6;
        txt17=text7;
        QPushButton *click=new QPushButton("Save changes");
        QPushButton *click1=new QPushButton("Cancel");
        QHBoxLayout *v1=new QHBoxLayout();
        QHBoxLayout *v2=new QHBoxLayout();
        QHBoxLayout *v3=new QHBoxLayout();
        QHBoxLayout *v6=new QHBoxLayout();
        QHBoxLayout *v7=new QHBoxLayout();
        QHBoxLayout *v8=new QHBoxLayout();
        v1->addWidget(lable1);
        v2->addWidget(lable2);
        v2->addWidget(text2);
        v3->addWidget(lable3);
        v3->addWidget(text3);
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
        h->addLayout(v6);
        h->addLayout(v7);
        h->addLayout(v8);
        w->setLayout(h);
        w->resize(200,400);
        w->show();
        connect(click,SIGNAL(clicked()),this,SLOT(saveEdit()));
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
        w2->setWindowTitle("Massage");
        w2->show();
        connect(Ok2,SIGNAL(clicked()),w2,SLOT(close()));

    }
}

void MainWindow::saveEdit()
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
    f="shomare parvaz : "+txtedit->text()+"\n"+"mabda : "+txt12->text()+"\n"+"maghsad : "+txt13->text()+"\n"+"tedad radif : "+txt16->text()+"\n"+"tedad sandali dar har radif : "+txt17->text()+"\n"+"*\n\n";

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
    masage->setWindowTitle("Masasge");
    masage->show();
    connect(Ok,SIGNAL(clicked()),masage,SLOT(close()));
    connect(Ok,SIGNAL(clicked()),w1,SLOT(close()));

}

void MainWindow::searchPass()
{
    QLabel *lsp = new QLabel("Please Enter passanger number or Name of passanger ");
    QLineEdit *tsp = new QLineEdit();

    QPushButton *psp1 = new QPushButton("Search a passanger by number");
    QPushButton *psp2 = new QPushButton("Search a passanger by Name ");
    QPushButton *psp3 = new QPushButton("Back to main part");

    QScrollArea *ssp =new QScrollArea();

    QHBoxLayout *hsp1 = new QHBoxLayout();
    QHBoxLayout *hsp2 = new QHBoxLayout();
    QHBoxLayout *hsp3 = new QHBoxLayout();
    QHBoxLayout *hsp4 = new QHBoxLayout();
    QHBoxLayout *hsp5 = new QHBoxLayout();

    hsp1->addWidget(lsp);
    hsp1->addWidget(tsp);
    hsp3->addWidget(psp1);
    hsp4->addWidget(psp2);
    hsp5->addWidget(psp3);

    QVBoxLayout *vsp = new QVBoxLayout();
    vsp->addLayout(hsp1);
    vsp->addLayout(hsp3);
    vsp->addLayout(hsp4);
    vsp->addLayout(hsp5);
    vsp->addLayout(hsp2);

    QWidget *wsp = new QWidget();
    wsp->setWindowTitle("Search a Passanger");
    wsp->setLayout(vsp);
    wsp->show();
    w4=wsp;
    txtinf=tsp;
    sco1inf=ssp;
    vbinf=hsp2;
    connect(psp1,SIGNAL(clicked()),this,SLOT(passWithNumber()));
    connect(psp2,SIGNAL(clicked()),this,SLOT(passWithName()));
    connect(psp3,SIGNAL(clicked()),wsp,SLOT(close()));
}

void MainWindow::passWithNumber()
{
    QFile file1("allpasengernumber.txt");
    file1.open(QIODevice::ReadOnly|QIODevice::Text);
    QString d=file1.readAll();
    if(d.indexOf((" "+txtinf->text()+" "))!=-1)
    {
        QString adress,d;
        adress = txtinf->text();
        adress = adress+".txt";
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

void MainWindow::passWithName()
{
    QFile file1("allpasenger.txt");
    file1.open(QIODevice::ReadOnly|QIODevice::Text);
    bool r=true;
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

   if(!r)
   {
       labinf->setText(c);
        sco1inf->setWidget(labinf);
        vbinf->addWidget(sco1inf);
        w4->resize(400,400);
    }
    else
    {
        QWidget *w5=new QWidget();
        QPushButton *Ok2=new QPushButton("Ok");
        QLabel *lab2=new QLabel("Pasenger namee is't found");
        QVBoxLayout *v2=new QVBoxLayout();
        w5->resize(400,75);
        v2->addWidget(lab2);
        v2->addWidget(Ok2);
        w5->setLayout(v2);
        w5->show();
        connect(Ok2,SIGNAL(clicked()),w5,SLOT(close()));
    }
}


MainWindow::~MainWindow(){}
