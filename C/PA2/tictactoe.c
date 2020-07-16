/* -------------------------
 * Programming Assignment #2
 * PA2/tictactoe.c
 * Due date : 7th Jun, 2020
 * -------------------------
 * 
 * Student No. 1815364
 * Student Name. Kim Doy
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define BOARD_SIZE 3	// 판 사이즈 3x3
#define FORMER 'O'	// 선수는 O
#define LATTER 'X'	// 후수는 X

#define USER_LOSE 0
#define USER_WIN 1
#define USER_DRAW 2
#define MORE_CHANCE 3

//보드 초기화와 보드 출력
void init_board( char piece[BOARD_SIZE][BOARD_SIZE] );	//프로그램을 시작할 때 한번만 사용 
void print_board( char piece[BOARD_SIZE][BOARD_SIZE] ); 

// 게임 플레이 관련 함수
void computer_play( char comstone, char piece[BOARD_SIZE][BOARD_SIZE] );
void user_play( char userstone, char piece[BOARD_SIZE][BOARD_SIZE] );

// 게임 승리조건 체크 함수
int game_check( char piece[BOARD_SIZE][BOARD_SIZE], char userstone, char comstone );

int main(void){
	
	srand(time(0)); //rand 초기화 함수. 한번사용
	int turn;
	char userstone, comstone;
	int check;

	//turn이 1이면 사용자가 선수, 0이면 컴퓨터가 선수
	turn = rand() % 2;
	
	if(turn){
		userstone = FORMER;
		comstone = LATTER;
		//printf("user: %c, comp: %c\n", userstone, comstone);
	}
	else{
		userstone = LATTER;
		comstone = FORMER;
		//printf("user: %c, comp: %c\n", userstone, comstone);
	}

	//o,x 가 들어가는 칸 9칸
	char piece[BOARD_SIZE][BOARD_SIZE];

	init_board(piece);
	
	int i = 1;

	while(i){

		print_board(piece);
		
		check = game_check(piece, userstone, comstone);
		
		switch(check){
			case USER_WIN : 
				printf("You Win!\n");
				return 0;

			case USER_LOSE :
				printf("You lost...\n");
				return 0;

			case USER_DRAW : 
				printf("Draw!\n");
				return 0;

		}
		// turn이 1이면 사용자가 선, 홀수일때 사용자가 두기
		if(turn && i % 2 )			user_play(userstone, piece);
		else if(turn && i % 2 == 0 )		computer_play(comstone, piece);
		
		// turn이 0이면 컴퓨터가 선, 홀수일 때 컴퓨터가 먼저두기
		else if(turn == 0 && i % 2 )		computer_play(comstone, piece);
		else if(turn == 0 && i % 2 == 0)	user_play(userstone, piece);
	
			
		printf("\n");
		i++;
	}


	return 0;

}

/* 사용자 함수 정의하는 곳 */
void init_board( char piece[BOARD_SIZE][BOARD_SIZE] ){
	
	// 게임 시작전에 빈칸 넣어 초기화해주기
	for(int i = 0; i < BOARD_SIZE ; i++){
		for(int j = 0; j < BOARD_SIZE; j++){
			piece[i][j] = ' ';
		}
	}
}
void print_board( char piece[BOARD_SIZE][BOARD_SIZE]){
        
        //틱택토 바닥판 출력하기 
        printf(" %c | %c | %c \n",piece[0][0],piece[0][1],piece[0][2]);
        printf("---+--—+--—\n");
        printf(" %c | %c | %c \n",piece[1][0],piece[1][1],piece[1][2]);
        printf("—--+—--+—--\n");
        printf(" %c | %c | %c \n",piece[2][0],piece[2][1],piece[2][2]);
        

}
int game_check( char piece[BOARD_SIZE][BOARD_SIZE], char userstone, char comstone ){
	
	//승리조건 체크하기
	
	int empty = 0;

	for(int i = 0; i < BOARD_SIZE ; i++){
			
		//가로줄 빙고
		if(piece[i][0] != ' ' && piece[i][0] == piece[i][1] && piece[i][1] == piece[i][2]){
			if(piece[i][0] == userstone)	return USER_WIN;
			else	return USER_LOSE;
		}
		//세로줄 빙고
		else if(piece[0][i] != ' ' && piece[0][i] == piece[1][i] && piece[1][i] == piece[2][i]){
			if(piece[0][i] == userstone)	return USER_WIN;
			else	return USER_LOSE;		
		}			
		//대각선 빙고
		else if(piece[0][0] != ' ' && piece[0][0] == piece[1][1] && piece[1][1] == piece[2][2]){
			if(piece[0][0] == userstone) 	return USER_WIN;
			else	return USER_LOSE;
		}
		else if(piece[0][2] != ' ' && piece[0][2] == piece[1][1] && piece[1][1] == piece[2][0]){
			if(piece[0][2] == userstone)	return USER_WIN;
			else	return USER_LOSE;
		}


		// 무승부 판별

		for(int j = 0 ; j < BOARD_SIZE; j++){
			if(piece[i][j] == ' ')	empty += 1;	
		}
	}
	if(empty == 0)	return USER_DRAW;
	
	return MORE_CHANCE;
}

// 실제 게임 플레이 하기
void computer_play( char comstone, char piece[BOARD_SIZE][BOARD_SIZE] ){
	
	int choose;
	
	while(1){
		choose = rand() % 9;
		if( piece[choose/3][choose%3] == ' ')	break;
		
	}

	piece[choose/3][choose%3] = comstone;

	return;

}

void user_play( char userstone, char piece[BOARD_SIZE][BOARD_SIZE] ){
	
	int choose;
	
	while(1){
		printf("Enter a number: ");
		scanf("%d", &choose);

		if(choose < 1 || choose > 9)	
			printf("Wrong number!\n");
		else if( piece[(choose-1)/3][(choose-1)%3] != ' ')	
			printf("Wrong Number!\n");
		else				
			break;
	}
	piece[(choose-1)/3][(choose-1)%3] = userstone;
	
	return;
}
