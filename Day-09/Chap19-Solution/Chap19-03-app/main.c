// main 소스코드

#include <stdio.h>

int input_data(void);	// 함수 선언
double average(void);
void print_data(double);

// 전역 변수!
int count = 0;
static int total = 0;	// 정적, 소스 코드가 실행되는동안 끝까지 살아남는 변수.

int main(void) {
	double avg;

	total = input_data();	// main.c에 없음
	avg = average();		// main.c에 없음
	print_data(avg);		// main.c에 있음

	return 0;
}

// 함수 정의
void print_data(double avg) {
	printf("입력한 양수 개수 : %d\n", count);
	printf("전체 합과 평균 : %d, %.1lf\n", total, avg);
}