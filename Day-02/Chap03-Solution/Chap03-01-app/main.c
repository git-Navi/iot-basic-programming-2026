// 변수
#include <stdio.h>	// 표준 입출력 헤더 파일
#include <limits.h> // 모든 타입의 최소값, 최대값 담고 있는 헤더 파일
#include <float.h>

int main(void) {
	// 변수 상자 만들기
	int a;	// 소수점이 없는 숫자 데이터
	int b, c;	// 변수 여러 개 선언
	float f;	// 소수점이 있는 숫자 데이터
	double d;	// 더 정밀한 소수점이 있는 숫자 데이터
	char ch;	// 문자 데이터

	// assignment(대입) 왼쪽의 변수에 오른쪽 값을 넣는다.
	a = 10;
	b = a;
	c = a + 20;

	//c = 3.145; // Ctrl + / -> 주석 처리 단축키

	f = 3.14159;
	d = 3.14159265358979;	// double은 15자리 정도까지 정확히 표현 가능
	ch = 'A';

	// 출력
	printf("변수 a의 값 : %d\n", a);
	printf("변수 b의 값 : %d\n", b);
	printf("변수 c의 값 : %d\n", c);
	// 정수 형태는 %d, 실수 형태는 %f
	// 빨간 줄이 그이면 오류
	// 녹색 줄이 그이면 경고(!), 실행은 되긴 함.
	printf("변수 f의 값 : %d\n", f);
	printf("변수 f의 값 : %f\n", f);
	// %f는 소수점 6째 자리까지 출력한다는 변환 문자
	printf("변수 d의 값 : %f\n", d);
	// 그 이상의 소수점 자리를 보고싶다면 아래처럼 %.nf 사용
	printf("변수 d의 값 : %.16f\n", d);
	printf("변수 ch의 값 : %c\n", ch);
	printf("변수 ch의 값 : %d\n", ch);

	// ASCII - 영문자, 특수문자(+,-, etc) 등 숫자 값으로 1:1 매칭이 되어 있음.
	// https://ko.wikipedia.org/wiki/ASCII ASCII 표 참조
	printf("변수 ch의 값 : %c\n", 66);
	printf("변수 ch의 값 : %c\n", 97);

	// 정수형
	// char : 크기 1byte -> 8bit 00000000~11111111(2진수) -> 00-FF (0-255 까지 표현, 16진수) / 최대표기 255
	// short : 크기 2bytes
	// int(기본, 제일 중요!) : 크기 4bytes
	// long : 크기 4bytes
	// long long : 크기 8bytes
	
	// sizeof : 내장 함수, 변수의 사이즈를 표현
	printf("변수 char 사이즈 %zu byte / 최소 %d, 최대 %d \n", sizeof(char), CHAR_MIN, CHAR_MAX);
	printf("변수 short 사이즈 %zu byte / 최소 %d, 최대 %d \n", sizeof(short), SHRT_MIN, SHRT_MAX);
	printf("변수 int 사이즈 %zu byte / 최소 %d, 최대 %d \n", sizeof(int), INT_MIN, INT_MAX);
	printf("변수 longlong 사이즈 %zu byte / 최소 %lld, 최대 %lld \n", sizeof(long long), LLONG_MIN, LLONG_MAX);

	// unsigned : 양수로만 표현하는 방법
	// 양수로만 표현하기 때문에 최소값이 0
	printf("변수 unsigned char 사이즈 %zu byte / 최소 %d, 최대 %d \n", sizeof(unsigned char), 0, UCHAR_MAX);
	printf("변수 unsigned short 사이즈 %zu byte / 최소 %d, 최대 %d \n", sizeof(unsigned short), 0, USHRT_MAX);
	printf("변수 unsigned int 사이즈 %zu byte / 최소 %d, 최대 %u \n", sizeof(unsigned int), 0, UINT_MAX);
	printf("변수 unsigned long 사이즈 %zu byte / 최소 %d, 최대 %u \n", sizeof(unsigned long), 0, ULONG_MAX);
	printf("변수 unsigned longlong 사이즈 %zu byte / 최소 %d, 최대 %llu \n", sizeof(unsigned long long), 0, ULLONG_MAX);
}