// 여러가지 함수 유형
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_num(void); // 1. 매개변수 없는 함수. / 매개변수 없고, 반환값 있는 함수;
void print_char(char, int); // 2. 리턴(반환)값 없는 함수
void print_line(void); // 3. 매개변수와 반환값이 모두 없는 함수

void main(void) {
	int result;

	result = get_num(); // 함수 호출
	printf("result: %d\n", result);

	print_char('@', 5); // 함수 호출

	print_line(); // 함수 호출
	printf("학번	이름	전공	학점\n");
	print_line(); // 함수 호출

	return 0;
}

// 이하 함수 정의 부분

// 매개변수가 필요 없음. 키보드로 입력 받으니까.
int get_num(void) {
	// 함수 내용 작성
	int num;	// 키보드에서 입력 값을 저장할 변수
	int res;

	printf("양수 입력 : ");
	res = scanf("%d", &num);	// 키보드 입력으로 값을 대입

	return num;
}

void print_char(char ch, int count) {
	int i;

	for (i = 0; i < count; i++) {
		printf("%c", ch);
	}
	printf("\n");
	// return이 없음.
}

void print_line(void) {
	int i;

	for (i = 0; i < 50; i++) {
		printf("-");
	}
	printf("\n");
} // 함수를 호출한 곳으로 점프 백