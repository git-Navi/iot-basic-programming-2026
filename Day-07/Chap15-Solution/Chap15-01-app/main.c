// 함수 포인터
// 함수도 변수처럼 주소를 가짐. 포인터로 활용 가능

#include <stdio.h>

int sum(int, int);
int sub(int, int);
int mul(int, int);
int div(int, int);

int main(void) {
	int (*fp)(int, int);	// 함수 포인터 선언! 매개변수 타입과 갯수가 일치해야한다.
	int res;

	fp = sum;	// 배열의 이름만 적으면 주소, 함수의 이름만 적으면 주소를 뜻한다.
	//res = sum(10, 20);	// 일반적인 방식으로 함수 호출
	res = fp(10, 20);	// 함수 포인터로 함수 호출!
	printf("덧셈 결과 : %d\n", res);

	fp = sub;	// 함수 주소를 변경해서 fp가 뺄셈을 할 수 있게 변경
	res = fp(20, 10);
	printf("뺄셈 결과 : %d\n", res);

	fp = mul;	// 함수 주소를 변경해서 fp가 곱셈을 할 수 있게 변경
	res = fp(20, 10);
	printf("곱셈 결과 : %d\n", res);

	fp = div;	// 함수 주소를 변경해서 fp가 뺄셈을 할 수 있게 변경
	res = fp(10, 2);
	printf("나누기 결과 : %d\n", res);

	return 0;
}

int sum(int x, int y) {
	return x + y;
}

int sub(int x, int y) {
	return x - y;
}

int mul(int x, int y) {
	return x * y;
}

int div(int x, int y) {
	return x / y;
}