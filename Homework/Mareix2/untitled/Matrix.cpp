#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int **mat1;
    int **mat2;
    int **result;
    int row,col;
    cout<<"Please enter row/col"<<endl;
    cin>>row>>col;

    mat1 = new int *[row];
    mat2 = new int *[row];
    result = new int*[row];
    int k,i,j;

    for(k=0; i<row; k++)
        mat1[k] = new int[col];
        mat2[k] = new int[col];
        result[k] = new int[col];

            for (i=0; i<row; i++)
               for (j=0; j<col; j++)
                   for (j=0; j<row; j++)
                       for(i=0; i<col; i++)
                           result[i][k] += (mat1 [i][k] * mat2[k][j]);
    cout<<setw(4)<<result[i][k];
    return 0;
}
