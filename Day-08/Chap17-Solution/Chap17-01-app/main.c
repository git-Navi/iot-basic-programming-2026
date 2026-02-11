// 구조체
#include <stdio.h>

#pragma pack(1)	// 패딩 바이트를 사용 안하면 17byte만 사용한다.

struct student {
	char ch1;	// 1
	short num;	// 2
	char ch2;	// 1
	int score;	// 4byte
	double grade;	// 8byte
	char ch3;	// 1
};

int main(void) {

	struct student st1;

	// 실제 사용되는 바이트는 12byte, 하지만 패딩 바이트로 16byte로 구성
	// student 총 17byte -> 실제 32byte 사용
	printf("구조체 student 크기 : %zu\n", sizeof(st1));
	// 구조체에 선언하는 멤버변수의 위치만 조정해도 패딩 바이트가 사라짐 -> 24byte

	return 0;
}