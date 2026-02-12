// 헤더파일 사용

#include <stdio.h>		// 라이브러리(헤더파일)
// 하위 폴더에 있는 파일을 추가할때는 printf()와 다르게 \\ 사용하지 않음.
//#include "./include/student.h"
#include "student.h"	// 사용자가 만든 헤더파일은 ""로 추가

#define PI 3.14159265359
#define LIMIT 100.0
#define MSG "passed!"
#define ERR_PRN printf("허용범위 초과!!");
// 조건부 컴파일 지시자
#define VER 7
#define BIT16

void func(void);

int main(void) {
	Student st1 = { 315, "홍길동" };
	double radius, area;	// 반지름, 면적

	int max;

#if VER >= 6
	printf("버전 %d입니다.\n", VER);
#else
#error 컴파일러 버전은 6.0 이상이어야 합니다.
	printf("버전 확인하세요!\n");
#endif

#ifdef BIT16
	max = 32767;
#else
	max = 2147483647;
#endif

	printf("학번 : %d, 이름 : %s\n", st1.num, st1.name);

	radius = 5;	// 5 이하면 통과됨!
	area = radius * radius * PI;

	if (area > LIMIT) {	// 계산된 면적이 100.0을 넘으면
		ERR_PRN;	// 오류 메세지 매크로로 출력!
	}
	else {
		printf("원 면적 : %.2lf (%s)\n", area, MSG);
	}

	printf("컴파일(빌드) 날짜와 시간 : %s %s \n", __DATE__, __TIME__);
	printf("파일명 : %s\n", __FILE__);
	printf("함수명 : %s\n", __FUNCTION__);
	printf("행번명 : %d\n", __LINE__);

#line 100 "macro"	// 행번호를 100으로 변경, 파일명도 macro.c로 표시
	func();

	return 0;
}

void func(void) {
	printf("\n");
	printf("파일명 : %s\n", __FILE__);
	printf("함수명 : %s\n", __FUNCTION__);
	printf("행번명 : %d\n", __LINE__);
}