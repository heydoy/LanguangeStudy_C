/*
 * Created on 2 Jun 2020 
 * Name. Kim Doy
 * 벡터 내적 값 출력 프로그램
 */

#include <stdio.h>


int innerProduct(int *a, int *b, int size);

int main(void){
	
	int x[3];
	int y[3];

	int result;
	//int *p = x;
	//int *q = y;
	//배열의 이름(x)이 배열의 시작주소 x = &x[0] 를 가지고 있기 때문에 주석처리함
	
	printf("Enter vector 1 : ");
	scanf("%d %d %d", x, x+1, x+2);
	//scanf("%d %d %d", p, p+1, p+2);
	
	printf("Enter vector 2 : ");
	scanf("%d %d %d", y, y+1, y+2);
	//scanf("%d %d %d", q, q+1, q+2);
	
	printf("Inner Product = %d \n", innerProduct(x, y, 3));
	//printf("Inner Produt = %d\n", innerProduct(p, q, 3));

	return 0;
}
int innerProduct(int *a, int *b, int size){
	
	int result = 0;

	for(int i = 0; i < size ; i++){
		result += (*(a+i)) * (*(b+i));	
	}

	return result;
}
