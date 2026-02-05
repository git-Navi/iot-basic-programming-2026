// 포인터 이전 로컬 변수, 변수 스코프

#include <stdio.h>

void func(void);

void add(int);	// 매개변수 값을 100 더하는 함수

int x = 10;	// 전역변수 (Global Variable)

int main(void) {
	// 기본 변수 스코프
	int x = 30;
	printf("main x = %d\n", x);
	func();
	printf("main x = %d\n", x);

	// 블록 스코프
	int a = 1;

	if (a == 1) {
		int b = 2;
		printf("블록 내부 : a=%d, b=%d\n", a, b);
	}

	printf("블록 외부 : a=%d\n", a);
	//printf("b=%d\n", b);	// 블록내부에서 선언한 변수 b는 블록 밖에서 사용 불가!! 컴파일 에러남!!

	// 함수 스코프
	int y = 10;
	add(y);
	printf("y = %d\n", y);

	return 0;
}

void func(void) {
	int x = 20;	// 지역변수 (Local Variable)

	printf("func x = %d\n", x);
}

void add(int x) {
	x = x + 100;
}