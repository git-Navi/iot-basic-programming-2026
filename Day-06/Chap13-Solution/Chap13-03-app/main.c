// 값 복사 전달 & 주소 복사
// return 값을 포인터변수로 받기!

#include <stdio.h>

// void add_ten(int);
int add_ten(int);

void plus_ten(int*);	// 매개변수로 포인터 선언

int* sum(int, int);	// 매개변수는 일반변수, 리턴은 포인터변수

int main(void) {
	int a = 100;
	int* result;

	a  = add_ten(a);
	printf("a = %d\n", a);
	
	plus_ten(&a);
	printf("a = %d\n", a);

	result = sum(40, 60);	// 정적변수 res의 주소를 돌려받음.
	printf("*result = %d\n", *result);

	return 0;
}

// 값 복사 후, return 없으면 값 사라짐.
//void add_ten(int num) {
//
//	num = num + 10;
//
//	return num;
//}

int add_ten(int num) {

	num = num + 10;

	return num;
}

void plus_ten(int* pa) {
	*pa = *pa + 10;
}

int* sum(int a, int b) {
	static int res;	// 정적 지역변수, static을 써서 sum 함수가 끝나도 변수가 사라있도록 하겠다는 의미.

	res = a + b;

	return &res;	// 정적변수의 주소를 반환
}
