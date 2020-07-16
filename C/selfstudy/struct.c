/*
 *  구조체(Struct)
 *  구조체란 자료형이 상이한 복수의 멤버들을 하나의 자료로 무무어서 처리하는 복합자료형(Complex Data Type)이다. 
 *  e.g.)
 *  struct{
 *  	char name[10];
 *  	int grade;
 *  	char major[20];
 *  } Student;
 *
 *  위는 이름, 학년, 전공 세개의 멤버를 갖는 Student 구조체를 정의하는 선언문이다.
 *  구조체변수가 자신의 멤버를 지시할 경우 점(.)연산자를 사용하고 등호를 이용하여 초기화한다. 
 *  e.g.) 
 *  strcpy(student.name, "Park");
 *  student.grade = 3;
 *  strcpy(student.major, "Computer Science");
 *
 *  Student Kim; // 오류
 *
 *  위 선언문은 구조체 변수 자체를 선언한 것으로 구조체 자료형이 아니므로, Student를 통하여 다른 구조체 변수를 선언할 수 없다. 
 */


/*
 * 구조체 자료형 선언!!
 * 구조체 자료형을 정의하기 위해서는 c언어에서 제공하는 "typedef" 키워드를 사용한다.
 * 구조체 자료형 선언문에서 이름의 위치에 ㄸㅏ라 구조체 변수 선언시 struct가 필요할 수도.
 * e.g.)
 * typedef struct Student{
 * char name[10];
 * int grade;
 * char major[20];
 * };
 * struct Student Kim, Lee;
 */


/*
 * 구조체의 할당과 비교
 * 구조체 변수간에 직접적인 할당(Assignment) 명령문은 허용된다.
 * e.g.)
 * struct Student Kim, Lee;
 * Kim = Lee; //적합
 *
 * 그러나 구조체 변수간 직접비교(eqality operation)는 허용되지 않으며 
 * 다음 함수와 같이 두 구조체의 멤버간 개별 비교를 해주어야 한다. 
 * if(kim==lee) ... // <-- 오류 
 *
 * strcmp 함수는 두 인자 값이 다를 경우 1을 반환하고 같을 경우 0을 반환한다.
 *
 * e.g.)
 * int student_equal( struct Student Kim, struct Student Lee){
 * 	if(strcmp(Kim.name, Lee.name)) //값이 다르면 1을 반환
 * 		return FALSE;
 * 	if(Kim.age != Lee.age)
 * 		return FALSE;
 * 	if(Kim.grade != Lee.grade)
 * 		return FALSE;
 * 	}
 * 
 * 구조체에 ㄸㅗ 다른 구조체가 멤버로 포함되는 것을
 * 내장형 구조체(Embeded Structure)라고 한다.
 */


// 프로그램 2.1 구조체의 생성
#define _CRT_SECURE_NO_WARNINGS		//strcpy보안경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <string.h>	//strcpy함수가 선언된 헤더파일


//구조체 자료형 선언
typedef struct Contact_type{
	char phone[20];
	char email[20];
	char address[20];
};

typedef struct Student{
	char name[20];
	int age;
	char major[20];
	int grade;
	struct Contact_type contact;	//내장형 구조체 

};

int main(void){
	
	struct Student Amy;

	strcpy(Amy.name, "Amy Wong");
	Amy.age = 22;
	strcpy(Amy.major, "Computer Science");
	Amy.grade = 3;
	strcpy(Amy.contact.phone, "010-0101-2323");
	strcpy(Amy.contact.email, "wongwong@sm.ac.kr");
	strcpy(Amy.contact.address, "Yongsan, Seoul");

	printf("name : %s\nage : %d\nmajor : %s\ngrade : %d\nphone : %s\nemail : %s\naddress: %s\n", Amy.name, Amy.age, Amy.major, Amy.grade, Amy.contact.phone, Amy.contact.email, Amy.contact.address);
	

	return 0;
}
