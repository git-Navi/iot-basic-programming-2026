// 포인터 배열

#include <stdio.h>

int main(void) {
	char* panimal[5];	// 동물 다섯마리 입력하는데, 문자열을 포인터로 사용
	int i;

	panimal[0] = "강아지";
	panimal[1] = "고양이";
	panimal[2] = "앵무새";
	panimal[3] = "사자";
	panimal[4] = "긴꼬리원숭이";

	for (i = 0; i < 5; i++) {
		printf("%s\n", panimal[i]);
	}


	return 0;
}