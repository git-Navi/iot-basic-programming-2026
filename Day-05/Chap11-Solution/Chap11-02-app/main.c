// 문자 입력 실수
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char ch1, ch2;
	char ch3;

	//scanf("%c%c", &ch1, &ch2);	 // a엔터를 치면 ch1 = 'a', ch2 = '\n'
	//printf("[%c%c]", ch1, ch2);

	// getchar(), putchar() 함수로 글자 하나를 입력, 출력

	// 주석 변환 토글 단축키 > Ctrl + /
	// 주석 변환 > Ctrl + K, C
	// 주석 해제 > Ctrl + K, U

	//ch3 = getchar();	// getchar()는 앞선 입력의 \n도 들어갈 수 있음!
	//printf("입력값 -> ");
	//putchar(ch3);


	// 입력버퍼 문제
	int num, grade;	// 학번, 학점

	printf("학번 입력 : ");
	scanf("%d", &num);	// 학번 입력
	getchar();	// 키보드 버퍼의 내용은 읽어옴. 그냥 사라짐. buffer clear -> \n 만 지움! (Enter에 대한 해결만 하는 것!)
	printf("학점 입력 : ");
	grade = getchar();	// 학점 입력

	printf("학번은 %d, 학점은 %c", num, grade);

	return 0;
}