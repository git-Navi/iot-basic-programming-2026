// 구조체

#include <stdio.h>

// 구조체 선언
struct student {
	int num;		// 구조체 멤버, 학번
	double grade;	// 멤버 학점
	//char name[20];
	//double height;
	//double weight;
};	// 세미콜론 필수

int main(void) {

	struct student st1;	// 구조체 student형 변수로 선언

	st1.num = 2;
	st1.grade = 4.5;

	printf("학번 : %d\n", st1.num);
	printf("학점 : %.1f\n", st1.grade);

	return 0;
}