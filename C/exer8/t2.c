/*
 * Student No. 1815364
 * Name. Kim Doy
 *
 * exer8/t2.c
 * 거스름돈 구하기, call by reference 함수 이용
 */

#include <stdio.h>

void change(int price, int paid, int *b50000, int *b10000, int *b5000, int *b1000, int *b500, int *b100);

int main(void){
	
	int price, paid;
	int c50000, c10000, c5000, c1000, c500, c100;

	printf("Price: ");
	scanf("%d", &price);
	printf("Received: ");
	scanf(" %d", &paid);

	change(price, paid, &c50000, &c10000, &c5000, &c1000, &c500, &c100);
	
	printf("\nChange\n");
	printf("50000 : %d, 10000: %d, 5000: %d, 1000: %d, 500: %d, 100: %d\n", c50000, c10000, c5000, c1000, c500, c100);
		
	return 0;
}

void change(int price, int paid, int *b50000, int *b10000, int *b5000, int *b1000, int *b500, int *b100){

	int diff;
	diff = paid - price;
	
	*b50000 = diff / 50000;
	diff %= 50000;
	*b10000 = diff / 10000;
        diff %=  10000;
	*b5000 = diff / 5000;
        diff %= 5000;
        *b1000 = diff / 1000;
        diff %=  1000;
	*b500 = diff / 500;
        diff %= 500;
        *b100 = diff / 100;
        diff %=  100;


}

