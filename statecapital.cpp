//StateCapital
#include <iostream.h>
#include <conio.h>
#include <fstream.h>
#include <stdio.h>
#include <string.h>

void main(){
	char str[50];
	int i,j;
	clrscr();

	//Create and adding details to state and capital files
	ofstream foutc("Capital");
	ofstream fouts("State");
	cout<<"Enter name of 5 states and their capital.\n";
	for(i=0;i<5;i++){
		cout<<"\nEnter state : ";
		gets(str);
		fouts<<str<<endl;

		cout<<"\nEnter capital : ";
		gets(str);
		foutc<<str<<endl;

		clrscr();
	}
	fouts.close();
	foutc.close();

	//Output
	ifstream fins("State");
	ifstream finc("Capital");

	gotoxy(10,1);
	cout<<"State";
	gotoxy(25,1);
	cout<<"Capital	\n";
	for(i=0;i<40;i++){
		cout<<"_";
	}
	for(i=3;i<=7;i++){

		fins.getline(str,50);
		gotoxy(10,i);
		cout<<str;

		finc.getline(str,50);
		gotoxy(25,i);
		cout<<str;

	}
	finc.close();
	fins.close();


	getch();
}


