#include "matrix.h"
#include<iostream>
using namespace std;
matrix::matrix(int r,int c)
{
    (rows)=(r);
    (cols)=(c);

    //make 2d matrix
    m=new int* [rows];
    for (int i=0;i<rows; i++)
    {
        m[i]=new int [cols];
    }


}
void matrix::setMatrixValue(int row,int col,int value)
{
    m[row][col]=value;
}
int matrix::showMatrixValue(int row,int col)
{
    return m[row][col];
}
matrix::matrix(const matrix& source)
{
    //this scope mean rows and cols of copy constructor is equal of arguman rows and cols
    rows=source.rows;
    cols=source.cols;

    m=new int*[rows];
    for (int j=0;j<rows; j++)
    {
        m[j]=new int [cols];
    }
}

//define operator >> and overloaded it
istream& operator >> (istream& R,matrix& M1)
{
    cout<<"Enter your rows"; R>>M1.rows;
    cout<<"Enter your cols"; R>>M1.cols;
    return R;
}

//define operator << and overloaded it
ostream& operator << (ostream& R,matrix& M1)
{
    R<<"rows:"<<M1.rows<<endl<<"cols:"<<M1.cols;
    return R;
}
