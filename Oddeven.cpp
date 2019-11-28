#include <iostream>
#include <fstream>
#include<conio.h>


using namespace std;

int main(){
    int i,n;
    system("cls");

    //Entering numbers
    cout<<"Enter 10 numbers.\n";
    ofstream fout("Numbers");
    for(i=0;i<10;i++){
        cin>>n;
        fout<<n<<endl;
    }
    fout.close();


    //Managing odd or even
    ofstream feven("Even");
    ofstream fodd("Odd");
    ifstream fin("Numbers"); 
    for(i=0;i<10;i++){
        fin>>n;
        if(n%2==0)
            feven<<n<<endl;
        else
            fodd<<n<<endl;
    }
    feven.close();
    fodd.close();
    fin.close();

    //Printing all files
    ifstream foutz("Numbers");
    ifstream foutx("Even");
    ifstream foutc("Odd");

    cout<<"\nContents of file 'Numbers' are: \n";
    while(foutz){
        foutz>>n;
        cout<<n<<endl;
    }
    cout<<"\nContents of file 'Even' are: \n";
    while(foutx){
        foutx>>n;
        cout<<n<<endl;
    }
    cout<<"\nContents of file 'Odd' are: \n";
    while(foutc){
        foutc>>n;
        cout<<n<<endl;
    }
    foutz.close();
    foutx.close();
    foutc.close();
    
    return 0;
}
