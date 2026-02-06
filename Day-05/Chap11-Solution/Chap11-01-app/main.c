// 문자

#include <stdio.h>

int main(void) {
	char small, cap = 'G';

	if ((cap >= 'A') && (cap <= 'Z')) {	// 65 ~ 90 사이라면
		//small = cap + 32;
		small = cap + ('a' - 'A');	// 97 - 65 => 32 'z' - 'Z'
	}

	printf("대문자 : %c\n", cap);
	printf("소문자 : %c\n", small);
	
	return 0;
}