#include "mainwindow.h"
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //setLayoutDirection(Qt::RightToLeft);
    QString title = QString::fromUtf8("سلام %1 %2");
    QString gender = QString::fromUtf8("خانم");
    QString userName = QString::fromUtf8("دانشجوی محترم");

    QString s = title.arg(gender).arg(userName);
    setWindowTitle(s);

    QWidget* w = new QWidget(this);
    w->resize(200,200);

    QLineEdit* text1 = new QLineEdit("");
    QPushButton* exitButton = new QPushButton(QString::fromUtf8("خروج از برنامه"));

    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(text1);
    layout->addWidget(exitButton);

    w->setLayout(layout);

}

MainWindow::~MainWindow()
{

}
