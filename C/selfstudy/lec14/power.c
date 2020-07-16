/*
 * 재귀함수
 * 자기 자신을 호출하는 함수
 * 재귀함수를 사용할 때는 반드시 재귀함수 종료조건을 추가해야한다. 그렇지 않으면 무한히 불려짐
 * */

// power함수를 아래 원리를 이용하여 만들어 볼 것
//
// n 이 짝수이면 x^n = x^n/2 * x^n/2
// n 이 홀수이면 x^n = x^(n-1)/2 * x^(n-1)/2 * x
//
//

#include <stdio.h>

int power(int x, int n){
	if(n == 0)	return 1;
	else if(n % 2 == 0)
		return power(x, n/2)*power(x, n/2);
	else
		return x * power(x, (n-1)/2) * power(x, (n-1)/2);
}

int main(void){
	char skip = 'y';
	int x, n;

	printf("제곱할 숫자 : ");
	scanf("%d",&x);
	printf("몇 제곱? : ");
	scanf("%d",&n);

	printf("%d의 %d 제곱은 %d 입니다.\n", x, n, power(x, n));


	return 0;
}
