#define _CRT_SECURE_NO_WARNINGS // 보안문제 이전의 오래된 함수 사용을 위해서

#include <stdio.h>
#include <float.h>	// 실수형 최소값, 최대값 헤더 파일
#include <string.h> // 문자열 처리를 위한 라이브러리

int main(void) {
	// 실수형
	// float
	printf("변수 float 사이즈 %zu byte / 최소 %e, 최대 %e \n", sizeof(float), FLT_MIN, FLT_MAX);
	// double (실수형 기본)
	printf("변수 double 사이즈 %zu byte / 최소 %e, 최대 %e \n", sizeof(double), DBL_MIN, DBL_MAX);

	// 문자열 : 문자의 배열(char array)
	// 문자를 표현할 때는 '' (single quote)
	// 문자열을 표현할 때는 "" (double quote)
	char fruit[20] = "Strawberry";	// 절대 '' 사용 금지!

	printf("과일 이름 : %s", fruit);

	// fruit = "banana"; 문자열에서 대입은 불가능
	strcpy(fruit, "banana"); // 함수를 사용해서 변수값을 변경
	printf("변경 과일 이름 : %s\n", fruit);

	// const : 변하지 않는 값을 지정
	const double tax_rate = 0.10;	// 세율
	const double pi = 3.141592;	// 원주율이 바뀌나요?
	int income = 5000;
	double tax = income * tax_rate;
	printf("세금은 %f원\n", tax);

	// const로 지정했기 때문에 값을 바꿀 수 없어 오류 발생, const는 이후에 변경 불가능
	//tax_rate = 0.20;

	// 변수 선언에서 조심할 것
	int age;	// unsigned char(최대값 255)가 가장 적합, 왜냐하면 나이에는 음수가 없고...
	
	/*
	* 변수명 지정 방식
	* 알파벳 A-Z, a-z, 0-9, _ 까지만 허용
	* 숫자로 시작할 수 없음
	* 대소문자 구별
	* 예약어는 변수명으로 사용 불가 (if, while, switch 등)
	* 
	* 의미있는 단어들의 조합으로 변수명 선언할 것!
	*/

	//int 0apple;
	//int non-stop;
	//int non!stop;
	//int short;	// 타입형 이름이라 못 씀!
	
	char full_name[50] = "YOUR NAME";
	int age = 50;
	char address[100] = "YOUR ADDRESS";
	char blood_type = 'A';
	float height = 165.3f;
}