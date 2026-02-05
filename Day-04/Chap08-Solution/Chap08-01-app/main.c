// 배열

#include <stdio.h>

int main() {
	// 배열 선언과 초기화 방법

	//int kor, math, eng, social, science;	// 5과목 점수 저장 변수
	int ary[5];			// 5과목 점수 저장 배열
	int total = 0;			// 5과목 총점
	int i;
	double avg = 0.0;	// 평균 점수

	ary[0] = 90;	// 국어 점수
	ary[1] = 85;	// 수학 점수
	ary[2] = 70;	// 영어 점수
	ary[3] = 95;	// 사회 점수
	ary[4] = 100;	// 과학 점수

	// int ary[5] = { 90, 85, 70, 95, 100 }; // 선언과 초기화를 동시에도 가능함. 이게 더 편함.
	// int ary[5] = { 0 };	// 선언과 초기화를 동시에 0으로 초기화 할 수도 있음.
	// int ary2[] = { 1, 2, 3, 4 } // 배열 초기화로 배열 크기를 자동 지정

	printf("국어 점수 : %d\n", ary[0]);
	printf("수학 점수 : %d\n", ary[1]);
	printf("영어 점수 : %d\n", ary[2]);
	printf("사회 점수 : %d\n", ary[3]);
	printf("과학 점수 : %d\n", ary[4]);

	// 합산
	// 너무 비효율적인...
	//total = ary[0] + ary[1] + ary[2] + ary[3] + ary[4];
	//printf("총점은 %d\n", total);

	for (i = 0; i < 5; i++) {
		total += ary[i];
	}
	printf("총점은 %d\n", total);

	avg = total / 5.0;
	printf("평균은 %.1f\n", avg);

	return 0;
}