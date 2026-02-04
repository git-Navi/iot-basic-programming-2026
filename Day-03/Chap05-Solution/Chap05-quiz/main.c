// 별 찍기 예제
/*
		******
		******
		******
		******
		******
		
		*
		**
		***
		****
		*****
	
*/


#include <stdio.h>

int main() {

	int i, j, k;

	// 5x5 별 찍기
	for (i = 0; i < 5; i++) {
		// 반복문의 조건만 조절하면 대부분 답이 나옴!
		for (j = 0; j < 6; j++) {
			printf("*");
		}
		printf("\n");
	}
	
	printf("\n");

	// 오른쪽 아래 삼각형 별 찍기
	for (i = 1; i <= 5; i++) {
		for (j = 1; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}

	printf("\n");

	// 오른쪽 아래 역삼각형 별 찍기
	for (i = 1; i <= 5; i++) {

		// k <= 5 - i 핵심!
		for (k = 1; k <= 5 - i; k++) {
			printf(" ");	// 빈 공백 추가!
		}

		for (j = 1; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}

	printf("\n");

	// 엑스 모양 별 찍기
	for (i = 5; i >= 1; i--) {
		for (k = 1; k <= 5 - i; k++) {
			printf(" ");
		}

		for (j = 1; j <= 2 * i - 1; j++) {
			printf("*");
		}
		printf("\n");
	}


	return 0;
}