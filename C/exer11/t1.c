/*
 * Student No. 1815364
 * Name. Kim Doy
 * -------------------
 * exer11/t1.c
 */


#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]){

	if(argc == 1)
		printf("No argument.\n");

	else{
		for(int i = 1; i < argc; i++){
			printf("arg%d: %s, %ld\n",i, argv[i], strlen(argv[i]));
		}
	
	}

	return 0;
}
