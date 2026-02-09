// 14장 3번 퀴즈

#include <stdio.h>

int main(void) {

	char mark[5][5] = { 0 };
	int i, j;

	/*for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (i == j) mark[i][j] = 'X';
		}
	}*/

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			// 배열 X 찍기
			// 아래 수식만 수정하면 대각선 찍기, 별표찍기, 테두리찍기, 십자가 찍기도 가능함.
			if (i == j || i + j == 4) mark[i][j] = 'X';
		}
	}

	// 결과 출력
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {

			if (mark[i][j] != 0) {
				printf("[%c]", mark[i][j]);
			} else {
				printf("[ ] ");
		}
	}
		printf("\n");
	}
	

	return 0;
}