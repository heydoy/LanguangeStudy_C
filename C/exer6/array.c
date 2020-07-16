/*
 * Created on 12 May 2020 
 * Name : Kim Doy
 */

#include <stdio.h>

int main(void){
	
	int arr[6][7] = {0,};
	//int odd = 1;

	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 7 ; j++){
			
			//arr[i][j] = odd;
			//odd += 2;
			arr[i][j] = (i*7*2)+(2*(j+1)-1);	
			printf("%3d",arr[i][j]);
		}
		printf("\n");
	}
	

	return 0;
}

