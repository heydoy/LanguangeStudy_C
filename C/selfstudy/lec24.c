/*
 * 실행할 때 인자 넣기
 */

#include <stdio.h>

int main(int argc, char *argv[]){
	
	printf("argc = %d\n",argc); 
	//printf("argv[0] = %s\n",argv[0]);
	//printf("argv[1] = %s\n", argv[1]);
	for(int i = 0; i < argc ; i++)
		printf("argv[%d] = %s\n", i, argv[i]);
	return 0;
}
