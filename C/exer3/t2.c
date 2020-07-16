/***************************
* Student Number : 1815364
* Name : Kim Doy
---------------------------
* 실습3 : exer3/t2.c
* created on Tue 14 Apr 2020
****************************/

#include <stdio.h>

int main(void){
	int a,b,c,d;
	int largest, smallest;

	printf("Enter four integers: ");
	scanf("%d %d %d %d", &a, &b, &c, &d);
	

	largest = a>b?(a>c?(a>d?a:d):(c>d?c:d)):(b>c?(b>d?b:d):(c>d?c:d));
	printf("Largest: %d\n",largest);

	if(a<b){
		if(a<c){
			if(a<d) smallest = a;
			else smallest = d;	
		}
		else{
			if(c<d) smallest = c;
			else smallest = d;
		}
	}
	else{
		if(b<c){
			if(b<d) smallest = b;
			else smallest = d;
		}
		else{
			if(c<d) smallest = c;
			else smallest = d;
		}

	}
	printf("Smallest: %d\n",smallest);

	return 0;

}
