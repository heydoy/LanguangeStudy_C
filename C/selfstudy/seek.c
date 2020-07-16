#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	FILE *fp = fopen("foo.txt", "r");
	long int pos;
	int i;
	
	for(i = 0; i<11; i++) getc(fp);

	printf("%c\n", getc(fp));
	
	fseek(fp, -4L, SEEK_CUR);
	pos = ftell(fp);
	printf("%c\n", getc(fp));
	printf("%c\n", getc(fp));
	printf("%c\n", getc(fp));
	printf("%c\n", getc(fp));

	fseek(fp, pos, SEEK_SET);
	printf("%c\n", getc(fp));

	return 0;

}
