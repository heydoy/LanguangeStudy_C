/*********************
 * Created on 28 Apr 2020 
 * Kim Doy 
 * 제곱근 출력 
 *********************/

#include <stdio.h>

int main(void){
	
	int x;
	double y = 1.0;
	double temp;	
	
	printf("Enter a positive integer: ");
	scanf("%d", &x);
	
	temp = (double)x;

	for(;;){
		y =(y+(temp/y))/2.0;
		//교수님, 조건이 0.00001이면 2의 제곱근은 1.414216이 나오고
		//조건이 0.000001일 때 1.414214(pdf와 같은 값)가 나와요.
		if( (y-(temp/y)) <=  0.00001){
			//y=(y+(temp/y))/2.0;
			break;
		}	
			
	}

	printf("Square root = %.6f\n", y);

	return 0;
}
