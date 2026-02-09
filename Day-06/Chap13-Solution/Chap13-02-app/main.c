// 정적 변수

#include <stdio.h>

void auto_func(void);	// 일반 지역변수
void static_func(void);	// 정적 지역변수

int main(void) {
	int i;

	printf("일반 지역변수 사용 함수 호출\n");
	for (i = 0; i < 3; i++) {
		auto_func();
	}

	printf("정적 지역변수 사용 함수 호출\n");
	for (i = 0; i < 3; i++) {
		static_func();
	}

	return 0;
}

void auto_func(void) {
	// auto_func가 한 번 호출 될때 생성되고 함수가 종료될 때 메모리에서 사라진다.
	auto int a = 0;	// auto, 0으로 초기화

	a++;
	printf("%d\n", a);
}

void static_func(void) {
	// static은 return 0에서 만날때까지 살아있음.
	// main.c가 처음 시작될 때 메모리 올라갔다가, main.c가 종료될 때 메모리에서 사라진다.
	static int a;	// static, 0으로 자동 초기화, 초기화 써도 됨.

	a++;
	printf("%d\n", a);
}