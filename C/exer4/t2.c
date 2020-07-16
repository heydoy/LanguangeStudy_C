/**************************
* 학  번 : 1815364
* 이  름 : 김도이
* 실습 4 : exer4/t2.c
* created on Tue 21 Arr 2020
***************************/
 
#include <stdio.h>

int main(void){
	int integer;
	
	while(1){	
		printf("Enter a positive integer: ");
		scanf("%d",&integer);
		
		if(integer<=0){
			printf("Error!\n");
			continue;
		}
		else if(integer==1){
			printf("Not prime\n");
			break;
		}
		else{
			for(int i = 2; i < integer ;i++){
				if(integer % i == 0){
					printf("Not prime\n");
					return 0;
				}
			}
			printf("Prime\n");
			break;
		}
	}	
	return 0;
}
