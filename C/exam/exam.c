/*
C언어 파일입출력과 함수를 이용한 시험문제

Original Code by Prof. Park
Answer.txt by Doy Kim 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ans에 있는 7자리 숫자를 출력하도록 answer.txt에 입력하기*/

char* ans = "1234567";

void q1(int a, int b, int c, int d);
void q2(int a, int b, int c);
void q3(int a, int b);
void q4(char *s1, char *s2, int a);
void q5(int a, int b, int c, int d, int e);
void q6(int a, int b);
void q7(char *s1, char *s2);
char eval(char c);
int main(void){
	int i, v, w, x, y, z;
	char st1[64], st2[64];
	FILE *fp = fopen("answer.txt", "r");
	if(!fp){
		printf("Answer file load failed!\n");
		exit(0);
	}
	fscanf(fp, "%d%d%d%d", &w, &x, &y, &z);
	q1(w, x, y, z);

	fscanf(fp, "%d%d%d", &x, &y, &z);
	q2(x, y, z);

	fscanf(fp, "%d%d", &x, &y);
	q3(x, y);

	for(i=0;i<64;i++)	st1[i] = st2[i] = '\0';
	fscanf(fp, "%s%s%d", st1, st2, &x);
	q4(st1, st2, x);

	fscanf(fp, "%d%d%d%d%d", &v, &w, &x, &y, &z);
	q5(v, w, x, y, z);

	fscanf(fp, "%d%d", &x, &y);
	q6(x, y);

	for(i=0;i<64;i++)	st1[i] = st2[i] = '\0';
	fscanf(fp, "%s%s", st1, st2);
	q7(st1, st2);

	fclose(fp);
	eval(0);
	return 0;
}
void q1(int a, int b, int c, int d){
	int k = 1;
	k += (b > 20) ? 3 : 4;
	printf("%c", eval((char)((a-c) * (d-c) - k)));
	return;
}

void q2(int a, int b, int c){
	int *p, *q, *r, k;
	p = &a;
	q = &b;
	r = &c;
	*p = *q + b;
	*r = *p;
	q = r;
	k=(a+b+c)/5+23;
	printf("%c", eval((char)k));
	return;
}


void q3(int a, int b){
	int i=0;
	char ch, k[26];
	for(i=0;i<26;i++)	k[i] = a+i;
	for(i=0;i<26;i++){
		if(*(k+i) != 'G')	continue;
		break;
	}
	ch = (char)(i+b*3);
	printf("%c", eval(ch));
	return;
}

void q4(char *s1, char *s2, int a){
	int i, p, q, r, s;
	char ch = 'X';
	if(strlen(s1) < 6 || strlen(s2) < 6)	goto L4;
	for(i=0, p=0, q=0;s1[i] != '\0'; i++){
		if(s1[i] == 'A')	p++;
		if(s1[i] == 'B')	q++;
	}
	for(i=0, r=0, s=0;s2[i] != '\0'; i++){
		if(s2[i] == 'A')	r++;
		if(s2[i] == 'B')	s++;
	}
	if(p==r && q==s && p>4 && q>2){
		for(i=0;s1[i] != '\0' && s2[i] != '\0'; i++){
			if(s1[i] == s2[i])	goto L4;
		}
		ch = (char)((int)s1[3] + (int)s2[4] - a);
	}
L4:
	printf("%c", eval(ch));
}

void q5(int a, int b, int c, int d, int e){
	struct {
		int x;
		int y;
	} P = {a-1,b-2}, Q={c+3,d+4};
	char ch = 'X';
	if(P.x>0 && P.y>0 && Q.x>0 && Q.y>0){
		if(P.x != Q.x && P.x != Q.y){
			if(P.x * P.x + P.y * P.y == Q.x * Q.x + Q.y * Q.y){	// Hint: 65
				ch = (char)(a * b + c * d + e);
			}
		}
	}
	printf("%c", eval(ch));
	return;
}

void q6(int a, int b){
	int k[5], c;
	char ch;
	k[0] = a & 0x1F;
	k[1] = a & 0xFE0;
	k[2] = a & 0xFF000;
	k[3] = a & 0x7F00000;
	k[4] = a & 0xF1000000;
	c = (k[0] << 19) | (k[1] >> 5) | (k[2] << 12) | (k[3] >> 13) | ((k[4] >> 13) & 0xFFF10000);
	ch = b == c ? (char)(k[2]>>12) : 'X';
	printf("%c", eval(ch));
	return;
}

void q7(char *s1, char *s2){
	int i, j, l = strlen(s1), m = strlen(s2), p=0, q=0;
	char ch = 'X';
	if(l>10 && m>10){
		i=0;
		j=m-1;
		while(i<l && j>=0){
			if(s1[i] >= '0' && s1[i] <= '9'){
				if(s2[j] >= '0' && s2[j] <= '9'){
					if(s1[i] != s2[j])	goto L7;
					i++;
					j--;
				}
				else if(s2[j] == '.'){
					q++;
					j--;
				}
				else	j--;
			}
			else if(s1[i] == '.'){
				p++;
				i++;
			}
			else	i++;
		}
		ch = (char)(p+q+32);
	}
L7:
	printf("%c", eval(ch));
	return;
}

char eval(char c){
	static int score = 0;
	static int count = 0;
	int pt[8] = {0, 2, 5, 8, 12, 16, 22, 30};
	if(count == 7){
		printf("\n\nYour score: %d\n", pt[score]);
		if(score == 7){
			printf("Congratulations!\n");
		}
		return c;
	}
	if(c == ans[count++])
		score++;
	return c;
}

