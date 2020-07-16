#include <stdio.h>
#include <stdlib.h>

int main(void){
	char ch;
	FILE *fp;

	fp = fopen("data.txt", "r");

	if(!fp){
		printf("data.txt does not exist!\n");
		exit(0);
	}

	/*
	for(ch = 'A'; ch <= 'Z'; ch++){
		putc(ch, fp);
	}
	*/
	// EOF는 255, NULL은 0
	// EOF = End of File이라는 뜻
	// fp 포인터가 캐릭터 값을 반환에 성공하면 다음바이트를 가리킨다.
	/*
	printf("%c\n", getc(fp));
	printf("%c\n", fgetc(fp));
	for(int i= 0; i< 10; i++)	getc(fp);
	printf("%c\n", getc(fp));
	*/
	
	while((ch=getc(fp)) != EOF){
		printf("%c\n",getc(fp));	
	}

	fclose(fp);

	return 0;
}
