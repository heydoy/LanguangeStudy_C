#include <stdio.h>

// '='의 부가기능 실습

int main(void){
		
	int i;
	float x;
	x = i = 12.34f;
	
	printf("=의 부가기능을 사용하고자 할 ㄸㅐ 타입이 다르경우는 유의해아한다.");
	printf("int i;\nfloat x;\nx = i = 12.34f;\n");
	printf("정수형 변수 i는 %d, 실수형 변수 x는 %.2f이다.\n", i , x);
	
	printf("\n");

	printf("부가기능의 사용 에\n");

	int a,b,c;
	a = 1;
	c = 1 +(b = a);

	printf("int a, b, c;\na = 1;\nc = 1 + (b = a);\n");
	printf("a = %d, b = %d, c = %d\n", a, b, c);


	printf("증가/감소 연산삱\n");
	printf("d = 4\n");
	int d = 4;
	printf("d++ = %d\n",d++);
	printf("d = %d\n",d);

	printf("e = 4\n");
	int e = 4;
	printf("++e = %d\n",++e);
	printf("e = %d\n",e);

}
