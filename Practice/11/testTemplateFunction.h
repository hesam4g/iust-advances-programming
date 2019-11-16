#ifndef TESTTEMPLATEFUNCTION_H
#define TESTTEMPLATEFUNCTION_H

#include<QDebug>

template<class T>
void swap(T& a,T& b)
{
    T c = a;
    a = b;
    b = c;
}

#endif // TESTTEMPLATEFUNCTION_H
