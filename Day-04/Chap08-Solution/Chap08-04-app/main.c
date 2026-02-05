// 문자열 입력
// 공백 허용하는 문자열 입력
// 문자열 전용 입출력 함수 : gets, puts

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char str[80];
	char str2[5];

	printf("문자열 입력 : ");
	//scanf("%s", str);
	gets(str);

	printf("입력한 문자열 :");
	puts(str);

	str2[0] = 'P';
	str2[1] = 'K';
	str2[2] = '\0';	// 배열 요소로 문자열을 넣을 때는 마지막 요소에 반드시 \0(null)를 입력
	printf("%s\n", str2);

	return 0;
}