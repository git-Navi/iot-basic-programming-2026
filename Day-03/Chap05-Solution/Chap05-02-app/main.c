// switch~case 문
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

	printf("switch~case 문 예제\n");

	int rank = 0, money = 0;	// 변수 선언, 초기화

	printf("등수를 입력하세요 : ");
	scanf("%d", &rank);

	//switch (rank) {
	//case 1:	// 1등이면?
	//	money = 1000;	// 1000만원
	//	break;			// switch문 탈출(빠져나가라!), break문을 빼버리면 아래의 로직도 실행되버림.
	//case 2:	// 2등이면?
	//	money = 500;	// 500만원
	//	break;
	//case 3:	// 3등이면?
	//	money = 200;	// 200만원
	//	break;
	//case 4:	// 4등이면?
	//	money = 50;		// 50만원
	//	break;
	//default:	// if문 else
	//	money = 10;
	//	break;
	//}

	if (rank == 1) {
		money = 1000;
	}
	else if (rank == 2) {
		money = 500;
	}
	else if (rank == 3) {
		money = 200;
	}
	else if (rank == 4) {
		money = 50;
	}
	else {
		money = 10;
	}

	printf("%d등 당첨금 %d 만원에 당첨되셨습니다!\a\n", rank, money);

	return 0;
}