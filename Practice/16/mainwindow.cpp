#include "mainwindow.h"
#include<QWidget>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QString>
#include<QLineEdit>
#include<QLabel>
#include<QPushButton>
#include<string>
#include<math.h>

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    QWidget *w = new QWidget(this);
    w->resize(600,150);
    QHBoxLayout *h1 = new QHBoxLayout();
    QHBoxLayout *h2 = new QHBoxLayout();
    QHBoxLayout *h3 = new QHBoxLayout();

    QVBoxLayout *v = new QVBoxLayout();

    QLabel *label1 = new QLabel("type your word             :");
    QLabel *label2 = new QLabel("your coded or decoded word :");

    text1 = new QLineEdit();
    text2 = new QLineEdit();

    QPushButton *p1 = new QPushButton("Code");
    QPushButton *p2 = new QPushButton("Decode");
    QPushButton *p3 = new QPushButton("Quit");

    h1->addWidget(label1);
    h1->addWidget(text1);
    h2->addWidget(label2);
    h2->addWidget(text2);
    h3->addWidget(p1);
    h3->addWidget(p2);
    h3->addWidget(p3);

    v->addLayout(h1);
    v->addLayout(h2);
    v->addLayout(h3);
    w->setLayout(v);

    connect(p1,SIGNAL(clicked()),this,SLOT(code()));
    connect(p2,SIGNAL(clicked()),this,SLOT(decode()));
    connect(p3,SIGNAL(clicked()),this,SLOT(quit()));

}

char MainWindow:: inttostr(long int a)
{
    if(a==0)return '0';
    if(a==8)return '1';
    if(a==16)return '2';
    if(a==24)return '3';
    if(a==32)return '4';
    if(a==40)return '5';
    if(a==48)return 'a';
    if(a==56)return 'b';
    if(a==64)return 'c';
    if(a==72)return 'd';
    if(a==80)return 'e';
    if(a==88)return 'f';
    if(a==96)return 'g';
    if(a==104)return 'h';
    if(a==112)return 'i';
    if(a==120)return 'j';
    if(a==128)return 'k';
    if(a==136)return 'l';
    if(a==144)return 'm';
    if(a==152)return 'n';
    if(a==160)return 'o';
    if(a==168)return 'p';
    if(a==176)return 'q';
    if(a==184)return 'r';
    if(a==192)return 's';
    if(a==200)return 't';
    if(a==208)return 'u';
    if(a==216)return 'v';
    if(a==224)return 'w';
    if(a==232)return 'x';
    if(a==240)return 'y';
    if(a==248)return 'z';
    return ' ';
}

int MainWindow::strtoint(char b,int k)
{

    if (b=='0' && k==0)
        return 0;
    if (b=='1' && k==0)
        return 8;
    if (b=='2' && k==0)
        return 16;
    if (b=='3' && k==0)
        return 24;
    if (b=='4' && k==0)
        return 32;
    if (b=='5' && k==0)
        return 40;
    if (b=='a' && k==0)
        return 48;
    if (b=='b' && k==0)
        return 56;
    if (b=='c' && k==0)
        return 64;
    if (b=='d' && k==0)
        return 72;
    if (b=='e' && k==0)
        return 80;
    if (b=='f' && k==0)
        return 88;
    if (b=='g' && k==0)
        return 96;
    if (b=='h' && k==0)
        return 104;
    if (b=='i' && k==0)
        return 112;
    if (b=='j' && k==0)
        return 120;
    if (b=='k' && k==0)
        return 128;
    if (b=='l' && k==0)
        return 136;
    if (b=='m' && k==0)
        return 144;
    if (b=='n' && k==0)
        return 152;
    if (b=='o' && k==0)
        return 160;
    if (b=='p' && k==0)
        return 168;
    if (b=='q' && k==0)
        return 176;
    if (b=='r' && k==0)
        return 184;
    if (b=='s' && k==0)
        return 192;
    if (b=='t' && k==0)
        return 200;
    if (b=='u' && k==0)
        return 208;
    if (b=='v' && k==0)
        return 216;
    if (b=='w' && k==0)
        return 224;
    if (b=='x' && k==0)
        return 232;
    if (b=='y' && k==0)
        return 240;
    if (b=='z' && k==0)
        return 248;
    if (b=='.' && k==0)
        return 0;
    if (b=='?' && k==0)
        return 0;
    if (b==' ' && k==0)
        return 0;


    if (b!=' ' && b !='.' && b !='?'){
        if (k==1)return strtoint(b,0)+2;
        if (k==2)return strtoint(b,0)+4;
        if (k==3)return strtoint(b,0)+6;
    }
    return 0;
}

void MainWindow::code()
{
    text1->setText("");
    char b[100];
    unsigned long int p=0;
    int count =1;
    QString s = text1->text(),d,f="";
    string a = s.toStdString();
    a=a+"h";
    for (int i=0;i<s.length();i++){
        if (a[i+1]==' ' )
             p=p+strtoint(a[i],1)*pow(256,count-1);
        if (a[i+1]=='.')
             p=p+strtoint(a[i],2)*pow(256,count-1);
        if (a[i+1]=='?')
             p=p+strtoint(a[i],3)*pow(256,count-1);
        if (a[i+1]!=' ' && a[i+1]!='.' && a[i+1]!='?')
             p=p+strtoint(a[i],0)*pow(256,count-1);
        if (count==4){
            itoa(p,b,10);
            d=QString(b);
            f=f+d;
            f=f+"  ";
            text2->setText(f);
            count=1;
            }
       else
           count++;
    }
    if (count !=1){
        p=strtoint(a[0],0);
        itoa(p,b,10);
        d=QString(b);
        f=f+d;
        text2->setText(f);}
}

void MainWindow::decode()
{

    char h[100];
    QString f="",w;
    long int e,b,c;
    QStringList k;
    QString a=text1->text(),m,l;
    a.replace("  "," ");
    k=a.split(" ");
    for(int i=0;i<k.length();i++){
        m=k[i];
        e=m.toInt();
        for(int j=0;j<4;j++){
             c=e%256;
             b=c%8;
             if(b==0)f.append(inttostr(c));
             if(b==2)f=f+inttostr(c-b)+" ";
             if(b==4)f=f+inttostr(c-b)+".";
             if(b==6)f=f+inttostr(c-b)+"?";
             e=e/256;
        }
    }
    text2->setText(f);
}


void MainWindow::quit(){
    exit(0);
}

MainWindow::~MainWindow()
{

}
