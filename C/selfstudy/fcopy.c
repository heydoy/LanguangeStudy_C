#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	FILE *src =0, *dst = 0;
	char ch;
	if(argc != 3)	exit(0);
	
	if(!(src = fopen(argv[1], "r"))){
		printf("%s does not exist!\n", argv[1]);
		exit(0);
	}
	
	dst = fopen(argv[2], "w");
	
	while((ch=getc(src)) != EOF){
		putc(ch, dst);
	}

	fclose(dst);
	fclose(src);

	return 0;
}
