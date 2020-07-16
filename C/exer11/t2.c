/*
 * Student No. 1815364
 * Name. Kim Doy
 * -------------------
 * exer11/t2.c
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	char * p;
	char * search;
	p = (char *)malloc(sizeof(char)*32);
	search = (char *)malloc(sizeof(char)*2);

	printf("Enter a sentence: ");
	gets(p);
	
	printf("Enter a charcater to search: ");
	gets(search);

	printf("%1s found at index: ",search);

	
	
	for(int i = 0; p[i] != '\0' ; i++){
		if(search[0] == p[i])
		       printf("%d ",i);
	}
	printf("\n");
	
	free(p);
	free(search);

	return 0;
}
