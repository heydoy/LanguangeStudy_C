/*
 * Student No. 1815364
 * Name. Kim Doy
 * exer9/t2.c
 * 배열에서 찾는 수가 몇번째인지 출력
 */

#include <stdio.h>

int find(int *a, int size, int k);

int main(void){
	
	int x[10] = {45, 10, 23, 11, -3, 31, 56, 32, 55, -21};
	int number;
	int result;
	
	//int *p = &x[0];

	printf("What are you looking for? : ");
	scanf("%d", &number);

	result = find(x, 10, number);
	//result = find(p, 10, number);

	if(result == -1)	printf("Not found\n");
	else			printf("Index : %d\n", result );
	
		
	return 0;
}

int find(int *a, int size, int k){
	
	for(int i = 0; i < size ; i++){
		if( *(a+i) == k )	
			return i;
	}
	return -1;
};
