// 무한 루프 (infinite loop)

#include <stdio.h>

int main() {
	int i = 1;
	
	// while문을 사용한 무한 루프
	//while (1) {	// 조건이 항상 참이므로 무한 루프
	//	printf("IF %d\n", i++);
	//}

	// for문을 사용한 무한 루프
	//for (;;) {	// 조건이 없으므로 무한 루프
	//	printf("FOR %d\n", i++);
	//}

	while (1) {
		printf("Be happy!\n");
		i++;
		if (i == 10) {
			break;	// i가 10이 되면 무한 루프 종료
		}
	}

	// continue문, 특정 상황에서 일부 반복을 제외시킬 때 사용
	for (i = 1; i <= 100; i++) {
		if (i % 3 == 0) {	// 3의 배수인 경우,
			continue;		// 아래 코드를 실행하지 않고 다음 반복으로 넘어감.
		}
		printf("%d\t", i);
	}

	return 0;
}