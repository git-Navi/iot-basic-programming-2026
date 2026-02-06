// 배열과 포인터 차이

#include <stdio.h>

int main(void) {
	int ary[3] = { 0 };
	int* pary = ary;
	int i = 0;

	printf("배열의 크기 : %zu\n", sizeof(ary));
	printf("포인터의 크기 : %zu\n", sizeof(pary));

	for (i = 0; i < 3; i++) {
		printf("%5d", *(pary + i));
	}

	return 0;
}