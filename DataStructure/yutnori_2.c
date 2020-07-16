/*
* /// 노드는 다 구현함!! 이제 나머지 필요!!
* 자료구조 과제 2. 윷놀이
* 규칙 : 플레이어 2인, 말 3개
* 양방향 순환리스트 사용
* ----------------------
* 학번: 1815364
* 이름: 김도이
*/

/* 헤더파일 불러오기 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* 노드와 포인터 선언 */
//윷 판의 한 칸을 나타내는 노드
typedef struct Yoot {
    //링크필드 4개
    struct Yoot * shortPrev;
    struct Yoot * shortNext;
    struct Yoot * Prev;
    struct Yoot * Next;
    
    //말 위치 저장할 char포인터
    char * data;
}Yoot;

//윷 시작과 끝 가리키는 포인터
Yoot *HEAD = NULL;
Yoot *TAIL = NULL;     // 최종적으로 도달하는 곳. 여기 도착하면 종료
Yoot *TAIL_T = NULL;
Yoot *TAIL_B = NULL;

//윷의 이동경로 제한위치를 가리키는 포인터
Yoot *RT = NULL;      //Right Top : 오른쪽 위
Yoot *LT = NULL;      //Left Top : 왼쪽 위
Yoot *LB = NULL;      //Left Bottom : 왼쪽 아래
Yoot *C = NULL;       //Center: 가운데

//윷판 칸 갯수 체크용 변수
int size = 0;

// 통과한 말의 갯수 저장하는 변수
int passP1 = 0;
int passP2 = 0;

// 말의 위치를 계속해서 추적하는 포인터
Yoot *pA = NULL;
Yoot *pB = NULL;
Yoot *pC = NULL;

Yoot *pX = NULL;
Yoot *pY = NULL;
Yoot *pZ = NULL;


// 도개걸윷모 갯수 저장하는 변수
int yut[6] = {0,};
// 윷 막대가 던져진 횟수 저장하는 변수
int total = 0;

/* 함수 선언 부분 */
void printTitle(void);
void initYoot(void);
Yoot * allocYoot(Yoot * pre);
void boardStatus(void);
int playYoot(void);
void moveYoot(void);
void moveHorse(int player);
void goHorse1(char choose, int number);
void goHorse2(char choose, int number);
void catchEnemy1(char choose);
void catchEnemy2(char choose);


/* 메인함수 시작 */
int main(void){
    int i = 0;
    //난수함수 seed를 time()으로 설정
    srand(time(NULL));
    //윷판 세팅. 처음 한번만
    initYoot();
    // 보드 상황 보여주기
    printTitle();
    getchar();
    boardStatus();
    while(i++ >= 0){
        //승리조건
        if((pA == TAIL && pB == TAIL && pC == TAIL) || passP1 ==3 ){
            printf("PLAYER 1이 승리하였습니다.\n");
            break;
        }
        else if((pX == TAIL && pY == TAIL && pZ == TAIL)|| passP2 ==3 ){
            printf("PLAYER 2가 승리하였습니다.\n");
            break;
        }
            
        
        //플레이어 1
        if(i % 2 == 1){
            printf("\n>>>>>>>> PLAYER 1의 차례\n");
            total = 0;
            moveYoot();
            if(pA == NULL && pB == NULL && pC == NULL && total == 1 && yut[0] == 1){
                // 아무 말도 윷판에 없고, 빽도가 나왔을 경우 스킵한다.
                total = 0;
                yut[0] = 0;
                printf("윷판에 말이 없어서, 말이 뒤로 갈 수 없습니다. \n자동으로 다음 상대에게 턴이 넘어갑니다.\n");
                continue;
            }
            moveHorse(i);
            
        }
        //플레이어 2
        else if(i % 2 == 0) {
            printf("\n>>>>>>>> PLAYER 2의 차례\n");
            total = 0;
            moveYoot();
            if(pX == NULL && pY == NULL && pZ == NULL && total == 1 && yut[0] == 1){
                // 아무 말도 윷판에 없고, 빽도가 나왔을 경우 스킵한다.
                total = 0;
                yut[0] = 0;
                printf("윷판에 말이 없어서, 말이 뒤로 갈 수 없습니다. \n자동으로 다음 상대에게 턴이 넘어갑니다.\n");
                continue;
            }
            moveHorse(i);
        }
        
    }
    
    
    //i = playYoot();
   // i = i==0?-1:i;
    //printf("총 %d칸 이동하세요\n",i);
    
    return 0;
}

/* 함수 정의 부분 */
void printTitle(void){
    printf("\n\n");
    printf("'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n");
    printf("  _|      _|  _|    _|  _|_|_|_|_|  _|      _|    _|_|    _|_|_|    _|_|_|\n");
    printf("    _|  _|    _|    _|      _|      _|_|    _|  _|    _|  _|    _|    _|\n");
    printf("      _|      _|    _|      _|      _|  _|  _|  _|    _|  _|_|_|      _|\n");
    printf("      _|      _|    _|      _|      _|    _|_|  _|    _|  _|    _|    _|\n");
    printf("      _|        _|_|        _|      _|      _|    _|_|    _|    _|  _|_|_|\n\n");
    printf("'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n\n");
    printf("\t\t\tPLAYER 1 : ABC, PLAYER 2 : XYZ\n");
    printf("\t윷놀이 게임을 시작합니다. 게임을 진행하시려면 아무키나 누르세요.\n\n");
    printf("'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n");
}
void initYoot(void){   //윷놀이 판 노드 생성
    //head 설정
    Yoot *p = allocYoot(HEAD);
    //이후 오른쪽 아래에서 위로 4칸
    p = allocYoot(p);
    p = allocYoot(p);
    p = allocYoot(p);
    p = allocYoot(p);
    //RT설정
    p = allocYoot(p);
    RT = p;
    // 이후 오른쪽에서 왼쪽으로 4칸
    p = allocYoot(RT);
    p = allocYoot(p);
    p = allocYoot(p);
    p = allocYoot(p);
    //LT 설정
    p = allocYoot(p);
    LT = p;
    //이후 왼쪽위에서 아래로 4칸
    p = allocYoot(LT);
    p = allocYoot(p);
    p = allocYoot(p);
    p = allocYoot(p);
    //LB 설정
    p = allocYoot(p);
    LB = p;
    //이후 오른쪽 3칸, TAIL_B 설정
    p = allocYoot(LB);
    p = allocYoot(p);
    p = allocYoot(p);
    p = allocYoot(p);

    //아래쪽 마지막 칸 설정
    TAIL_B = p;
    //p->Next = HEAD;
    HEAD->Prev = TAIL_B;
    
    // 큰 한바퀴는 끝
    // <| 이 경로 작업하기
    TAIL = RT;
    p = allocYoot(RT);
    RT->Next = LT->Prev->Prev->Prev->Prev;
    p = allocYoot(p);
    
    // C 설정
    p = allocYoot(p);
    C = p;
    C->shortPrev = C->Prev;
    C->Prev = NULL;
    // 이후 한칸, TAIL_T 설정
    p = allocYoot(C);
    C->shortNext = p;
    C->Next = NULL;
    
    p = allocYoot(p);
    TAIL_T = p;
    TAIL_T->Next = HEAD;
    HEAD->shortPrev = TAIL_T;
    
    // < 경로 끝
    // > 경로 시작
    
    TAIL = LT;
    p = allocYoot(LT);
    LT->Next = LB->Prev->Prev->Prev->Prev;
    p = allocYoot(p);
    // C 설정
    p->Next = C;
    C->Prev = p;
    TAIL = C;
    //C 다음칸 두개
    p = allocYoot(C);
    p = allocYoot(p);
    
    //LB와 연결
    p->Next = LB;
    LB->shortPrev = p;
    
    // TAIL로 가면 승리
    
    TAIL = allocYoot(TAIL_B);
    TAIL_T->Next = TAIL;
    TAIL_B->Next = TAIL;
    //TAIL->shortPrev = TAIL_T;
    
    
    //printf("총 윷보드 칸의 갯수: %d\n", size);
}


//동적할당해서 포인터 리턴해주는 함수
Yoot * allocYoot(Yoot * pre){
    
    Yoot *new_node = (Yoot *)malloc(sizeof(Yoot));
    new_node->data = malloc(sizeof(char)*4);    // 말이 최대 3개이므로
    new_node->data = "O";
    
    new_node->Prev = NULL;
    new_node->Next = NULL;
    new_node->shortNext = NULL;
    new_node->shortPrev = NULL;
    
    //연결리스트 맨 앞에 삽입하는 경우
    if(pre == NULL && HEAD == NULL){
        HEAD = new_node;
        TAIL = new_node;
    }
    //RT, LT 분기점에서 삽입하는 경우
    else if(pre == RT || pre == LT){
        new_node->Prev = pre;
        pre->shortNext = new_node;
        TAIL = new_node;
    }
    //연결리스트 맨 뒤에 삽입하는 경우
    //else if(pre == TAIL){
    else {
        new_node->Prev = TAIL;
        TAIL->Next = new_node;
        TAIL = new_node;
    }
    size++;
    return new_node;
}


void boardStatus(void){ //윷놀이 판 현재 상태 보여주기
    printf("\n");
    printf("=========================\n");
    printf("    >> 윷놀이 보드 <<\n");
    printf("=========================\n");
    //왼쪽 오른쪽 줄 상태 보여줄 l,r 선언(사용 후 해지)
    Yoot *l = (Yoot *)malloc(sizeof(Yoot));
    
    //1번째 줄 : LT-> prev 4개 -> RT
    l=LT;
    for(int i = 0; i < 6 ; i++){
        printf("%3s ", l->data);
        l = l->Prev;
    }
    printf("\n");
    //2번째 줄 : LT->next  LT->short next  RT->short next  RT->prev
    printf("%3s  ",LT->Next->data);
    printf("%3s",LT->shortNext->data);
    printf("       ");
    printf("%3s  ",RT->shortNext->data);
    printf("%3s", RT->Prev->data);
    printf("\n");
    //3번째 줄 : 2째줄의 next->next prev->prev
    printf("%3s    ",LT->Next->Next->data);
    printf("%3s",LT->shortNext->Next->data);
    printf("   ");
    printf("%3s    ",RT->shortNext->Next->data);
    printf("%3s", RT->Prev->Prev->data);
    printf("\n");
    //4번째 줄 : C 가운데 하나만
    printf("          %3s\n",C->data);
    //5번째 줄 : Lt-...> next   C->next C->short next  RT-...>prev
    printf("%3s    ",LB->Prev->Prev->data);
    printf("%3s", C->Next->data);
    printf("   ");
    printf("%3s    ",C->shortNext->data);
    printf("%3s", HEAD->Next->Next->data);
    printf("\n");
    //6번째 줄 : 5번째 줄의 next->next tail_t prev->prev
    printf("%3s  ",LB->Prev->data);
    printf("%3s",LB->shortPrev->data);
    printf("       ");
    printf("%3s  ",HEAD->shortPrev->data);
    printf("%3s", HEAD->Next->data);
    printf("\n");
    //7번째 줄 : LB -> next 3개  tail_b  head
    l = LB;
    for(int i = 0; i < 5 ; i++){
        printf("%3s ",l->data );
        l = l->Next;
    }
    printf("%3s",HEAD->data);
    
    printf("\n");
    printf("=========================\n\n");
    printf("통과한 말의 수: P1 %d개, P2 %d개\n", passP1, passP2);
}


int playYoot(void){
    
    int i;
    
    //빽도:0, 도:1, 개:2, 걸:3, 윷:4, 모: 5
    printf("윷을 던지려면 아무키나 눌러주세요. >>>> ");
    getchar();
    i = rand() % 6;
    
    switch(i){
        case 0 :
            printf("@XXX 백도!\n");
            break;
        case 1 :
            printf("OXXX 도!\n");
            break;
        case 2 :
            printf("OOXX 개!\n");
            break;
        case 3 :
            printf("OOOX 걸!\n");
            break;
        case 4 :
            printf("OOOO 윷!\n");
            break;
        case 5 :
            printf("XXXX 모!\n");
            break;
    }
    return i;
}

void moveYoot(void){
    
    int i;
    while(1){
        i = playYoot();
        yut[i]++;
        total++;
        if(i<4) break;
    }
    getchar();
    printf("\n< 윷 던진 결과 : 총 %d회 >\n", total);
    if(yut[0])         printf("빽도: %d번 ",yut[0]);
    if(yut[1])         printf("도: %d번 ",yut[1]);
    if(yut[2])         printf("개: %d번 ",yut[2]);
    if(yut[3])         printf("걸: %d번 ",yut[3]);
    if(yut[4])         printf("윷: %d번 ",yut[4]);
    if(yut[5])         printf("모: %d번 ",yut[5]);
    printf("\n\n");
}


void moveHorse(int player){
    
    char choose;
    int number;
    
    //PLAYER 1일때
    if(player % 2){
        for(int i = 0; i < total ; i++){
            // 움직일 말 입력
            printf("움직일 말을 입력해주세요. (1P: A,B,C) : ");
            while(1){
                scanf("%s", &choose);
                if(choose == 'A' || choose == 'B' || choose == 'C'){
                    if(choose == 'A' && pA == TAIL){
                        printf("이미 홈에 도착한 말입니다. 다시 선택해주세요.\n");
                        continue;
                    }
                    if(choose == 'B' && pB == TAIL){
                        printf("이미 홈에 도착한 말입니다. 다시 선택해주세요.\n");
                        continue;
                    }
                    if(choose == 'C' && pC == TAIL){
                        printf("이미 홈에 도착한 말입니다. 다시 선택해주세요.\n");
                        continue;
                    }
                    break;
                }
                else
                    printf("잘못 입력하셨습니다. 다시 입력해주세요. : ");
            }
            //움직일 눈 갯수 입력
            printf("움직일 눈의 갯수를 입력해주세요.(빽도:0, 도:1, 개:2, 걸:3, 윷:4, 모:5) : ");
            while(1){
                scanf("%d",&number);
                if(number < 0 || number > 5)    printf("잘못 입력하셨습니다. 다시 입력해주세요. : ");
                else if(yut[number]) break;
                else    printf("잘못 입력하셨습니다. 다시 입력해주세요. : ");
            }
            goHorse1(choose, number);  // P1 실제 말을 링크드 리스트에서 이동시키는 함수
            catchEnemy1(choose);   //적을 잡았는지 체크해주고, 잡았으면 윷놀이를 하게 하는 함수
            boardStatus();
            yut[number]--;
        }// 던진 횟수만큼 말과 눈 입력 후 이동해야 종료
        total = 0;
    }
    //PLAYER 2일때
    else{
        for(int i = 0; i < total ; i++){
            // 움직일 말 입력
            printf("움직일 말을 입력해주세요. (2P: X,Y,Z) : ");
            while(1){
                scanf("%s", &choose);
                if(choose == 'X' || choose == 'Y' || choose == 'Z'){
                    if(choose == 'X' && pX == TAIL){
                        printf("이미 홈에 도착한 말입니다. 다시 선택해주세요.\n");
                        continue;
                    }
                    if(choose == 'Y' && pY == TAIL){
                        printf("이미 홈에 도착한 말입니다. 다시 선택해주세요.\n");
                        continue;
                    }
                    if(choose == 'Z' && pZ == TAIL){
                        printf("이미 홈에 도착한 말입니다. 다시 선택해주세요.\n");
                        continue;
                    }
                    break;
                }
                else
                    printf("잘못 입력하셨습니다. 다시 입력해주세요. : ");
            }
            //움직일 눈 갯수 입력
            printf("움직일 눈의 갯수를 입력해주세요.(빽도:0, 도:1, 개:2, 걸:3, 윷:4, 모:5) : ");
            while(1){
                scanf("%d",&number);
                if(number < 0 || number > 5)    printf("잘못 입력하셨습니다. 다시 입력해주세요. : ");
                else if(yut[number]) break;
                else    printf("잘못 입력하셨습니다. 다시 입력해주세요. : ");
            }
            goHorse2(choose, number);  // P1 실제 말을 링크드 리스트에서 이동시키는 함수
            yut[number]--;
            catchEnemy2(choose);   //적을 잡았는지 체크해주고, 잡았으면 윷놀이를 하게 하는 함수
            boardStatus();
            
        }// 던진 횟수만큼 말과 눈 입력 후 이동해야 종료하는 반복문
        total = 0;
    }
    
}
void goHorse1(char choose, int number){    //실제 말을 링크드 리스트에서 이동시키는 함수
    if(choose == 'A' && number != 0){
        if(pA == NULL){
            pA = HEAD;
        }
        else if(pA == LT || pA == RT || pA == C){
            pA->data = "O";
            pA = pA->shortNext;
        }
        else if(pA != NULL ){
            pA->data = "O";
            pA = pA->Next;
        }
        
        for(int i = 1; i < number; i++){
            if(pA == TAIL){
                passP1++;
                break;
            }
            pA = pA->Next;
        }
        pA->data = "A";
    }
    else if(choose == 'A' && number == 0){
        pA->data = "O";
        pA = pA->Prev;
        pA->data = "A";
    }
    
    else if(choose == 'B' && number != 0){
        if(pB == NULL){
            pB = HEAD;
        }
        else if(pB == LT || pB == RT || pB == C){
            pB->data = "O";
            pB = pB->shortNext;
        }
        else if(pB != NULL ){
            pB->data = "O";
            pB = pB->Next;
        }
        
        for(int i = 1; i < number; i++){
            if(pB == TAIL){
                passP1++;
                break;
            }
            pB = pB->Next;
        }
        pB->data = "B";
    }
    else if(choose == 'B' && number == 0){
        pB->data = "O";
        pB = pB->Prev;
        pB->data = "B";
    }
    
    else if(choose == 'C' && number != 0){
        if(pC == NULL){
            pC = HEAD;
        }
        else if(pC == LT || pC == RT || pC == C){
            pC->data = "O";
            pC = pC->shortNext;
        }
        else if(pC != NULL ){
            pC->data = "O";
            pC = pC->Next;
        }
        
        for(int i = 1; i < number; i++){
            if(pC == TAIL){
                passP1++;
                break;
            }
            pC = pC->Next;
        }
        pC->data = "C";
    }
    else if(choose == 'C' && number == 0){
        pC->data = "O";
        pC = pC->Prev;
        pC->data = "C";
    }
}
void goHorse2(char choose, int number){
    if(choose == 'X' && number != 0){
        if(pX == NULL){
            pX = HEAD;
        }
        else if(pX == LT || pX == RT || pX == C){
            pX->data = "O";
            pX = pX->shortNext;
        }
        else if(pX != NULL ){
            pX->data = "O";
            pX = pX->Next;
        }
        
        for(int i = 1; i < number; i++){
            if(pX == TAIL){
                passP2++;
                break;
            }
            pX = pX->Next;
        }
        pX->data = "X";
    }
    else if(choose == 'X' && number == 0){
        pX->data = "O";
        pX = pX->Prev;
        pX->data = "X";
    }
    
    else if(choose == 'Y' && number != 0){
        if(pY == NULL){
            pY = HEAD;
        }
        else if(pY == LT || pY == RT || pY == C){
            pY->data = "O";
            pY = pY->shortNext;
        }
        else if(pY != NULL ){
            pY->data = "O";
            pY = pY->Next;
        }
        
        for(int i = 1; i < number; i++){
            if(pY == TAIL){
                passP2++;
                break;
            }
            pY = pY->Next;
        }
        pY->data = "Y";
    }
    else if(choose == 'Y' && number == 0){
        pY->data = "O";
        pY = pY->Prev;
        pY->data = "Y";
    }
    else if(choose == 'Z' && number != 0){
        if(pZ == NULL){
            pZ = HEAD;
        }
        else if(pZ == LT || pZ == RT || pZ == C){
            pZ->data = "O";
            pZ = pZ->shortNext;
        }
        else if(pZ != NULL ){
            pZ->data = "O";
            pZ = pZ->Next;
        }
        for(int i = 1; i < number; i++){
            if(pZ == TAIL){
                passP2++;
                break;
            }
            pZ = pZ->Next;
        }
        pZ->data = "Z";
    }
    else if(choose == 'Z' && number == 0){
        pZ->data = "O";
        pZ = pZ->Prev;
        pZ->data = "Z";
    }
}
void catchEnemy1(char choose){   //적을 잡았는지 체크해주고, 잡았으면 윷놀이를 하게 하는 함수
    if(choose == 'A'){
        if(pA == pX){
            //pX->data = "O";
            pX = NULL;
            printf("상대편 말을 잡으셨습니다. 윷을 한 번 더 던집니다.\n");
            moveYoot();
        }
        else if(pA == pY){
            //pY->data = "O";
            pY = NULL;
            printf("상대편 말을 잡으셨습니다. 윷을 한 번 더 던집니다.\n");
            moveYoot();
        }
        else if(pA == pZ){
            //pZ->data = "O";
            pZ = NULL;
            printf("상대편 말을 잡으셨습니다. 윷을 한 번 더 던집니다.\n");
            moveYoot();
        }
    }
    else if(choose == 'B'){
        if(pB == pX){
            //pX->data = "O";
            pX = NULL;
            printf("상대편 말을 잡으셨습니다. 윷을 한 번 더 던집니다.\n");
            moveYoot();
        }
        else if(pB == pY){
            //pY->data = "O";
            pY = NULL;
            printf("상대편 말을 잡으셨습니다. 윷을 한 번 더 던집니다.\n");
            moveYoot();
        }
        else if(pB == pZ){
            //pZ->data = "O";
            pZ = NULL;
            printf("상대편 말을 잡으셨습니다. 윷을 한 번 더 던집니다.\n");
            moveYoot();
        }
    }
    else if(choose == 'C'){
        if(pC == pX){
            //pX->data = "O";
            pX = NULL;
            printf("상대편 말을 잡으셨습니다. 윷을 한 번 더 던집니다.\n");
            moveYoot();
        }
        else if(pC == pY){
            //pY->data = "O";
            pY = NULL;
            printf("상대편 말을 잡으셨습니다. 윷을 한 번 더 던집니다.\n");
            moveYoot();
        }
        else if(pC == pZ){
            //pZ->data = "O";
            pZ = NULL;
            printf("상대편 말을 잡으셨습니다. 윷을 한 번 더 던집니다.\n");
            moveYoot();
        }
    }
}
void catchEnemy2(char choose){   //적을 잡았는지 체크해주고, 잡았으면 윷놀이를 하게 하는 함수
    if(choose == 'X'){
        if(pX == pA){
            //pA->data = "O";
            pA = NULL;
            printf("상대편 말을 잡으셨습니다. 윷을 한 번 더 던집니다.\n");
            moveYoot();
        }
        else if(pX == pB){
            //pB->data = "O";
            pB = NULL;
            printf("상대편 말을 잡으셨습니다. 윷을 한 번 더 던집니다.\n");
            moveYoot();
        }
        else if(pX == pC){
            //pC->data = "O";
            pC = NULL;
            printf("상대편 말을 잡으셨습니다. 윷을 한 번 더 던집니다.\n");
            moveYoot();
        }
    }
    else if(choose == 'Y'){
        if(pY == pA){
            //pA->data = "O";
            pA = NULL;
            printf("상대편 말을 잡으셨습니다. 윷을 한 번 더 던집니다.\n");
            moveYoot();
        }
        else if(pY == pB){
            //pB->data = "O";
            pB = NULL;
            printf("상대편 말을 잡으셨습니다. 윷을 한 번 더 던집니다.\n");
            moveYoot();
        }
        else if(pY == pC){
            //pC->data = "O";
            pC = NULL;
            printf("상대편 말을 잡으셨습니다. 윷을 한 번 더 던집니다.\n");
            moveYoot();
        }
    }
    else if(choose == 'Z'){
        if(pZ == pA){
            //pA->data = "O";
            pA = NULL;
            printf("상대편 말을 잡으셨습니다. 윷을 한 번 더 던집니다.\n");
            moveYoot();
        }
        else if(pZ == pB){
            //pB->data = "O";
            pB = NULL;
            printf("상대편 말을 잡으셨습니다. 윷을 한 번 더 던집니다.\n");
            moveYoot();
        }
        else if(pZ == pC){
            //pC->data = "O";
            pC = NULL;
            printf("상대편 말을 잡으셨습니다. 윷을 한 번 더 던집니다.\n");
            moveYoot();
        }
    }
}
