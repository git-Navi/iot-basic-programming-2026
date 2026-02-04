// for문

#include <stdio.h>

int main() {
	/*
	* for (초기화; 조건; 증감) {
	*		반복할 실행문
	* }
	*/
	int a = 1;
	int i = 0;
	for (i = 0; i < 4; i++) {
		// 초기화 : i = 0
		// 조건 : i < 3
		// 증감 : a++
		a = a * 2;
	}
	printf("a : %d\n", a);

	// $를 10번 출력하기!
	for (i = 0; i < 10; i++) {
		printf("$");	// printf("%c", '$'); 결과는 동일함. 콘솔에 출력하는 건 똑같다.
	}
	printf("\n");	// 줄바꿈

	int i, j;

	// 이중 for문
	for (i = 0; i < 3; i++) {	// 바깥쪽 for문
		for (j = 0; j < 5; j++) {	// 안쪽 for문
			printf("%s", "*");
		}
		printf("\n");	// 한 줄 출력 후 줄바꿈
	}

	return 0;
}