#include <iostream>
#include<conio.h>
#include<string>
#include<stdio.h>
using namespace std;
//in ghesmat az barname sabet key ra dar mabnate 16 tarif miconad
const int key=0x1f;
int main()
{
    string s,d;
    FILE *p;
    int c,a,i;
    // chon bray coding kardan va ham decod kardan ma bayad key ra ba vorudi xnor konim baraye hami nemiporsim cod dr decod
    cout<<"FILE or TEXT?(1/2)";
    cin>>c;
    if(c==2){
        cin>>s;
        cout<<"\n";
        for(i=0;i<s.size();i++)
        {
        //reshte vorudi ra bakhsh bakhsh karde bad kode ascii har codam ro ba ke xnor mikonad
        a=(int)s[i]^key;
        cout<<(char)a;
        }
    }
    else {
        //file file,txt ra baz mikone  bad etelaat dahklesh ra mikhanad bad karhayi ra ke baraye text karde bodim ra anjam midim
        p=fopen("in.txt","r");
        d=getc(p);
        for(i=0;i<d.size();i++)
        {
            a=(int)d[i]^key;
            cout<<(char)a;
        }
    fclose(p);
    }
    getch();
    return 0;
}
