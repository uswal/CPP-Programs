#include <iostream.h>
#include <conio.h>
#include <stdio.h>	//rename,remove
#include <string.h>
//#include <iomanip.h>
//#include <dos.h>
#include <stdlib.h>
#include <ctype.h>
#include <fstream.h>
#include <time.h>

//Home
void WelcomePage();

//Add Customer
void OptionAddCust();

//Transaction
void OptionTransaction();

//Display Particular
void DisplayParticular();

//Display All
void DisplayAll();

//Misc
void CommonKeyHUD();
void CommonKey(char key);

class Account{
	private:
		char NameC[20],DOOC[12],AccNoC[12],OBalC[12],ContactC[12],AccTypeC[12],BalanceC[12];
	public:
		void AddCustomer(){
			char AccNoT[12],FPointer[40];
			char integer[]={'0','1','2','3','4','5','6','7','8','9'};
			int i,j,n;
			long int IntAccNo=0;
			char d='g',t;
			char cdate[9];
			gotoxy(1,4);

		//----------- Current date stuffs ---------
			_strdate(cdate); //format:[mm:dd:yy]
			
			//changing to format; [dd:mm:yy]
			t=cdate[0];
			cdate[0]=cdate[3];
			cdate[3]=t;
			
			t=cdate[1];
			cdate[1]=cdate[4];
			cdate[4]=t;
			
			strcpy(DOOC,cdate);
			
		//----------- Current date end --------------
		
		//######### Account number generater
			ifstream finag("LIST"); //finag - file input account genenerator

			while(finag){
				finag.getline(AccNoT,12); //stupid way - FAILED! to get 'long int' directly for our last account, pointer was stuck
	
				for(i=0;i<6;i++){
					if(finag.eof())
						break;
					finag.getline(FPointer,40);
					strcpy(AccNoC,AccNoT);
				}
			}
			finag.close();
			
			
			//Very own string to integer converter? XD
			for(i=0;AccNoC[i]!='\0';i++){
				for(j=0;;j++){
					if(AccNoC[i]==integer[j]){
						n=j;
						break;
					}
				}
				IntAccNo=(IntAccNo*10)+n;
			}
			
			IntAccNo=IntAccNo+1;
			
			
		//********

			//FileHandling
			fstream fout;
			fout.open("LIST",ios::app);
			
			//Record formatting in file : AccNo
										//Balance
										//AccType
			
			
			cout<<"Date Of Opening [DD-MM-YY] : "<<DOOC<<"\n";
			
			cout<<"Account Number : "<<IntAccNo<<"\n\n";
			
			cout<<"Enter Account Type [General/Saving] : ";
			gets(AccTypeC);
				
			cout<<"Enter Customer Name : ";
			gets(NameC);
			
			cout<<"Enter Opening Balance : ";
			gets(BalanceC);
			
			cout<<"Enter Contact number : ";
			gets(ContactC);
			
		
			d='n';
			cout<<"\n\nDo you wish to add this to the record? Press <Y/N> : ";
			cin>>d; 
		
			if(d == 'Y' || d == 'y' ){
				fout<<IntAccNo<<endl;
				fout<<NameC<<endl;
				fout<<AccTypeC<<endl;
				fout<<BalanceC<<endl;
				fout<<ContactC<<endl;
				fout<<DOOC<<endl;
				fout<<"***************"<<endl;
				cout<<"\nRecord added succesfully";
			}
			else
				cout<<"\nRecord addition cancelled";
				
			//########
			fout.close();
			
		}
};

void main(){
	clrscr();
	textbackground(WHITE);
	
	for(;;){
		//PageManager
		WelcomePage();

		//Hud kinda stuffs
		CommonKeyHUD();
	}
	
	//getch();
}

void WelcomePage(){
	clrscr();
	char Key;
	
	gotoxy(30,4);
	textcolor(YELLOW);
	cprintf("Central Bank Of India");

	gotoxy(37,6);
	textcolor(RED);
	cprintf("MAIN MENU");

	gotoxy(33,10);
	textcolor(BLUE);
	cprintf("1. Add Customer");
	
	gotoxy(34,12);
	cprintf("2. Transaction");
	
	gotoxy(31,14);
	cprintf("3. Display Particular");
	
	gotoxy(34,16);
	cprintf("4. Display All");

	gotoxy(37,18);
	cprintf("5. Exit");
	
	CommonKeyHUD();
	
	//getKeys
	
	Key=getch();
	Key=toupper(Key);
	
	for(;;){
		if(Key!='1' && Key!='2' && Key!='3' && Key!='4' && Key!='5' && Key!='E' && Key!='H' ){
			gotoxy(1,23);
			cout<<"[ Invalid key press! ]";
			Key=getch();
			Key=toupper(Key);
		}
		else
			break;
	}
	
	if(Key=='1')
		OptionAddCust();
	else
	if(Key=='2')
		OptionTransaction();
	else
	if(Key=='3')
		DisplayParticular();
	else
	if(Key=='4')
		DisplayAll();
	else
	if(Key=='5')
		exit(0);
	else
	CommonKey(Key);
		
}
//************************ Add Customer ************************
void OptionAddCust(){
	
	char Key;
	
	clrscr();
	gotoxy(1,1);
	cout<<"Add customer portal";
	
	//Calling add customer from class
	Account a;
	a.AddCustomer();

	gotoxy(1,23);
	cout<<"Press 'C' to add more customer!";
	CommonKeyHUD();
	
	Key=getch();
	Key=toupper(Key);
	
	for(;;){
		if(Key!='C' && Key!='H' && Key!='E'){
			gotoxy(1,22);
			cout<<"[ Invalid key press! ]";
			Key=getch();
			Key=toupper(Key);
		}
		else
			break;
	}
	
	if(Key=='C')
		OptionAddCust();
	else
		CommonKey(Key);
	
}
//######################## Add Customer ########################
//************************ Transaction **********************
void OptionTransaction(){
	
	char integer[]={'0','1','2','3','4','5','6','7','8','9'};
	int x=1,i,j,n,err=1;
	char AccNo[12],tstr[40],istr[12];
	char Key='A',d='a';
	long int res=0,inp;
	clrscr();
	
	cout<<"\n\n\nSearch account number : ";
	gets(istr);
	
	ifstream finz("LIST");
	ofstream foutz("LIST1"); //LIST1 is our temporary file
	
	while(finz){ //accno - name -type -bal -con -doo -stars
		//if(finz.eof()) //Didn't worked XDXD
			//break;
		
		finz.getline(AccNo,12);	//Accout Number
		if(!finz.eof())
			foutz<<AccNo<<endl;

		x=strcmp(AccNo,istr);

		finz.getline(tstr,40); //Name
		if(!finz.eof())
			foutz<<tstr<<endl;
		
		if(x==0)
			cout<<"\n\nName : "<<tstr;
		
		finz.getline(tstr,40);	//Type
		if(!finz.eof())
			foutz<<tstr<<endl;
		
		Key='A';
		finz.getline(tstr,40); //Balance 
		
		
		if(x!=0){
			if(!finz.eof())
				foutz<<tstr<<endl;
		}
		else{	//Withdraw/Deposit main part
			//cout<<"\nAccount found!\n";
			cout<<"\nCurrent Balance : "<<tstr;
			cout<<"\n\nD - Depoist	  W - Withdraw";
			
			Key=getch();
			Key=toupper(Key);
			if(Key!='D' && Key!='W'){
				//cout<<"\n\ni izz out";
				x=5;
				err=2;
				//getch();
				break;
			}
			//string to int
			for(i=0;tstr[i]!='\0';i++){
				for(j=0;;j++){
					if(tstr[i]==integer[j]){
						n=j;
						break;
					}
				}
				res=(res*10)+n;
			}
			//*
			if(Key=='D')
				cout<<"\n\n[Depositing]  ";
			else
				cout<<"\n\n[Withdrawing]  ";
			
			cout<<"Enter amount : ";
			cin>>inp;
			
			cout<<"\nConfirmation required!";
			cout<<"\nY - Yes     N - No";
			d=getch();
			d=toupper(d);
			if(d!='Y'){
				err=3;
				break;
			}
			
			if(Key=='W')
				res=res-inp;
			else
				res=res+inp;
			
			foutz<<res<<endl;	
			err=0;
		}//
		
		//con-doo-stars
		
		finz.getline(tstr,40);	//contact
		if(!finz.eof())
			foutz<<tstr<<endl;
		
		finz.getline(tstr,40);	//date of opening
		if(!finz.eof())
			foutz<<tstr<<endl;
		
		finz.getline(tstr,40);	//stars
		if(!finz.eof())
			foutz<<tstr<<endl;
		
		if(finz.eof())
			break;
		
		
	
	}
	finz.close();
	foutz.close();
	
	if(err==0){
		remove("LIST");
		rename("LIST1","LIST");
		cout<<"\n\nTransaction Successful!";
		cout<<"\nNewBalance : "<<res;
	}
	else
	if(err==1)
		cout<<"\n\nAccount not found!";
	else
	if(err==2)
		cout<<"\n\nTransaction failed!";
	else
	if(err==3)
		cout<<"\n\nTransaction cancelled!";
	else
		cout<<"\n\nUnexpected error!";
	
	//Messages afterwards
	cout<<"\n\nPress S to search more!";
	CommonKeyHUD();
	
	Key=getch();
	Key=toupper(Key);
	
	for(;;){
		if(Key!='S' && Key!='H' && Key!='E'){
			gotoxy(1,22);
			cout<<"[ Invalid key press! ]";
			Key=getch();
			Key=toupper(Key);
		}
		else
			break;
	}
	
	if(Key=='S')
		OptionTransaction();
	else
		CommonKey(Key);
	
	
}

//##################################### Transaction #########################
//***********************Display Particular***********************
void DisplayParticular(){
	char str[30],AccNoT[30],BalanceT[30],AccTypeT[30],NameT[30],DOOT[30],ContactT[30],BST[30]; 
	int x=5; 
	char Key;
	clrscr();
	
	cout<<"\n\n\nSearch account number : ";
	gets(str);

	ifstream fin1("LIST");
	
	//###
	while(fin1){ //acno,name,actpye,balance,contact,doo,bs
		
			fin1.getline(AccNoT,30);
			fin1.getline(NameT,30);
			fin1.getline(AccTypeT,30);
			fin1.getline(BalanceT,30);
			fin1.getline(ContactT,30);
			fin1.getline(DOOT,30);
			fin1.getline(BST,30);

			x = strcmp(AccNoT,str);
			
			if(x==0)
				break;
	}
	//***
	fin1.close();	
	
	if(x!=0)
		cout<<"\nAccount not found";
	else{
		cout<<"\n\n";
		cout<<"\nName            : "<<NameT;
		cout<<"\nAccount type    : "<<AccTypeT;
		cout<<"\nBalance         : "<<BalanceT;
		cout<<"\nDate of opening : "<<DOOT;
		cout<<"\nContact         : "<<ContactT;
	}
	
	cout<<"\n\nPress S to search more!";
	CommonKeyHUD();
	Key=getch();
	Key=toupper(Key);
	
	for(;;){
		if(Key!='S' && Key!='H' && Key!='E'){
			gotoxy(1,22);
			cout<<"[ Invalid key press! ]";
			Key=getch();
			Key=toupper(Key);
		}
		else
			break;
	}
	
	if(Key=='S')
		DisplayParticular();
	else
		CommonKey(Key);
}
//########################Display Particular ###################
//************************Display All***************************
void DisplayAll(){
	//acno-name-type-bal-con-doo
	char AccNoA[12],NameA[20],TypeA[12],BalA[12],ConA[12],DOOA[12],Stars[40];
	int i,y=2;
	char d;
	
	clrscr();
	
	
	gotoxy(1,1);
	textcolor(RED);
	cprintf("AccNo.");
	
	gotoxy(11,1);
	cprintf("Name");
	
	gotoxy(32,1);
	cprintf("AccType");
	
	gotoxy(42,1);
	cprintf("Balance");
	
	gotoxy(52,1);
	cprintf("Contact");
	
	gotoxy(65,1);
	cprintf("OpeningDate");
	
	
	cout<<endl;
	for(i=0;i<80;i++){
		cprintf("-");
	}
	
	textcolor(BLUE);
	ifstream fin2("LIST");
		while(fin2){
			y=3;
			//page changer till EOF with while
			//line changer
			for(y=3;y<21;y++){ 
				//row filler
					
						fin2.getline(AccNoA,12);
						fin2.getline(NameA,20);
						fin2.getline(TypeA,12);
						fin2.getline(BalA,12);
						fin2.getline(ConA,12);
						fin2.getline(DOOA,12);
						
						fin2.getline(Stars,40);
						
						gotoxy(1,y);
						cprintf(AccNoA);
	
						gotoxy(11,y);
						cprintf(NameA);
	
						gotoxy(32,y);
						cprintf(TypeA);
	
						gotoxy(42,y);
						cprintf(BalA);
	
						gotoxy(52,y);
						cprintf(ConA);
	
						gotoxy(65,y);
						cprintf(DOOA);
					
						if(fin2.eof())
							break;
			}
			if(y==21 && !fin2.eof()){
				gotoxy(1,25);
				cout<<"E - Exit Record Listing \t\t N - Next Page";
				d=getch();
				if(toupper(d)!='N')
					break;
				else{
					clrscr();
					gotoxy(1,1);
					textcolor(RED);
					cprintf("AccNo.");
	
					gotoxy(11,1);
					cprintf("Name");
	
					gotoxy(32,1);
					cprintf("AccType");
	
					gotoxy(42,1);
					cprintf("Balance");
	
					gotoxy(52,1);
					cprintf("Contact");
	
					gotoxy(65,1);
					cprintf("OpeningDate");
					
					cout<<endl;
					for(i=0;i<80;i++){
						cprintf("-");
					}
	
					textcolor(BLUE);
				}
	
			}
				
		}
	fin2.close();
	
	CommonKeyHUD();
	d=getch();
	d=toupper(d);
	
	for(;;){
		if(d!='H' && d!='E'){
			gotoxy(1,22);
			cout<<"[ Invalid key press! ]";
			d=getch();
			d=toupper(d);
		}
		else
			break;
	}
	
	CommonKey(d);
}
//########################Display All###########################
void CommonKey(char Key){
		
	gotoxy(1,1);
	
	if(Key=='E')
		exit(0);
	else
	if(Key=='H')
		WelcomePage();
	//else
		//cout<<"invalid keypress"; //TODO: Other key won't do anything
}

void CommonKeyHUD(){
	
	gotoxy(1,25);
	textcolor(BLUE);
	cprintf("E - Exit          H - Home                                  ");

}				
			
