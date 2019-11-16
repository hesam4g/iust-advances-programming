#include "matrix.h"
#include<iostream>

using namespace std;

Matrix::Matrix()
{
    row = col = 2;
    size = col*row;
    m = new(int *[2]);
    for(int i=0 ; i<=1 ; i++)
    {
        for(int j=0 ; j<=1 ; j++)
        {
            m[i][j] = i + j;
        }
    }
}


Matrix::Matrix(int r,int c)
{
    row = r;
    col = c;
    size = row*col;
    m = new (int *[row]);
    for (int i = 0;i<=row;i++)
    {
        m[i] = new int [col];
    }
    for (int j=0;j<row;j++){
        for (int k =0;k<col;k++){
            m[j][k] = j+k;
        }
    }
}

ostream &operator <<(ostream& o,Matrix& m1)
{
    for (int j=0;j<m1.row;j++){
        for (int k =0;k<m1.col;k++)
        {
            o<<m1.m[j][k]<<" ";
        }
        o<<endl;
    }
    return o;
}
