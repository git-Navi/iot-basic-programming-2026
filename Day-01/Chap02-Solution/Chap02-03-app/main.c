// 진법 표시
#include <stdio.h>
#include <limits.h>	// 각 타입별 최대값과 최소값을 저장하는 헤더 파일

int main() {
	// limits.h 사용해서 출력, 더 자세한 정보를 보고 싶으면 Ctrl + 클릭으로 참고
	printf("int의 최대값 : %d\n", INT_MAX);
	printf("int의 최소값 : %d\n", INT_MIN);

	printf("%d\n", 12);		// 10진수
	printf("%d\n", 014);	// 8진수, 12 (숫자 앞에 '0')
	printf("%d\n", 0xC);	// 16진수, 12 (숫자 앞에 '0x')

	printf("%d\n", 12);	// 10진수
	printf("%o\n", 12);	// 12를 8진수로 출력
	printf("%x\n", 12);	// 12를 16진수로 출력 (소문자)
	printf("%X\n", 12);	// 12를 16진수로 출력 (대문자)

	// 지수 표현
	printf("%.1lf\n", 1e6);
	printf("%.7lf\n", 3.14e-5);

	// 문자, 문자열
	// C에서는 문자 != 문자열
	printf("%c\n", 'A');
	printf("%s\n", "A");
	printf("%d\n", 'A'); // 아스키코드로 A는 int로 65
	printf("%c는 %s 입니다.\n", '1', "first");

	// 문자는 무조건 변환문자 %c 사용
	// 문자열은 무조건 변환문자 %s 사용
	printf("%c는 %c 입니다.\n", '1', "first"); // c는 문자이기 때문에 first 작성X
	printf("%s는 %s 입니다.\n", '1', "first"); // s는 문자열이기 때문에 1 작성X


}