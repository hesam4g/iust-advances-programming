#include <QTextBlock>
#include "mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QString>

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{


    QVBoxLayout *v = new QVBoxLayout(this);
    QHBoxLayout *h1 = new QHBoxLayout();

    QTextEdit *text=new QTextEdit;
    QHBoxLayout *h = new QHBoxLayout();

    v->addLayout(h);
    _text=text;
    _text->setText(QString::fromUtf8("به سیستم آموزش دانشگاه خوش آمدید.\nبرای شروع کار بر روی دکمه های بالا کلیک کنید."));

    QPushButton * profile =new QPushButton(QString::fromUtf8("مشخصات"));
    QPushButton * akhz=new QPushButton(QString::fromUtf8(" اخذ واحد "));
    h1->addWidget(profile);
    h1->addWidget(akhz);
    v->addLayout(h1);

    QHBoxLayout *h2 = new QHBoxLayout();

    QPushButton * lessons =new QPushButton(QString::fromUtf8(" دروس "));
    QPushButton * marks =new QPushButton(QString::fromUtf8(" نمرات "));
    h2->addWidget(lessons);
    h2->addWidget(marks);
    v->addLayout(h2);

    QHBoxLayout *h3 = new QHBoxLayout();

    QPushButton * khoorooj =new QPushButton(QString::fromUtf8(" خروج "));
    h3->addWidget(khoorooj);
    v->addLayout(h3);

    QHBoxLayout *h4= new QHBoxLayout();

    h4->addWidget(text);
    v->addLayout(h4);

    setLayout(v);
    connect(profile, SIGNAL(clicked()),this,SLOT(profileClick()));
    connect(akhz, SIGNAL(clicked()),this,SLOT(akhzClick()));
    connect(lessons, SIGNAL(clicked()),this,SLOT(lessonsClick()));
    connect(marks, SIGNAL(clicked()),this,SLOT(marksClick()));
    connect(khoorooj, SIGNAL(clicked()),this,SLOT(khooroojClick()));



}

void MainWindow::profileClick()
    {

    _text->setText(QString::fromUtf8("نام: امین\nنام خانوادگی: فلاحی\nشماره ی دانشجویی: ۸۹۵۲۱۳۰۲\nدانشکده: مهندسی کامپیوتر\nرشته و گرایش: مهندسی کامپیوتر، نرم افزار"));
    }
void MainWindow::akhzClick()
    {

    _text->setText(QString::fromUtf8("دروس قابل اخذ:\nساختمان داده\nمهندسی نرم افزار ۱\nریاضیات مهندسی"));
    }
void MainWindow::lessonsClick()
    {

    _text->setText(QString::fromUtf8("دروس اخذ شده:\nریاضی عمومی ۲\nفیزیک ۲\nآمار و احتمالات مهندسی\nبرنامه سازی پیشرفته"));
    }
void MainWindow::marksClick()
    {

    _text->setText(QString::fromUtf8("نمرات:\nریاضی عمومی ۱: ۱۰\nفیزیک ۱: حذف اضطراری\nمبانی کامپیوتر و برنامه سازی: ۰\nتاریخ تحلیلی صدر اسلام: ۱۵"));
    }
void MainWindow::khooroojClick()
    {

    exit(0);
    }



MainWindow::~MainWindow()
{


}
