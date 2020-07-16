/*
 * Student No. 1815364
 * Name. Kim Doy 
 * Mission 1 : Return Median 
 * Location : exer7/t1.c
 */

#include <stdio.h>

int get_median(int x, int y, int z);

int main(void){

	int a,b,c;
	printf("Enter 3 numbers : ");
	scanf("%d %d %d", &a, &b, &c);

	printf("Median = %d\n", get_median(a, b, c));
	
	return 0;
}
//중앙값 구하는 함수 정의
int get_median(int x, int y, int z){
	int max,min,median;
	
	max = (x>y)?(x>z?x:z):(y>z?y:z);
	min = (x<y)?(x<z?x:z):(y<z?y:z);

	median = (x < max && x > min)?x:((y < max && y > min)?y:z);

	return median;
}

