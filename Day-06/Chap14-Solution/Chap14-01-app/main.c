// 다차원 배열과 포인터 배열
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	// int score[3][4];	// 4bytes * 3 * 4 = 48bytes
	int score[3][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
	};
	//int score[3][4] = { 0 };	// 모두 0으로 초기화
	int total;
	double avg;

	char animal[5][20];	// 동물 5마리, 이름 길이 20자
	int count;

	int i, j;	// 2중 for문 변수

	// 2차원 배열 성적 처리
	for (i = 0; i < 3; i++) {	// 행
		printf("%d번 학생, 4과목 점수 입력: ", i);
		for (j = 0; j < 4; j++) {	// 열
			scanf("%d", &score[i][j]);	// 점수 입력 (앞쪽[]는 행이고 바깥쪽 for문 변수, 뒤쪽[]은 열이고 안쪽 for문 변수.
		}
	}

	// 점수 채점
	for (i = 0; i < 3; i++) {
		total = 0;
		for (j = 0; j < 4; j++) {
			total += score[i][j];
		}
		avg = total / 4.0;

		printf("%d번 학생, 총점 : %d, 평균 : %.2lf\n", i, total, avg);
	}

	// 2차원 배열로 동물 이름 관리
	// sizeof(animal) == 100, animal[0] == 20 -> 5
	count = sizeof(animal) / sizeof(animal[0]);
	//printf("%d\n", count);
	for (i = 0; i < count; i++) {
		// animal[i] == animal 배열, i행의 주소.
		scanf("%s", animal[i]);	// 만약 animal[i][j]라면 &animal[i][j]
	}
	
	for (i = 0; i < count; i++) {
		printf("%d번 동물 %s", i, animal[i]);
	}

	return 0;
}