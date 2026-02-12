// 파일 입출력 2

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>	// OS 관련, 혹은 코드 페이지 인코딩 해결

int main(void) {
	// 콘솔 출력, 입력을 UTF-8(65001)로 고정 설정, 949는 EUC-KR
	SetConsoleOutputCP(65001);	// 콘솔 출력 코드 페이지
	SetConsoleCP(65001);	// 콘솔 자체 코드 페이지
	FILE* ifp, * ofp;

	// 텍스트 내 포맷에 맞춰서 변수 선언
	char name[20];
	int kor, eng, math;	// 국, 영, 수 점수
	int total;
	double avg;
	int res;

	ifp = fopen("./original.txt", "r");
	if (ifp == NULL) {
		printf(u8"입력파일 오픈 실패!\n");	// 문자열을 utf-8로 변환 출력
		exit(1);
	}

	ofp = fopen("./copy.txt", "w");	// w 쓰기 모드는 파일이 없으면 자동 생성.
	if (ofp == NULL) {
		printf(u8"출력파일 생성 실패!\n");
		exit(1);
	}

	while (1) {
		// 입력 파일 포인터에서 읽어서 한줄씩 각 변수에 할당
		res = fscanf(ifp, "%s%d%d%d", name, &kor, &eng, &math);
		if (res == EOF) {	// 파일 데이터에 마지막까지 다 읽으면 EOF.
			break;
		}
		total = kor + eng + math;
		avg = total / 3.0;

		printf(u8"%s%5d%7.1lf\n", name, total, avg);	// 콘솔에 출력
		fprintf(ofp, "%s%5d%7.1f\n", name, total, avg);	// 파일에 출력
	}
	
	printf(u8"파일 복사 완료!\n");
	// 파일 포인터 해제
	fclose(ifp);
	fclose(ofp);

	return 0;
}