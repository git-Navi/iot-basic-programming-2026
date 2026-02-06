// 배열 값 출력하는 함수

#include <stdio.h>

// 배열 전체를 복사해서 처리하는 함수
void print_ary(int ary[], int size);
void print_ary2(int* pa, int size);

int main(void) {
	int ary[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int ary2[5] = { 10, 20, 30, 40 };
	printf("배열로 처리\n");
	print_ary(ary, 10);

	printf("포인터로 처리\n");
	print_ary2(ary, sizeof(ary) / sizeof(ary[0]));
	print_ary2(ary2, 5);

	return 0;
}

void print_ary(int ary[], int size) {
	int i;

	for (i = 0; i < size; i++) {
		printf("%5d", ary[i]);
	}
	printf("\n");
}

void print_ary2(int* pa, int size) {
	int i;

	for (i = 0; i < size; i++) {
		printf("%5d", *(pa + i));
		//printf("%5d", pa[i]); // 배열의 요소처럼도 사용 할 수 있다!
	}
	printf("\n");
}