// Chap02-02-app : 탈출문자(Escape Character), 변환문자(%) 학습
#include <stdio.h>

int main() {
	printf("Hello, World!\n");	// 콘솔에 문자열을 format에 맞춰서 출력하는 함수

	// '\n' escape character -> 한줄 내림 -> newline
	printf("12345\n");
	printf("67890\n");
	printf("Wow!\n");

	// printf 앞에서 Ctrl + C 하면 자동으로 한 줄로 복사가 되는 꿀팁이 있다.
 
	// '\t' -> 콘솔에 탭 추가 -> tab
	printf("My friend, Fuuka.\n");
	printf("My\tfriend,\tFuuka.\n");

	// '\b' -> 백스페이스 -> backspace
	printf("Goot\bd Morning!\n");

	// '\a' -> 알람 소리 -> alarm
	printf("Bark!!\a\n");

	// '\r' -> 글자 쓰는 맨 앞으로 이동 -> returncarrige
	printf("Department\rLotte\n");

	// 숫자를 콘솔에 출력하는 기능
	
	// '%d' -> deciaml, 정수를 문자로 출력
	printf("%d\n", 10);
	// '%nd' -> n의 자릿수만큼 늘려서 출력
	printf("%10d\n", 10);
	// '%f' -> float, 실수를 문자로 출력
	printf("%f\n", 3.141592);
	// '%lf' -> long float, 실수를 소수점 6자리까지 출력
	printf("%lf\n", 3.14);
	// '%.nf' -> 소수점 n자리까지 출력하고, 그 뒤는 반올림
	printf("%.2f\n", 3.14159265727);

	// 여러 개의 파라미터
	printf("%5d x %5d = %5d", 6, 7, 6 * 7);

	return 0;
}