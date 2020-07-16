/*
 * Created on Jun 16, 2020
 * Name. Kim Doy
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
