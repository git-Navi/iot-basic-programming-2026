// 콘솔 프로그램 명령행 인수

#include <stdio.h>

// main 함수, 엔트리 포인트(entry point) = 진입점
// argc 인수 개수
// argv 인자 문자열의 배열
// ./Chap16-06-app.exe help
// argc = 2
// argv = ["./Chap16-06-app.exe", "help"]
int main(int argc, char** argv) {

	int i;

	/*for (i = 0; i < argc; i++) {
		printf("%s\n", (argv + i));
	}*/

	// 입력받는 문자열마다 여러가지 처리되는 프로그램을 만들 수 있음.
	if (argc < 2) {
		printf("mygit: 명령어가 필요함\n");
		printf("사용법: mygit <command> [options]\n");

		return 0;
	}

	/* git init */
	if (strcmp(argv[1], "init") == 0) {
		printf("깃 저장소 초기화!");
	}
	else if (strcmp(argv[1], "commit") == 0) {
		if (argc >= 4 && strcmp(argv[2], "-m" == 0)) {
			printf("커밋 메세지: '%s'\n", argv[3]);
			printf("[main abc1234] 커밋 완료!\n");
		}
		else {
			printf("오류!");
		} 
	}
	else {
		printf("mygit: 알 수 없는 명령 '%s'\n", argv[1]);
	}

	return 0;
}