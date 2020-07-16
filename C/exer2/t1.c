/***************************
 * Student Number : 1815364
 * Name : Kim Doy
 ---------------------------
 * 실습 2 : exer2/t1.c
 * created on Tue 7 Apr 2020
 ***************************/

#include <stdio.h>

int main(void){
	int a;
	int reversal;
	
	printf("Enter a two-digit number: ");
	scanf("%d", &a);
	
	reversal = a/10 + a%10*10;
	
	printf("The reversal is %d\n",reversal);

}
