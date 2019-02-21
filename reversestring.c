#include <stdio.h>
#include <conio.h>
#include <string.h>

void rev(char str[50]);

int main(){
	char str1[50];
	clrscr();
	printf("Enter string.\n");
	gets(str1);
	//User defined reverse function
	rev(str1);

	getch();
	return 0;
}
void rev(char str[50]){
	int i,noa=0,j=0;
	char rev[50];

	for(i=0;str[i]!='\0';i++)
		noa++;


	for(i=noa-1;i>=0;i--){
		rev[j]=str[i];
		j++;
	}
	rev[j]='\0';
	puts(rev);
}
