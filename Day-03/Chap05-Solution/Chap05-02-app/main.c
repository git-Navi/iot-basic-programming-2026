// switch~case 구문
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

	printf("switch~case 구문 시작하기\n");

	int rank = 0, money = 0;	// rank, money 초기화

	printf("순위를 입력하세요 : ");
	scanf("%d", &rank);

	//switch (rank) {
	//case 1:	// 1등
	//	money = 1000;	// 1000만원
	//	break;			// switch문 탈출 (빠져나가기!) break문은 필수!
	//case 2:	// 2등
	//	money = 500;	// 500만원
	//	break;
	//case 3:	// 3등
	//	money = 200;	// 200만원
	//	break;
	//case 4:	// 4등
	//	money = 50;		// 50만원
	//	break;
	//default:	// if문의 else와 동일
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

	printf("%d등의 당첨금은 %d 만원 입니다!\a\n", rank, money);

	return 0;
}