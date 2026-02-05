// 포인터, 간접참조연산자

#include <stdio.h>

int main(void) {
	int a;	// 일반 변수
	int* pa;	// 포인터 변수

	// 포인터 변수는 다른 변수의 주소를 대입(할당)하는 변수
	pa = &a;	// a의 주소를 포인터 변수 pa에 대입
	// !!! 포인터가 가리키는 변수에다가 값을 할당한다 !!!
	*pa = 100;

	printf("a 값 출력 : %d\n", a);
	printf("pa가 가르키고 있는 값 : %d\n", *pa);

	// a의 주소
	printf("변수 a의 주소 : %u\n", &a);
	printf("포인터변수 pa의 값 : %u\n", pa);

	return 0;
}