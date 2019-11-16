#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
const int key=0x1f;
//key ro sabet dar nazar gereftam!!
int main()
{
	string s,d;
	int a;
	FILE *p;
	//fileE ke mikhaim baz konim p dar nazar migiram
	p=fopen("in.txt","r");
	d=getc(p);
	//file ra b surate string dar miavaraim
	for(int i=0;i<d.size();i++)
	{
		a=(int)d[i]^key;
		cout<<(char)a;
	}
	fclose(p);
	cout<<endl;
	return 0;
}