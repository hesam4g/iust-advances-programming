//i write this code with qt creature
#include<iostream>
using namespace std;
#ifndef MATRIX_H
#define MATRIX_H
//in this file i define a class and declare it's attribute

class matrix
{
    int cols;
    int rows;
    int** m;
    public:
        //default constructor
    matrix(): rows(1),cols(1){}
        //constructor that give two argumans (rows and cols)
        matrix(int,int);
        //copy constructor
        matrix(const matrix &);
        //set value of m[int][int]
        void setMatrixValue(int,int,int);
        //print value of m[int][int]
        int showMatrixValue(int,int);
        //declare two friend function that overloaded operators << and >>
        friend istream& operator >> (istream& R,matrix& M1);
        friend ostream& operator << (ostream& R,matrix& M1);

};

#endif // MATRIX_H
