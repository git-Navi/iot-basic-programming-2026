// 평균 계산 소스코드

extern int count;	// main.c에 있는 count을 가져와서 공유!
extern int total;	// input.c에 있는 total을 가져와서 공유!, main.c에 선언된 static total은 main.c 내에서만 공유됨.

double average(void) {
	return total / (double)count;
}