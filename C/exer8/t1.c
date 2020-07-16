/*
 * Student No. 1815364
 * Name. Kim Doy 
 *
 * exer8/t1.c
 * 양의 약수 구하기, 포인터활용
 */

#include <stdio.h>

int main(void){
	int num, *p;
	p = &num;

	int divisor, *q;
	q = &divisor;
	*q = 0;

	while(1){
		printf("Enter a positive integer : ");
		scanf("%d", p);

		if(*p <= 0)	printf("Error!\n");
		else		break;
	}

	for(int i = 1; i <= *p ; i++){
		if( *p % i == 0)	*q = *q +1;
	} 
	
	printf("The number of divisors is %d\n",*q);
	return 0;
}
