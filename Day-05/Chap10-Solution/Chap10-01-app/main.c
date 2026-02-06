// 배열과 포인터
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int ary[3];
	int i;

	// 기존의 배열 사용법
	ary[0] = 10;
	ary[1] = 20;
	ary[2] = ary[0] + ary[1];

	for (i = 0; i < 3; i++) {
		printf("%5d\n", ary[i]);
	}

	printf("\n");

	// 배열의 주소 &ary[0] == ary
	printf("배열 ary의 주소 : %zu\n", ary);	// 배열의 이름은 배열의 주소
	printf("배열 ary[0]의 주소 : %zu\n", &ary[0]); // 첫번째 배열요소 주소와 동일

	printf("배열 ary[1]의 주소 : %zu\n", &ary[1]); // 두번째 배열요소 주소
	printf("배열 ary[2]의 주소 : %zu\n", &ary[2]); // 세번째 배열요소 주소

	// 포인터로 동일한 기능 사용법
	*(ary + 0) = 100;	// == ary[0]
	*(ary + 1) = 200;	// == ary[1]
	*(ary + 2) = *(ary + 0) + *(ary + 1);	// == ary[2]

	for (i = 0; i < 3; i++) {
		printf("%5d", *(ary + i));
	}
	printf("\n");

	// 배열요소에 일반형식으로 키보드 입력
	printf("정수 입력 : ");
	scanf("%d", &ary[2]);
	printf("%d\n", ary[2]);

	// 배열요소 포인터형식으로 입력
	printf("정수 입력 : ");
	scanf("%d", ary + 2);
	printf("%d\n", *(ary + 2));
	
	return 0;
}

