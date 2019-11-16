#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

using namespace std;

class Matrix
{
    ostream friend &operator <<(ostream& , Matrix&);
private:
    int **m;
    int row,col,size;

public:
    Matrix();
    Matrix(int,int);
    Matrix(Matrix &);
    void operator = (const Matrix &);
    bool operator == (const Matrix &);
    Matrix& operator + (const Matrix &);
    Matrix& operator - (const Matrix *);
};

#endif // MATRIX_H
