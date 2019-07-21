/*  9 7 5 3 1 3 5 7 9
     7 5 3 1 3 5 7
      5 3 1 3 5
       3 1 3
        1
 */
 
#include <iostream.h>
#include <conio.h>

void main(){
	int i,j,n=9,nol,nos=0; // i,j row/column, n : 1st number for each row
			// nol : pattern
			// nos : number of space
	clrscr();
		for(i=1;i<=5;i++){
			nol=n;
			//Spacing
			for(i=1;i<=nos;i++)
				cout<<"\t";

			//phase1 loop //decrement
			while(nol>0){
				cout<<nol<<"\t";
				nol=nol-2;
			}

			nol=nol+4; //Dirty fix, first digit before increment

			//phase2 loop //increment
			while(nol<=n){
				cout<<nol<<"\t";
				nol=nol+2;
			}

			cout<<"\n";
			n=n-2;
			nos++;

		}



	getch();
}
