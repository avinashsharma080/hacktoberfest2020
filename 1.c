#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int stringMatch(char str[],char pat[]){
	int n,m,i,j;
   
	n=strlen(str);
	m=strlen(pat);
	for(i=0;i<=n-m;i++){
		j=0;
		while(j<m && pat[j]==str[i+j]){
			j++;
			if(j==m)
				return i;
		}
	}
	return -1;
}

int main(){
	char str[100];
	char pat[100];
	int m;

	printf("Enter the string:");
	gets(str);
	printf("Enter the pattern:");
	gets(pat);
	m=stringMatch(str,pat);

	if(m>=0)
		printf("Pattern found at %d",m);
	else
	    printf("Pattern not found");

	return 0;
}
