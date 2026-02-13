// 주소록 프로그램 step2
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 사람은 숫자보다 이름에 익숙, 유지 보수를 위해서.
#define MAX_CONTACTS	100	// 100명의 주소록 작성
#define NAME_LEN		31	// 이름 최대 길이
#define PHONE_LEN		20
#define EMAIL_LEN		64
#define ADDR_LEN		128
#define MEMO_LEN		31

typedef struct _contact {
	char name[NAME_LEN];
	char phone[PHONE_LEN];
	char address[ADDR_LEN];
	char email[EMAIL_LEN];
	char memo[MEMO_LEN];
} Contact;	// 이후 Contact 이름으로 사용함.

// 변수 선언
static Contact contacts[MAX_CONTACTS];
static int count = 0;

// 함수 선언
static void print_menu(void);	// 해당 소스 내에서만 쓴다.
static int read_menu(void);
static void read_line(char* buf, int size);

static void add_contact(void);
static void list_contacts(void);

int main(void) {
	int choice;

	while (1) {	// 무한 루프
		print_menu(); // 메뉴를 출력
		choice = read_menu(); // choice 값에 입력 받음!

		switch (choice) {
		case 1:
			//printf("%s\n", "[ADD] 연락처 추가 (기능 구현)");
			add_contact();	// 실제 연락처 추가
			break;

		case 2:
			//printf("[LIST] 연락처 목록");
			list_contacts();
			break;
			
		case 3:
			printf("[SEARCH] 연락처 검색 (다음 스텝에서...)");
			break;
			
		case 4:
			printf("[EDIT] 연락처 수정 (다음 스텝에서...)");
			break;

		case 5:
			printf("[DELETE] 연락처 삭제 (다음 스텝에서...)");
			break;

		case 6:
			puts("프로그램 종료");
			return 0;

		default:
			puts("메뉴는 1-6 사이 입니다.");
			break;
		}

		puts("");
	}

	return 0;
}

static void print_menu(void) {
	puts("========================================");
	puts("        주소록 프로그램 (Step 2)        ");
	puts("========================================");
	puts("1. 추가");
	puts("2. 목록");
	puts("3. 검색 (미구현)");
	puts("4. 수정 (미구현)");
	puts("5. 삭제 (미구현)");
	puts("6. 종료");
	puts("----------------------------------------");

}

static int read_menu(void) {
	int choice, ch;

	printf("선택 > ");
	if (scanf("%d", &choice) != 1) {
		while ((ch = getchar()) != '\n' && ch != EOF) { }
		return -1;
	}

	while ((ch = getchar() != '\n' && ch != EOF)) { }

		return choice;
}

// fgets로 입력할 때 문제가 발생하지 않도록, 문자열 끝에 \n 제거
static void read_line(char* buf, int size) {
	if (fgets(buf, size, stdin) == NULL) {
		buf[0] = '\0';
		return;
	}
	// strcspn(buf, "\n") -> buf 문자열 내에서 \n을 찾아서 그 위치 값을 return
	// "Hello World!\n" -> "Hello World!\0"
	// buf[12] = '\0'
	buf[strcspn(buf, "\n")] = '\0';	// 문자열 끝에 있는 \n을 \0으로 변경
}

// 메뉴 1번 기능, 연락처 추가
static void add_contact(void) {
	if (count >= MAX_CONTACTS) {
		puts("주소록 최대 인원 100명에 도달했습니다.");
		return;
	}

	puts("[ADD] 새 연락처 입력");

	printf("이름 (최대 10자) : ");
	read_line(contacts[count].name, NAME_LEN);

	printf("전화 (최대 20자) : ");
	read_line(contacts[count].phone, PHONE_LEN);

	printf("주소 (최대 40자) : ");
	read_line(contacts[count].address, ADDR_LEN);

	printf("이메일 : ");
	read_line(contacts[count].email, EMAIL_LEN);

	printf("메모 (최대 30자) : ");
	read_line(contacts[count].memo, MEMO_LEN);

	count++;
	puts("추가 완료!");
}

// 메뉴 2번 기능, 연락처 목록
static void list_contacts(void) {
	int i;

	if (count == 0) {
		puts("[LIST] 저장된 연락처가 없습니다.");
		return;
	}

	puts("[LIST] 연락처 목록");
	puts("-------------------------------------------------------------------------------------");
	printf("%4s | %-10s | %-17s | %-30s | %-25s |\n", "No", "이름", "전화번호", "주소", "이메일");
	puts("-------------------------------------------------------------------------------------");

	// contacts 배열에 들어있는 주소록 출력
	for (i = 0; i < count; i++) {
		printf("%4d | %-11s | %-15s | %-36s | %-25s\n", i, contacts[i].name, contacts[i].phone, contacts[i].address, contacts[i].email);
	}

	puts("-------------------------------------------------------------------------------------");

}
