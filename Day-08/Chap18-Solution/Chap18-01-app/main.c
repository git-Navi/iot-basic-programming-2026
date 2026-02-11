// 파일 입출력
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	FILE* fp;	// 파일 포인터

	// 파일을 열면?
	fp = fopen("test.txt", "r");	// r 읽기, w 쓰기, a 내용추가
	if (fp == NULL) {
		printf("파일이 열리지 않았습니다.\n");
		exit(1);
	}

	printf("파일이 열렸습니다.\n");

	// 닫아야 함.
	fclose(fp);	// free와 동일함.

	return 0;
}