/***************************
 * 두개의 정수를 입력받아 사칙연산 계산 결과를 출력
 * Name : Kim Doy
 * created on Tue 31 Mar 2020
 ***************************/


#include <stdio.h>

int main(void){
	
	int a, b;
	printf("Enter two integers : ");
	scanf("%d %d", &a, &b);
	printf("%3d+%3d=%6d\n", a, b, a+b);
	printf("%3d-%3d=%6d\n", a, b, a-b);
	printf("%3d*%3d=%6d\n", a, b, a*b);
	printf("%3d/%3d=%6d\n", a, b, a/b);


	return 0;
}
