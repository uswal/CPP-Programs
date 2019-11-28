/* Write a program to input 10 students records in a file named "STUDENTS"
   and print them in a tabular format. */

#include <iostream.h>
#include <fstream.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main(){
	char str[100],str1[50];
	char d;
	int i,j,x,y;
	clrscr();

	ofstream fout;
	fout.open("students",ios::out);
	for(i=0;;i++){
		cout<<"\t\tENTER\n\n";

		cout<<"Name : ";
		gets(str);

		cout<<"Class : ";
		gets(str1);
		strcat(str,",");
		strcat(str,str1);

		cout<<"Section : ";
		gets(str1);
		strcat(str,",");
		strcat(str,str1);

		cout<<"Roll : ";
		gets(str1);
		strcat(str,",");
		strcat(str,str1);

		cout<<"Course : ";
		gets(str1);
		strcat(str,",");
		strcat(str,str1);

		fout<<str<<endl;

		cout<<"\n\nDo you wish to enter more details <Y/N> : ";
		cin>>d;

		if(toupper(d)!='Y')
			break;
		clrscr();
	}
	fout.close();

	//output
	clrscr();
	gotoxy(1,1);
	cout<<"Name";
	gotoxy(16,1);
	cout<<"Class";
	gotoxy(31,1);
	cout<<"Section";
	gotoxy(46,1);
	cout<<"Roll";
	gotoxy(61,1);
	cout<<"Course";
	gotoxy(1,2);
	for(i=0;i<75;i++){
		cout<<"-";
	}

	ifstream fin("students");
	y=3;
	for(i=0;i<20;i++){
		fin.getline(str,100);
		x=1;
		gotoxy(x,y);

		for(j=0;str[j]!='\0';j++){
			if(str[j]!=',')
				cout<<str[j];
			 else{
				x=x+15;
				gotoxy(x,y);
			 }

		}
		y++;
	}
	fin.close();


	getch();
}
