// 입력용 소스코드

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// extern!! 외부에 있는 것을 가져와라!!
extern int count;	// main.c에 선언한 변수 공유
int total;			// 전역변수

int input_data(void) {
	int pos;

	while (1) {
		printf("양수 입력 : ");
		scanf("%d", &pos);

		if (pos < 0) {
			break;
		}

		count++;
		total += pos;	// 합산
	}

	return total;
}