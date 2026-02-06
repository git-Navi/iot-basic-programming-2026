// 포인터 계속

#include <stdio.h>

// & (Ampersand, and) 
// * (Asterik, star)

int main(void) {
	int a = 10, b = 15, total; // 변수 선언 및 초기화 (a, b)
	double avg;          // 평균값 변수 선언 (avg)

	// 포인터 변수
	// 포인터는 주소를 담는 변수
	int* pa, * pb;
	int* pt = &total;
	double* pg = &avg;

	pa = &a;	// a의 주소를 pa에 대입한다.
	// *pa = *&a = a; // pa가 가리키는 곳에 a의 값 10 대입한다.
	pb = &b;	// b의 주소를 pb에 대입한다.

	// 원래는 total = a + b; avg = total / 2.0;
	// 대신 포인터 변수로 위의 작업을 대체한다.
	
	// *pa -> 변수의 주소가 가지고 있는 값
	// pa -> a 변수의 주소

	*pt = *pa + *pb;	// total = a + b와 동일
	*pg = *pt / 2.0;		// avg = total / 2.0과 동일

	// 결과 출력
	printf("a = %d, b = %d, total = %d, avg = %.2f\n", a, b, total, avg);

	printf("*pa = %d, *pb = %d, *pt = %d, *pg = %.2f\n", *pa, *pb, *pt, *pg);

	return 0;
}