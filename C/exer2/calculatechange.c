/***************************
 * Created on 7 Apr 2020
 * Name : Kim Doy
 ***************************/

#include <stdio.h>

int main(void){
	int price, received;
	int change;

	printf("Price: ");
	scanf("%d", &price);
	
	printf("Received: ");
	scanf("%d", &received);
	
	change = received - price;

	printf("Change\n");
	
	printf("50000: %d, ", change/50000);
	change %= 50000;
	printf("10000: %d, ", change/10000);
	change %= 10000;
	printf("5000: %d, ", change/5000);
	change %= 5000;
	printf("1000: %d, ", change/1000);
	change %= 1000;
	printf("500: %d, ", change/500);
	change %= 500;
	printf("100: %d\n", change/100);

	return 0;

}
