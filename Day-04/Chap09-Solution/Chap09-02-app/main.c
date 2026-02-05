// 변수의 주소

#include <stdio.h>

int main(void) {
	int a = 100;		// int형 변수 선언 (4bytes)
	double b = 300;	// double형 변수 선언 (8bytes)
	char c = 12;		// char형 변수 선언 (1byte)

	printf("int형 변수 a의 주소 : %u\n", &a);	// 주소연산자
	printf("double형 변수 b의 주소 : %u\n", &b);	// 주소연산자
	printf("char형 변수 c의 주소 : %u\n", &c);	// 주소연산자


	return 0;
}