/***************************
* Created on 14 Apr 2020
* Name : Kim Doy
****************************/

#include <stdio.h>

int main(void){
	
	int integer;
	int digit = 0;

	printf("Enter an positive integer: ");
	scanf("%d", &integer);

	if(integer < 1000 && integer >0){
		printf("%d has ",integer);

		while(integer){
			integer/=10;
			digit++;
		}
	
		printf("%d digits\n",digit);
	}
	else printf("Error!\n");
	return 0;
}
