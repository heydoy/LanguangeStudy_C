/**************************
* 학  번 : 1815364
* 이  름 : 김도이
* 실습 4 : exer4/t1.c
* created on Tue 21 Arr 2020
***************************/

#include <stdio.h>

int main(void){
	
	for(int i = 1; i <= 9; i++){
		for(int j = 2; j <= 9; j++){
			printf("%3d",j*i);
		}
		printf("\n");
	}
	return 0;
}
