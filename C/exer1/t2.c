/***************************
 * Student Number : 1815364
 * Name : Kim Doy
 ---------------------------
 * 실습 1 : exer1/t2.c
 * created on Tue 31 Mar 2020
 ***************************/


#include <stdio.h>

int main(void){
	//두개의 정수를 입력받아 사칙연산 계산 결과를 출력
	int a, b;
	printf("Enter two integers : ");
	scanf("%d %d", &a, &b);
	printf("%3d+%3d=%6d\n", a, b, a+b);
	printf("%3d-%3d=%6d\n", a, b, a-b);
	printf("%3d*%3d=%6d\n", a, b, a*b);
	printf("%3d/%3d=%6d\n", a, b, a/b);


	return 0;
}
