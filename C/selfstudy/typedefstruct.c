#include <stdio.h>

// typedef : 사용자 정의 형식을 정의하는 것. 
// typedef int PRICE; <- int대신에 PRICE로 형을 쓰겠다고

typedef struct info {
	char name[15];
	int price;
} INFO;

int main(void){
	INFO item = {"computer",50000};

	printf("%d, %s\n", item.price, item.name);
	return 0;
}
