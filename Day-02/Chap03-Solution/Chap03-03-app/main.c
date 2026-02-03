// 데이터 입력
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	//// 한 개의 값 입력
	//int input_val;

	//printf("수를 입력하세요 > ");
	//scanf("%d", &input_val);	// & 주소 : 키보드로 입력되는 값을 input_val의 주소에 가져가서 넣어라
	//printf("입력된 값 : %d\n", input_val);

	//// 여러 개의 값 입력
	//int age;
	//double height;
	//printf("나이와 키를 입력하세요(예: 25 178) > ");
	//scanf("%d %lf", &age, &height);
	//printf("나이: %d, 키: %.1fcm\n", age, height);

	// 문자열 입력
	char grade;		// 학점
	char name[20];	// 이름

	printf("학점을 입력하세요(예: A) > ");
	scanf("%c", &grade);
	printf("이름을 입력하세요(예: 홍길동) > ");
	scanf("%s", name);	// 배열의 이름만 적으면, 배열의 주소를 나타냄 (그래서 &를 생략!)
	printf("%s의 학점은 %c입니다.\n", name, grade);

	return 0;
}