#ifndef ALIST_H
#define ALIST_H

#include<QDebug>
#define FSIZE 10

class IntFixedSizeList
{
public:
    intList()
    {
        for(int i=0,i<10,i++)
        {
            data[i] = 0;
        }
    }

    int& operator [](int index)
    {
        return data[index];
    }

private:
    int data(FSIZE);
};

void testLineList()
{
    IntFixedSizeList x;
    x[2] = 12;
    qDebug() << x[2] + x[3];
}

#endif // ALIST_H
