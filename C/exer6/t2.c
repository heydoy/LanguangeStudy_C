/*
 * Student No. : 1815364
 * Name : Kim doy
 * Mission 2 : exer6/t2.c
 */


// Caesear Cipher 

#include <stdio.h>

int main(void){

	char ch[80];
	int k; 

	printf("Enter message to be encrypted : ");
	scanf("%[^\n]", ch);
	//fflush(stdin);
	printf("Enter shift amount: ");
	scanf(" %d", &k);
	
	for(int i = 0; i < 80; i++){
		if (ch[i] == '\n')	break;

		if (ch[i] <= 90 && ch[i] >= 65)	
			ch[i] = (ch[i]-'A'+k) % 26 +'A';

		else if (ch[i] <= 122 && ch[i] >= 97)
			ch[i] = (ch[i]-'a'+k) % 26 + 'a';
	
	}
	printf("Encrypted message: %s\n", ch);

	return 0;
}
