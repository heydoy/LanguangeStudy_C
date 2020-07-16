/**************************
* created on 21 Apr 2020
* Kim Doy 
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
