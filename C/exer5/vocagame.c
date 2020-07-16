/*********************
 * Created on 28 Apr 2020
 * Kim Doy 
 * 영단어를 입력하면, 글자별로 점수 매겨서 점수 보여주기 
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

