// 평균 계산 소스코드

extern int count;
extern int total;	// main.c에 있는 전역변수를 공유

double average(void) {
	return total / (double)count;
}