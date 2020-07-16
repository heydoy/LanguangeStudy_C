/*********************
 * 이름 : 김도이
 * 학번 : 1815364
 * 날짜 : 4월 28일(화)
 * 과제명 : exer5/t1.c
 * 과제주제: 영단어
 *********************/

#include <stdio.h>

int main(void){

	char ch;
	int value = 0;

	printf("Enter a word: ");
	do{
		scanf("%c",&ch);
		if( ch=='\n' || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')){
			if(ch =='Q' || ch == 'q' || ch == 'Z' || ch == 'z') value += 10;
			else if(ch == 'J' || ch == 'j' || ch == 'X' || ch == 'x') value += 8;
			else if(ch == 'K' || ch == 'k') value += 5;
			else if(ch == 'F' || ch == 'f' || ch == 'H' || ch == 'h' || ch == 'V' || ch == 'v' || ch == 'W' || ch == 'w' || ch == 'Y' || ch == 'y') value += 4;
			else if(ch == 'B' || ch == 'b' || ch == 'C' || ch == 'c' || ch == 'M' || ch == 'm' || ch == 'P' || ch == 'p') value += 3;
			else if(ch == 'D' || ch == 'd' || ch == 'G' || ch == 'g') value += 2;
			else if(ch=='\n') value = value;
			else value += 1;		
				
		}
		else{
			printf("Error!\n");
			return 0;
		}
		
	} while(ch != '\n');
	

	printf("Value = %d\n",value);

	
	return 0;
}

