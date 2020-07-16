/***************************
 * created on 7 Apr 2020
 * Name : Kim Doy 
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
