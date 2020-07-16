#include <stdio.h>

int main(void){
	
	int x;
	double y=1.0;
	double temp;

	printf("positive integer here: ");
	scanf("%d", &x);
	
	
	while(1){
		y = (y+x/y)/2;
		temp = y - x/y;
		if(temp < 0.00001) break;
	}
	
	printf("Square root: %f\n",y);


	return 0;
}
