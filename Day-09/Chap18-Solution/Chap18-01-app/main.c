// 파일 입출력
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <direct.h>

int main(void) {
	char cwd[256];	// 경로 입력 변수, 윈도우 경로 문자열 최대 길이, Python 설치 시에 확인 가능함.
	char str[80];
	char* res;

	_getcwd(cwd, sizeof(cwd));
	printf("현재 작업(프로젝트) 폴더 : %s\n", cwd);

	// 여기서부터 텍스트파일 복사
	FILE* fp,* ofp;	// fp 파일 입력용 파일 포인터, ofp 출력용 파일 포인터.

	// 디렉토리, 폴더 구분자로 '/'를 사용해도 무방하다.
	fp = fopen("sample.txt", "r");
	if (fp == NULL) {
		printf("파일 열기 실패!\n");
		return 1;	// exit(1) 동일한 기능
	}
	else {
		printf("파일 오픈 성공!\n");
	}

	// 파일 복사용 open
	ofp = fopen("./data/copy.txt", "w");
	if (ofp == NULL) {	// 실패 방지용
		printf("파일 열기 실패!\n");
		return 1;	// exit(1) 동일한 기능
	}
	while (1) {
		res = fgets(str, sizeof(str), fp);		// sample.txt 읽은 파일 포인터에서 한 줄을 Read.
		if (res == NULL) {	// 더 이상 읽을 게 없으면 break;
			break;
		}
		printf("한줄 쓰기 -> %s\n", str);
		str[strlen(str - 1)] = '\0';
		fputs(str, ofp);
		fputs(" ", ofp);	// 한 줄 끝난 뒤에 space 추가.
	}

	fclose(fp); fclose(ofp);

	return 0;
}