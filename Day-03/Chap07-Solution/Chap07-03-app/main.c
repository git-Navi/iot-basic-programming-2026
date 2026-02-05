// 재귀호출 함수

#include <stdio.h>

void fruit(void);	// 함수 선언
void fruit2(int);	// 종료 레벨 매개변수로 받는 재귀호출 함수 정의

int main(void) {
	
	//fruit();
	fruit2(1);
	
	return 0;
}

void fruit(void) {
	static int i = 1;
	printf("banana, %d\n", i++);
	fruit();	// 재귀호출
}

void fruit2(int count) {
	printf("apple\n");
	if (count == 3) {
		return;	// 함수 호출한 곳으로 되돌아가지만 반환 값은 없음.
	}
	fruit2(count + 1);	// 재귀호출
}