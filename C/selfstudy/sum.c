#include <stdio.h>
int main(void){
	int a,b,c,d;
	int m, n;
	printf("Enter two fractions : ");
	scanf("%d/%d+%d/%d", &a, &b, &c, &d);
	n = b * d;
	m = a * d + b * c;
	printf("sum = %d / %d \n", m,n);


	return 0;
}
