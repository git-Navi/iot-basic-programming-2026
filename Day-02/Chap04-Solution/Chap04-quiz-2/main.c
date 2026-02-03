#include <stdio.h>

int main() {
	// 경기장 좌석 수(seats) 초기화, 70석
	int seats = 70;
	// 입장객 수(audience) 초기화, 65명
	int audience = 65;
	// 입장률(rate)을 저장할 변수
	double rate = 0.0;
	// 'audience / seats'를 바로 연산하면 둘 다 int형이므로 몫을 계산한다.
	rate = (audience / seats) * 100;	// 0으로 출력됨!

	// 따라서 소수점까지 계산할 수 있도록 double형으로 형 변환한다.
	rate = ((double)audience / (double)seats) * 100;

	// 입장률 출력
	printf("입장률 : %.1f%%\n", rate);

	return 0;
}