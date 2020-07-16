/*
 * Name. Kim Doy
 * exer10/t1.c
 * : string slicing
 */

#include <stdio.h>

int main(void){
	
	char *s = "I am a girl. You are a boy.";
	int i = 0;

	while(s[i] != NULL){
		printf("%c", s[i]);
		if(s[i] == ' ')
			printf(" ");
		i++;
	}
	printf("\n");

	return 0;
}
