// 문자열과 포인터, 문자열 함수
// strcpy, strcat, strle, strcmp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>	// 문자열 함수를 사용하기 위한 헤더 파일

int main(void) {
	char str1[80] = "strawberry";
	char str2[80] = "apple";
	char* ps1 = "banana";
	char* ps2 = str2;

#pragma region strcpy() 함수 영역

	printf("strcpy() 함수 사용\n");

	printf("최초 문자열 : %s\n", str1);
	strcpy(str1, str2);	// str1에 str2 문자열을 복사하라.
	printf("바뀐 문자열 : %s\n", str1);

	strcpy(str1, ps1);	// str1에 ps1 문자열을 복사하라.
	printf("바뀐 문자열 : %s\n", str1);

	strcpy(str1, ps2);	// str1에 ps2 문자열을 복사하라.
	printf("바뀐 문자열 : %s\n", str1);

	strcpy(str1, "applemango");	// 문자열 상수도 가능!
	printf("바뀐 문자열 : %s\n", str1);

	// str2 = "apple"	// 문자 배열은 값 변경 불가능, strcpy 
	ps2 = "apple";	// 문자 포인터는 값 변경 가능.

#pragma endregion

#pragma region strncpy() 함수 영역

	printf("strncpy() 함수 사용\n");

	// strncpy() 원하는 개수의 문자 복사하는 함수
	char str3[20] = "mango tree";

	strncpy(str3, "apple-pie", 5);	// apple-pie에서 5글자만 복사한다.
	printf("바뀐 문자열 : %s\n", str3);

#pragma endregion

#pragma region strcat, strncat() 함수

	printf("strcat(), strncat() 함수 사용\n");

	// string concatenate()	- 문자열 연결 함수
	char str4[80] = "straw";
	strcat(str4, "berry");
	printf("바뀐 문자열 : %s\n", str4);

	strncat(str4, "piece", 3);	// str4 배열에 piece중, 세글자 pie만 결합한다.
	printf("바뀐 문자열 : %s\n", str4);

#pragma endregion

#pragma region strlen() 함수

	printf("strlen() 함수 사용\n");

	printf("str1 %s, 글자 길이는 %zu\n", str1, strlen(str1));
	strcpy(str1, "애플 망고");
	// C에서 한글 글자는 한 글자당 길이를 '2'로 지정한다.
	printf("str1 %s, 글자 길이는 %zu\n", str1, strlen(str1));

#pragma endregion

#pragma region strcmp(), strncmp() 함수

	// 문자열 비교 함수
	printf("strcmp(), strncmp() 함수 사용\n");

	char str5[80] = "pear";
	char str6[80] = "peach";

	printf("사전에 나중에 나오는 과일 : ");
	// strcmp(str5, str6) -> 결과는 1(str5가 str6보다 사전에 나중에 나온다.), 0(같은 문자열), -1(str5가 str6보다 사전에 먼저 나온다.)
	// printf("%d", strcmp(str5, str6));	// 1

	if (strcmp(str5, str6) > 0) {
		printf("%s\n", str5);
	}
	else if (strcmp(str5, str6) == 0) {
		printf("%s 같은 단어입니다.\n", str5);
	}
	else {
		printf("%s\n", str6);
	}

	int result = strncmp(str5, str6, 3);	// pear랑 peach를 비교하는데 3글자만 비교하는 것. (pea, pea)

	if (result == 0) {
		printf("0, 앞 3글자가 동일합니다.");
	}
	else if (result < 0) {
		printf("-1, %s < %s\n", str5, str6);	// str5가 먼저 나옴.
	}
	else {
		printf("1, %s > %s\n", str5, str6);		// str6가 먼저 나옴.
	}

#pragma endregion


	return 0;
}