#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
	struct {
		char * name;
		int price;
		int weight;
	} item1, item2, item3, item4;

	item1.name = (char *)malloc(15);
        item2.name = (char *)malloc(15);
	item3.name = (char *)malloc(15);

	strcpy(item1.name, "Desk");
	strcpy(item2.name, "Computer");
	strcpy(item3.name, "Mouse");

	item1.price = 600;
	item2.price = item1.price * 2;
	item3.price = item1.price / 10;

	printf("%s, %d\n", item2.name, item3.price);

	item4 = item1;

	printf("%s, %d\n", item4.name, item4.price);

	free(item1.name);
	free(item2.name);
	free(item3.name);
	
	return 0;
}
