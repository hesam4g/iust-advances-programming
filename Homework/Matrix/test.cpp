#include<iostream>
using namespace std;
//calling class and make object from it
#include "matrix.h"
#include "matrix.cpp"
int main()
{
    matrix M1;
    matrix M2(2,3);
    matrix M3 (M2);
    //using operator << and >>
    cin>>M1;
    cout<<M2;
    cout<<M1<<endl<<M3;
    return 0;
}

