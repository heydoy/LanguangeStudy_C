/*
* 자료구조
* 과제 1. 볼링
* ------------
* 이름: 김도이
* 학번: 1815364
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAME 10

#define OPEN 0
#define SPARE 1
#define STRIKE 2

typedef struct __node{
	int first;
	int second;
	int result;
	struct Frame *next;
} Frame;

Frame *head = NULL;
Frame *currentFrame = NULL;

int framenow = 0;
int totalScore[MAX_FRAME] = {0,};


//함수선언
void print_title(void);
int roll_the_bowl(void);
void bowl_game(void);
void bowl_game_tenth(void);
void add_frame(int bowl_first, int bowl_second, int bowl_result);
void free_list(void);
void calculate_score(void);
void print_score(void);


//메인함수
int main(void){

    print_title();
    for(int i = 0; i < MAX_FRAME ; i++ ){
        
        if(i < 9){
            bowl_game();
        }
        else if(i == 9){
            
            bowl_game_tenth();
        }
        calculate_score();
        print_score();
        
    }
	
    free_list();
    printf("                  볼링 게임을 이용해주셔서 감사합니다.\n");
    printf("                            ~~ END ~~\n\n");

	return 0;
}


/* 함수 정의 */

// 타이틀 출력. 프로그램이 시작할 때 한번만 실행.
void print_title(void){
	printf("=====================================================\n\n");
    printf("                       볼링 게임\n\n");
    printf("=====================================================\n");
}

int roll_the_bowl(void){
	int bowl;
	while(1){
		printf("볼을 굴려주세요 : ");
		scanf("%d", &bowl);
		if(bowl < 0 || bowl > 10)
			printf("잘못된 입력입니다. 다시 입력해주세요.\n");
            
		else{
			break;
		}
	}
	return bowl;
}

void bowl_game(void){
    int bowl_first, bowl_second;
    
    while(1){
        bowl_first = roll_the_bowl();
        //스트라이크일때
        if(bowl_first == 10){
            printf("STRIKE!\n");
            add_frame(10, 0, STRIKE);
            break;
        }
        //스트라이크가 아닐때
        else {
            while(1){
                bowl_second = roll_the_bowl();
                if( bowl_first + bowl_second > 10){
                    printf("잘못된 입력입니다.\n");
                    continue;
                }
                else if( bowl_first + bowl_second == 10){
                    printf("SPARE!\n");
                    add_frame( bowl_first, bowl_second, SPARE);
                }
                else{
                    add_frame( bowl_first, bowl_second, OPEN);
                }
                break;
            }
            break;
        }
    }
}

void bowl_game_tenth(void){
    
    int bowl1, bowl2, bowl3;
    int status;
    
    bowl1 = roll_the_bowl();
    if(bowl1==10){
        printf("STRIKE!\n");
        add_frame(10, 0, STRIKE);
        
        bowl2 = roll_the_bowl();
        if(bowl2==10){
            printf("STRIKE!\n");
            status=STRIKE;
        }
        else
            status=OPEN;
        add_frame(bowl2, 0, status);
        
        bowl3 = roll_the_bowl();
        if(bowl3==10){
            printf("STRIKE!\n");
            status=STRIKE;
        }
        else
            status=OPEN;
        
        add_frame(bowl3, 0, status);
    }
    else{
        bowl2 = roll_the_bowl();
        if(bowl1+bowl2 == 10){
            printf("SPARE\n");
            add_frame(bowl1, 0, SPARE);
            add_frame(bowl2, 0, SPARE);
            
            bowl3 = roll_the_bowl();
            
            add_frame(bowl3, 0, OPEN);
            if(bowl3==10){
                printf("STRIKE!\n");
                status=STRIKE;
            }
            else
                status=OPEN;
            
            add_frame(bowl3, 0, status);
        }
        else{
            add_frame(bowl1, 0, OPEN);
            add_frame(bowl2, 0, OPEN);
        }
    }
}
//볼링 결과를 링크드 리스트에 저장하는 함수
void add_frame(int bowl_first, int bowl_second, int bowl_result){
    
    Frame *temp = (Frame *)malloc(sizeof(Frame));
    temp->first = bowl_first;
    temp->second = bowl_second;
    temp->result = bowl_result;
    
    //첫번째 프레임일때
    if(head == NULL){
        temp->next = head;
        head = temp;
        currentFrame = temp;
    }
    else{
        temp->next = currentFrame->next;
        currentFrame->next = temp;
        currentFrame = currentFrame->next;
    }
}

//메모리 해제하는 함수
void free_list(void){
    Frame *p, *current;
    
    for( p = head ; p != NULL ; p = current){
        current = p->next;
		free(p);
	}
	return;
}

//순회 후 배열에 저장
void calculate_score(void){
    Frame *p = head;
    int isStrike, isSpare = 0;
    
    for( int i = 0; i < 12 && p != NULL; i++){
        
        if(i >= 0 && i < 12){
            if(i>=9 && i < 12){
                totalScore[9] += p->first;
            }
            if(isStrike == 1){
                if(p->result == STRIKE)
                    isStrike += 1;
                
                else if(p->result == SPARE){
                    isSpare = 1;
                    isStrike = 0;
                    
                    totalScore[i-1] = 10 + p->first + p->second;
                }
                else{
                    isStrike = 0;
                    isSpare = 0;
                    totalScore[i-1] = 10 + p->first + p->second;
                    totalScore[i] = p->first + p->second;
                }
            }
            else if(isStrike >= 2){
                if(p->result == STRIKE) {
                    totalScore[i-2] = 10 + 10 + 10;
                    isStrike += 1;
                }
                else if(p->result == SPARE) {
                    isSpare = 1;
                    isStrike = 0;
                    
                    totalScore[i-2] = 10 + 10 + p->first;
                    totalScore[i-1] = 10 + p->first + p->second;
                }
                else {
                    isSpare = 0;
                    isStrike = 0;
                    
                    totalScore[i-2] = 10 + 10 + p->first;
                    totalScore[i-1] = 10 + p->first + p->second;
                    totalScore[i] = p->first + p->second;
                }
            }
            
            
            else if(isSpare == 1){
                if(p->result == STRIKE){
                    isSpare = 0;
                    isStrike = 1;
                    
                    totalScore[i-1] = 10 + 10;
                }
                else if(p->result == SPARE){
                    isSpare = 1;
                    isStrike = 0;
                    
                    totalScore[i-1] = 10 + p->first;
                }
                else{
                    isSpare = 0;
                    isStrike = 0;
                    
                    totalScore[i-1] = 10 + p->first;
                    totalScore[i] = p->first + p->second;
                }
            }
            else {
                if(p->result == STRIKE) {
                    isStrike += 1;
                    
                }
                else if(p->result == SPARE) {
                    isSpare += 1;
                }
                else if(p->result == OPEN) {
                    isSpare = 0;
                    isStrike = 0;
                
                    totalScore[i] = p->first + p->second;
                    
                }
            }
        }
        p = p->next;
    }
    
}
// 점수 현황 출력하기
void print_score(void){
    
    printf("\n");
    printf("=======================================================================\n");
    printf("                             볼링 게임 점수판\n");
    printf("=======================================================================\n");
    
    printf("   1      2      3      4      5      6      7      8      9      10\n");
    printf("-----------------------------------------------------------------------\n");
    Frame *p = head;
    for(int i = 0; i < 12 && p != NULL; i++){
        if( i ==9 ){
            printf("%2d|", p->first);
        }
        else if(i == 10){
            if(p->first > 9)
                printf("%2d",p->first);
            else
                printf("%1d", p->first);
        }
        else if(i == 11){
            printf("|%-2d", p->first);
        }
        else{
        printf("%3d|%-3d", p->first, p->second);
        }
        p = p->next;
    }
    printf("\n");
    printf("-----------------------------------------------------------------------\n");
    
    p = head;
    int sum = 0;
    for(int i = 0 ; i < 10 && p != NULL ; i++){
        if(i == 9)  printf("%5d", totalScore[i]);
        else        printf("%5d  ",totalScore[i]);
        sum += totalScore[i];
    }
    printf("\n");
    printf("-----------------------------------------------------------------------\n\n");

    printf("                                                      Total: %6d\n\n", sum);
    
    printf("=======================================================================\n\n");
    
}
