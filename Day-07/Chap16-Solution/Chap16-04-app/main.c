// 동적할당 예제

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char temp[80];	// 최대 길이 80까지 받을 수 있는 문자열
	char* str[3];	// 동적할당할 포인터 배열
	int i;

	for (i = 0; i < 3; i++) {
		printf("문자열 입력 : ");
		gets(temp);	// 공백 포함 문자열 입력
		//printf("입력한 문자열 : %s\n", temp);
		str[i] = (char*)malloc(strlen(temp) + 1);	// hello\ + 74 쓰레기 공간 -> 6byte로만 동적할당.
		strcpy(str[i], temp);
	}

	for (i = 0; i < 3; i++) {
		printf("%s\n", str[i]);
	}

	// free 메모리 해제 (반환)
	for (i = 0; i < 3; i++) {
		free(str[i]);	// free 안하면 memory leak(메모리 누수) 발생
	}

	return 0;
}