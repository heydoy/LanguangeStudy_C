#include <stdio.h>

int main(void){
	int num;
	int digit = 0;

	printf("enter a number : ");
	scanf("%d", &num);

	for(int i = num ; i>0 ; i=i/10){			digit++;
	}
	printf("%d digits \n",digit);

	return 0;
}

