// break를 사용한 반복문 종료

#include <stdio.h>

int main() {
	int i;
	int sum = 0;

	for (i = 1; i <= 10; i++) {
		sum += i;	// sum = sum + i;
		if (sum >= 30) {
			break;	// for문 즉시 종료
		}
	}

	printf("누적합 : %d\n", sum);
	printf("마지막으로 더한 값 : %d\n", i);
}