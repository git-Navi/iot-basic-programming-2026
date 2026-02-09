// 지역변수, 전역변수, 정적변수

#include <stdio.h>

void assign(void);

int a;	// 전역변수, global이라고 안씀. 그냥 설명용임.

int main(void) {
	
	auto int a = 0;          // 지역변수, auto는 생략 가능! (int a = 0;)
	int b = 20;

	assign();
	printf("main 함수 a : %d\n", a);

	printf("교환 전 : %d, %d\n", a, b);
	{
		int a = 0, b = 0, temp;	// 블록 내 지연변수가 우선적으로 쓰인다.
		temp = a;
		a = b;
		b = temp;
	}

	printf("교환 후 : %d, %d\n", a, b);
	
	return 0;
}

void assign(void) {
	int a;

	a = 100;
	printf("assign 함수 a : %d\n", a);
}