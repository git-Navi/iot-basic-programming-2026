// 구조체 사용
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct profile {
	char name[20];	// 이름
	int age;		// 나이
	double height;	// 키
	char* intro;	// 자기소개 입력받는 포인터
};

int main(void) {
	struct profile one;

	strcpy(one.name, "홍길동");
	one.age = 19;
	one.height = 170.3;

	// 다른 변수의 주소를 담거나!
	// 동적 할당으로 사이즈를 잡아야함!
	one.intro = (char*)malloc(80);
	printf("자기소개 입력 : ");
	gets(one.intro);	// 할당한 공간에 자기소개 입력

	// 입력된 값 데이터 출력
	printf("프로필 출력\n");
	printf("이름 : %s\n", one.name);
	printf("나이 : %d\n", one.age);
	printf("키 : %.1f\n", one.height);
	printf("자기소개 : %s\n", one.intro);

	free(one.intro);

	return 0;
}