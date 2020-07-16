/*
 * Student.No 1815364
 * Name. Kim Doy
 * exer12/t2.c
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Name {
	char surname[12];
	char firstname[24];
};

struct Phone{
	int front;
	int back;
};

typedef struct{
	struct Name name;
	struct Phone phone;

} Phonebook;

Phonebook * list[3];

int search(char name[]);

int main(void){
	char searchname[12];
	int result;
	int x, y;

	for(int i= 0; i < 3; i++){
		list[i] = (Phonebook *)malloc(sizeof(Phonebook));

		printf("Enter name: ");
		scanf("%s %s", list[i]->name.surname, list[i]->name.firstname);

		printf("Enter phone number: ");
		
		//scanf("%d-%d", list[i]->phone.front, list[i]->phone.back);
		scanf("%d-%d",&x, &y);
		list[i]->phone.front = x;
		list[i]->phone.back = y;
		fflush(stdin);
	}

	printf("Enter surname: ");
	scanf("%s", searchname);
	
	result = search(searchname);

	if(result == 999)
		printf("Not found\n");
	else
		printf("Phone number: %d-%d\n", list[result]->phone.front, list[result]->phone.back);
		
	
	for(int j = 0; j< 3; j++)
		free(list[j]);

	return 0;
}
int search(char name[]){
	for(int i = 0; i < 3; i++){
		//printf("%s", list[i]->name.surname);
		if(strcmp(name, list[i]->name.surname)==0){
                       return i;
                }
	}
	return 999;

}
