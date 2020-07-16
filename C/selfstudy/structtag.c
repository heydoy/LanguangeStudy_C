#include <stdio.h>

int main(void){

	struct Student {
		char * name;
		int price;
	};
	
	struct Student kim = {"kim", 1500};

	printf("%s %d\n", kim.name, kim.price);
		
	
	struct Student kimi = kim;
	printf("%s %d\n", kimi.name, kimi.price);
	return 0;
}
