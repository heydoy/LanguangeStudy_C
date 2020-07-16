#include <stdio.h>
#include <stdlib.h>

int main(void){
	int i, data[10], copy[10];
	FILE *fp1 = 0, *fp2 = 0;
	fp1 = fopen("data.txt", "w");

	for(i = 0; i < 10; i++) 	data[i] = 0x31323334;

	fwrite(data, 4, 10, fp1);
	fclose(fp1);

	fp2 = fopen("data.txt", "r");
	fread(copy, 4, 10, fp2);
	fclose(fp2);
	
	
	fclose(fp2);
	
	for(i = 0; i < 10; i++)	printf("%X ", copy[i]);
	printf("\n");
	return 0;
}
