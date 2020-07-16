/*
 * Student NO. 1815364
 * Name. Kim Doy
 * exer12/t1.c
 */


#include <stdio.h>

int colorcheck(char colorname[]);
int main(void){
	
	char red[] = "red";
	char green[] = "green";
	char blue[] = "blue";
	
	int redv, greenv, bluev;
	int total;

	redv = colorcheck(red);
	greenv = colorcheck(green);
	bluev = colorcheck(blue);
	
	redv <<=22;
	greenv <<=11;
	
	total = redv + greenv + bluev;

	printf("Color value = %08X\n", total );
	
	return 0;
}

int colorcheck(char colorname[]){

	int color;
	while(1){
		printf("Enter %s color value (0 ~ 1023) : " ,colorname);
		scanf("%d", &color);
		if(color >= 0 && color < 1024)
			return color;
	}
}
