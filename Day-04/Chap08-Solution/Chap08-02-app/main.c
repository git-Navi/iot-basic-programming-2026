// 성적처리 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int score[5];
	int i;
	int total = 0;
	double avg = 0.0;

	//printf("배열 총 바이트 크기 %zu\n", sizeof(score));
	//printf("배열 요소 하나의 크기 %zu\n", sizeof(int));
	//printf("배열 요소 하나의 크기 %zu\n", sizeof(score[0]));	// == sizeof(int)
	//printf("배열의 사이즈 %zu\n", sizeof(score) / sizeof(score[0]));
	int count = sizeof(score) / sizeof(score[0]);

	// 키보드로 성적 입력
	for (i = 0; i < count; i++) {
		scanf("%d", &score[i]);	// 배열의 각 요소에 성적 입력
	}

	// 합산
	for (i = 0; i < count; i++) {
		total = total + score[i];
	}
	avg = total / (double)count;

	// 각 성적 출력
	for (i = 0; i < count; i++) {
		printf("%5d", score[i]);
	}
	printf("\n");
	printf("총점 : %d\n", total);
	printf("평균 : %.1f\n", avg);

	return 0;
}