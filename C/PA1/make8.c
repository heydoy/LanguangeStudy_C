/********************************

* 이름 : KIM DOY
* 날짜 : 2 MAY 2020
* 내용 : 물 8리터 만들기 게임
*********************************/


#include <stdio.h>

int main(void){

        //물통안에 든 물의 양 
        int jug_a = 5;
        int jug_b = 0;
        int jug_c = 6;

        //물통별 용량
        int A = 10;
        int B = 5;
        int C = 6;

        //사용자에게 입력받는 숫자
        /*밑에 do-while문 조건때문에 임의로 1로 초기화함 */
        int x = 1;
        int y = 1;

        //물병 1(jug_a)가 8리터가 되기전까지 반복하는 반복문
        while(1){

                //물병 보여주기 전에 한칸 띄워서 가독성 높여주기
                printf("\n");

                // 물병 3개의 상태를 출력하는 반복문
                for(int i = 10 ; i >= 0 ; i--){

                        if( i > 6 ){
                                if( jug_a == i )
                                        printf("|-----|");

                                else
                                        printf("|     |");
                        }
                        else if( i == 6 ){
                                if(jug_a == i )
                                        printf("|-----|");
                                else
                                        printf("|     |");

                                printf("  ");
                                printf("       ");
                                printf("  ");

                                if(jug_c == i)
                                        printf("|-----|");
                                else
                                        printf("|     |");
                        }
                        else if( i < 6  && i > 0 ){
                                if(jug_a == i)
                                        printf("|-----|");
                                else
					printf("|     |");

                                printf("  ");
                                if(jug_b == i)
                                        printf("|-----|");
                                else
                                        printf("|     |");
                                printf("  ");
                                if(jug_c == i)
                                        printf("|-----|");
                                else
                                        printf("|     |");

                        }
                        else{
                                // 바닥면
                                printf("+-----+");
                                printf("  ");
                                printf("+-----+");
                                printf("  ");
                                printf("+-----+");
                        }
                        printf("\n");
                }
                //물병 상태 보여주기 끝
                //물병 1(jug_a)는 8L이면 반복문 종료
                if(jug_a == 8)
                        break;

                //사용자에게 입력받는 명령처리
                do{
                        printf("\nEnter a command : ");
                        scanf("%d %d", &x, &y);

                        //x,y가 1,2,3이 아니면 에러 메시지 띄우기
                        if( x < 1 || x > 3 || y < 1 || y > 3)
                                printf("Error!\n");
                                continue;

                }while( x < 1 || x > 3 || y < 1 || y >3);
                //x,y가 둘다 1,2,3 이면 명령처리 반복을 종료


                //만약 x,y를 같은 숫자로 적었을 경우에는
                //물병 상태를 보여주고 명령을 받기(맨위로)
                if(x==y)
                        continue;

                //x는 물병1번(=jug_a)일 때
                if(x==1){
                        //물병이 비었으면 물병상태를 보여주고 명령받기(맨위로)
                        if(jug_a == 0)
                                continue;

                        //y가 물병 2번(=jug_b), 물병 3번(=jug_c)일 경우 체크
                        if(y == 2){
                                if(jug_a + jug_b <= B){
                                        jug_b += jug_a;
                                        jug_a = 0;
				}
				else{
                                        jug_a = (jug_a + jug_b) - B;
                                        jug_b = B;
                                }
                        }
                        else if(y == 3){
                                if(jug_a + jug_c <= C){
                                        jug_c += jug_a;
                                        jug_a = 0;
                                }
                                else{
                                        jug_a = (jug_a + jug_c) - C;
                                        jug_c = C;
                                }

                        }
                }
                //x는 물병2번(=jug_b)일 때
                else if(x==2){
                        //물병이 비었으면 물병상태를 보여주고 명령받기(맨위로)
                        if(jug_b == 0)
                                continue;

                        //y가 물병 1번(=jug_a), 물병 3번(=jug_c)일 경우 체크
                        if(y == 1){
                                if(jug_b + jug_a <= A){
                                        jug_a += jug_b;
                                        jug_b = 0;
                                }
                                else{
                                        jug_b = (jug_b + jug_a) - A;
                                        jug_a = A;
                                }
                        }
                        else if(y == 3){
                                if(jug_b + jug_c <= C){
                                        jug_c += jug_b;
                                        jug_b = 0;
                                }
                                else{
                                        jug_b = (jug_b + jug_c) - C;
                                        jug_c = C;
                                }

                        }

                }
                //x는 물병3번일때
                //위에서 걸렀기 때문에 else는 3번인경우만 됨
                else{
                        //물병이 비었으면 물병상태를 보여주고 명령받기(맨위로)
                        if(jug_c == 0)
                                continue;
			//y가 물병 1번(=jug_a), 물병 2번(=jug_b)일 경우 체크
                        if(y == 1){
                                if(jug_c + jug_a <= A){
                                        jug_a += jug_c;
                                        jug_c = 0;
                                }
                                else{
                                        jug_c = (jug_c + jug_a) - A;
                                        jug_a = A;
                                }
                        }
                        else if(y == 2){
                                if(jug_c + jug_b <= B){
                                        jug_b += jug_c;
                                        jug_c = 0;
                                }
                                else{
                                        jug_c = (jug_c + jug_b) - B;
                                        jug_b = B;
                                }

                        }

                }

        }

        //8리터 축하메시지 + 종료
        printf("\nCongratulations! You've got 8-liter water!\n");
        return 0;
}

