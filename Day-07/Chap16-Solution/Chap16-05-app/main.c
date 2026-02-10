// 동적할당문자열 처리 함수 사용

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char temp[81];	// 최대 80자 입력 임시 문자열
	char* str[21] = { 0 };	// 최대 21자
	int i = 0;

	while (i < 20) {	// 20개까지 입력
		printf("문자열 입력 : ");
		gets(temp);

		if (strcmp(temp, "end") == 0) {
			break;	// 문자열 end 입력하면 중간에 입력 종료
		}

		str[i] = (char*)malloc(strlen(temp) + 1);	// \0까지 포함. 동적메모리할당
		strcpy(str[i], temp);
		i++;
	}

	// 입력 문자열 출력 함수
	print_str(str);	// str 전체를 매개변수로 전달

	print_str2(str, i);
	
	for (i = 0; str[i] != NULL; i++) {
		free(str[i]);	// 메모리 해제
	}

	return 0;
}

void print_str(char** ps) {
	// Day-06 이중 포인터에서 print_str(char**, int)와 비교!
	while (*ps != NULL) {
		printf("%s\n", *ps);
		ps++;
	}
}

void print_str2(char** ps, int count) {
	int i;

	for (i = 0; i < count; i++) {
		printf("# %s\n", *(ps + i));
	}
}