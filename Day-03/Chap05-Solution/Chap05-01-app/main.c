// 제어문 - 선택문/분기분
// 선택에 따라 로직이 다르게 실행되는 것.

// if (조건이 참) {
//		~ 참 조건 로직 수행 ~
// } else {	// 옵션
//		~ 거짓 조건 로직 수행 ~
// }

// if ... : // 파이썬은 {} 사용 안함!

#include <stdio.h>	// 표준 입출력 헤더파일 printf, scanf

int main() {

	int a = 10, b = 0;

	if (a > 10) {	// 참인 조건
		b = a;
	}
	else {			// 거짓인 조건
		b = 1000;
	}

	if (a > 10) {
		b = 1;
	}
	else if (a == 0) {
		b = 2;
	}
	else {
		b = 3;
	}

	printf("a : %d, b : %d\n", a, b);

	int age = 20;
	int gender = 1;	// 1은 남자, 0은 여자

	if (age > 12) {
		if (gender == 1) {
			printf("'남탕, 성인입니다. 2.0'\n");
		}
		else {
			printf("'여탕, 성인입니다. 2.0'\n");
		}
	}
	else {
		if (gender == 1) {
			printf("'남탕, 소인입니다. 1.2'\n");
		}
		else {
			printf("'여탕, 소인입니다. 1.2'\n");
		}
	}

	// int 리턴 타입이 있으니까...
	return 0;
}