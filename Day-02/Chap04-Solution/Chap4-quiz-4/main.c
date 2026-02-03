#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// bmi = 몸무게 / ((키 / 100) * (키 / 100))

int main() {
	// 몸무게(kg) 입력
	double weight;
	// 키(cm) 입력
	double height;
	// bmi를 저장할 변수
	double bmi = 0.0;

	printf("몸무게(kg)와 키(cm)를 입력하세요: ");
	scanf("%lf %lf", &weight, &height);

	// bmi 계산
	bmi = weight / ((height / 100) * (height / 100));

	printf((bmi >= 20.0 && bmi < 25.0) ? "표준입니다.\n" : "체중관리가 필요합니다.\n");

	return 0;
}