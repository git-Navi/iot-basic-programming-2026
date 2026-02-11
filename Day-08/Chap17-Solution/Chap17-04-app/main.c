// 구조체 포인터 -> 연산자

#include <stdio.h>

struct score {
	int kor;		// 국어 점수
	int eng;		// 영어 점수
	int math;		// 수학 점수
};

struct address {
	char name[20];
	int age;
	char tel[20];
	char addr[80];
};

// 3. 구조체 배열을 주소로 받아서 출력하는 함수
void print_list(struct address*);

int main(void) {
	//struct score yuni = { 90, 80, 70 };
	struct score yuni = {	// 정확하게 초기화!
		.kor = 90,
		.eng = 80,
		.math = 70
	};
	struct score* ps = &yuni;	// 구조체 포인터에 주소를 저장

	printf("국어 : %d\n", (*ps).kor);
	// (*ps). 연산 자체가 복잡함. 이를 단순화 시키는 게 ->
	printf("영어 : %d\n", ps->eng);	// 연산자 사용
	printf("수학 : %d\n", ps->math);

	//struct address 구조체 배열
	struct address list[5] = {
		{"홍길동", 23, "111-1111", "울릉도 독도"},
		{"이순신", 35, "222-2222", "서울 건천동"},
		{"장보고", 19, "333-3333", "완도 청해진"},
		{"유관순", 15, "444-4444", "충남 천안"},
		{"안중근", 45, "555-5555", "황해도 해주"}
	};

	int i;

	// 2. 출력을 메인 함수에서 하면 쉽다!
	for (i = 0; i < 5; i++) {
		printf("%10s%5d%15s%20s\n", list[i].name, list[i].age, list[i].tel, list[i].addr);
	}

	printf("print_list 함수 출력\n");
	print_list(list);	// 배열의 이름만 적으면 주소가 된다.

	return 0;
}
// 구조체 배열 포인터를 사용하면
// *(포인터) 연산자로 작업하면 연산이 복잡해짐.
// 그래서, 대신 -> 를 사용하는 것.
void print_list(struct address* lp) {
	int i;

	// 주의 요함. 자세히 보도록.
	for (i = 0; i < 5; i++) {
		printf("%10s%5d%15s%20s\n", (*(lp+i)).name, (lp+i)->age, (lp + i)->tel, (lp + i)->addr);
	}
}