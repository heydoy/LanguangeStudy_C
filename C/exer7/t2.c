/*
 * Student No. 1815364
 * Name. Kim Doy 
 * Mission 2 : Return sum of two primes 
 * Location : exer7/t2.c
 */

#include <stdio.h>
#include <stdlib.h>

int is_prime(int x);
void print_sum(int y);

int main(void){
	
	int a;

	while(1){
		printf("Enter an even number greater than 2: ");
		scanf("%d", &a);
		
		if(a <=  2)	printf("Not greather than 2!\n");
		else if(a % 2)	printf("Not even number!\n");
		else	break;
	}

	print_sum(a);

	return 0;
}
//소수인지를 판별하는 함수 정의
int is_prime(int x){
	
	for(int i = 2; i < x; i++){
		if( x % i == 0)	
			return 0;
	}
	return 1;	
	
}
//입력받은 4이상의 짝수를 두개의 소수 합으로 출력해주는 함수 정의
void print_sum(int y){
	
	// 2부터 소수이므로, 2부터 시작
	for(int i = 2; i < y-1 ; i++){
		for(int j = 2; j < y-1; j++){
			
			if(i+j == y){
				if(is_prime(i) && is_prime(j)){
					printf("%d+%d\n", i, j);
					exit(0);					
				}
			}
		}
	}
}
