#include <stdio.h>
#include <conio.h>


int main(){
	int *ptr1,*ptr2;
	int mat1[10][10],mat2[10][10],res[10][10];
	int rw,cl,i,j;
	clrscr();
	printf("Enter number of rows and columns.\n");
	scanf("%d %d",&rw,&cl);

	printf("Enter elements of matrix 1.\n");
	for(i=0;i<rw;i++){
		for(j=0;j<cl;j++){
			printf("Enter element a%d%d : ",i+1,j+1);
			scanf("%d",&mat1[i][j]);
		}
		printf("\n");
	}

	printf("Enter elements of matrix 2.\n");
	for(i=0;i<rw;i++){
		for(j=0;j<cl;j++){
			printf("Enter element a%d%d : ",i+1,j+1);
			scanf("%d",&mat2[i][j]);
		}
		printf("\n");
	}

	//Adding matrices using pointers and printing result
	for(i=0;i<rw;i++){
		for(j=0;j<cl;j++){
			ptr1=&mat1[i][j];
			ptr2=&mat2[i][j];
			res[i][j]= *ptr1 + *ptr2;
			printf("%d \t",res[i][j]);
		}
		printf("\n");
	}
	getch();
	return 0;
}
