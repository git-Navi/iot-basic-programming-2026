// void 포인터

#include <stdio.h>

int main(void) {
	int a = 10;
	double b = 3.5;

	void* vp;	// void 포인터 선언
	int* pa;
	double* pb;
	
	// 추가적 내용
	//int* pi = (int*)vp; // 대입연산에서는 형변환을 안써도 오류X. 단, 명시적.

	vp = &a;
	printf("a : %d\n", *(int*)vp);	// vp를 int*로 변경 후 사용

	vp = &b;
	printf("b : %.1f\n", *(double*)vp);	// vp를 double*로 변경 후 사용

	pa = &b;	// 이전에 본 내용, double형을 int*에 할당
	printf("pa : %.1f\n", *pa);	// vp를 int*로 변경 후 사용

	return 0;
}