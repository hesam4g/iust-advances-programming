#include<iostream>
#include<string>
using namespace std;

int main()
{
	cout<<"\t\t be name khaleghe ESHGH \t\t"<<endl<<endl;
	string name,firstName,lastName;
	cout<<"please enter your first name : ";
	cin>>firstName;
	cout<<"please enter your last name : ";
	cin>>lastName;
	name = firstName +" "+ lastName;
	cout<<"salam "<<name<<endl;
	int javab = 38,yourGuess = 0;
	cout<<"lotfan yek adad beine 1 ta 100 hads bezan : ";
	while (javab != yourGuess)
	{
		cin>>yourGuess;
		if(yourGuess > javab)
		{cout<<"lotfan yek adade koochooloo tar!!!"<<endl;}
		if(yourGuess < javab){cout<<"lotfan ye adade gonde tar!!!"<<endl;}
	}
	cout<<"your guess is true!!"<<endl<<endl<<"GAME OVER!"<<endl;
}