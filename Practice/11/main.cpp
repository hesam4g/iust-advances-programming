#include <QtCore/QCoreApplication>
#include<testTemplateFunction.h>
#include<AList.h>

template<class A,class B>
void append(A& a,const B& b)
{

}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    int a = 10;
    int b = 20;
    qDebug() << a << b;
    swap(a,b);
    qDebug() << a << b;
    qDebug() << "-------------------------------";
    float d1 = 0.2;
    float d2 = 0.4;
    qDebug() << d1 << d2;
    swap(d1,d2);
    qDebug() << d1 << d2;
    qDebug() << "-------------------------------";
    append(a,d1);
    qDebug() << a << d1;
    return app.exec();
}
