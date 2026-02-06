// 문자열과 포인터

#include <stdio.h>

int main(void) {
	// 문자열 출력
	printf("%s\n", "apple");

	// 문자열 주소 확인
	printf("%u\n", "apple");

	printf("두번째 문자 주소 %u\n", "apple"+1);
	printf("첫 번째 문자 %c\n", *("apple"));
	printf("두 번째 문자 %c\n", *("apple" + 1));
	printf("첫 번째 문자 %c\n", "apple"[0]);
	printf("첫 번째 문자 %c\n", "apple"[5]);	// \0 출력 되는거임.

	char fruit[6] = "apple";

	// 문자열 주소 확인
	printf("%u\n", fruit);

	printf("두번째 문자 주소 %u\n", fruit + 1);
	printf("첫 번째 문자 %c\n", *(fruit));
	printf("두 번째 문자 %c\n", *(fruit + 1));
	printf("첫 번째 문자 %c\n", fruit[0]);
	printf("첫 번째 문자 %c\n", fruit[5]);	// \0 출력 되는거임.
	
	return 0;
}