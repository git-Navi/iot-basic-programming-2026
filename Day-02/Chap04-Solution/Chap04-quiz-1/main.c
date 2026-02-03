#include <stdio.h>

int main() {
	int res;	// 결과 변수

	int shortSize = sizeof(short);
	int longSize = sizeof(long);

	res = (shortSize > longSize);

	res = (res == 1) ? shortSize : longSize;

	printf("%s\n", (res == shortSize) ? "short" : "long");

	return 0;
}