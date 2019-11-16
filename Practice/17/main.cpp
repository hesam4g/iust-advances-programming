#include <QtCore/QCoreApplication>
#include "matrix.h"
#include<cstdlib>
#include<conio.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Matrix m1;
    Matrix m2(3,4);
    cout << m1 << endl << m2 << endl;
    return a.exec();
}
