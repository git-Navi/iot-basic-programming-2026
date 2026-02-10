// 이중포인터 활용 1

#include <stdio.h>

void swap_ptr(char**, char**);	// 포인터 값을 바꾸는 매개변수
void print_str(char**, int**);	// 포인터 배열을 매개변수

int main(void) {
	char* pa = "success";
	char* pb = "failure";

	printf("pa -> %s, pb -> %s\n", pa, pb);	// 변경 전 문자열

	swap_ptr(&pa, &pb);

	printf("pa -> %s, pb -> %s\n", pa, pb);	// 변경 후 문자열

	// 포인터배열
	// char* ptr_animal[] == char** ptr_animal
	// 문자열을 선언 및 초기화는 문자 배열 포인터로만 가능
	char* ptr_animal[] = { "eagle", "tiger", "lion", "squirrel" };
	// 이중포인터는 대입이나 매개변수로 전달할 때 가능
	char** ptr = ptr_animal;
	int count = sizeof(ptr_animal) / sizeof(ptr_animal[0]);

	print_str(ptr_animal, count);

	return 0;
}

void swap_ptr(char** ppa, char** ppb) {
	char* ptemp;

	ptemp = *ppa;	// ppa의 주소를 ptemp에 전달, "success"의 주소
	*ppa = *ppb;	// ppb의 주소를 ppa에 전달
	*ppb = ptemp;
}

// pps 2차원 문자배열과 유사.
void print_str(char** pps, int count) {
	int i;
	
	for (i = 0; i < count; i++) {
		printf("%s\n", *(pps + i));	// pps[i]와 동일
	}
}