// 주소록 프로그램 step5
#define _CRT_SECURE_NO_WARNINGS

#pragma region 전처리 영역

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma endregion

#pragma region 매크로 선언 영역

// 사람은 숫자보다 이름에 익숙, 유지 보수를 위해서.
#define MAX_CONTACTS	100	// 100명의 주소록 작성
#define NAME_LEN		31	// 이름 최대 길이
#define PHONE_LEN		20
#define EMAIL_LEN		64
#define ADDR_LEN		128
#define MEMO_LEN		31

#pragma endregion

typedef struct _contact {
	char name[NAME_LEN];
	char phone[PHONE_LEN];
	char address[ADDR_LEN];
	char email[EMAIL_LEN];
	char memo[MEMO_LEN];
} Contact;	// 이후 Contact 이름으로 사용함.

#pragma region 변수 영역

// 변수 선언
static Contact contacts[MAX_CONTACTS];
static int count = 0;

#pragma endregion

#pragma region 함수선언 영역

// 함수 선언
static void print_menu(void);	// 해당 소스 내에서만 쓴다.
static int read_menu(void);
static void read_line(char* buf, int size);

static void add_contact(void);
static void list_contacts(void);

static void search_contact(void);
static void print_contact(int index);

static void update_contact(void);
static void delete_contact(void);

static int save_contacts(const char* filename);	// 파일명이 변경되면 안된다.
static int load_contacts(const char* filename);	
static void trim_newline(char* s);	// 줄바꿈 제거 기능 추가

#pragma endregion

#pragma region 메인함수 영역

int main(void) {
	int choice;

	load_contacts("contacts.txt");	// 프로그램 실행 후 데이터 로드됨.

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
			//printf("[SEARCH] 연락처 검색 (다음 스텝에서...)");
			search_contact();
			break;

		case 4:
			//printf("[UPDATE] 연락처 수정 (다음 스텝에서...)");
			update_contact();
			break;

		case 5:
			//printf("[DELETE] 연락처 삭제 (다음 스텝에서...)");
			delete_contact();
			break;

		case 6:
			save_contacts("contacts.txt");	// 종료 직전 현재 데이터 저장
			puts("프로그램 종료");
			return 0;
		
		//case 7 :
		//	//printf("[SAVE] 연락처 저장 (다음 스텝에서...)");
		//	save_contacts("contacts.txt");
		//	break;

		//case 8 :
		//	//printf("[LOAD] 연락처 로드 (다음 스텝에서...)");
		//	load_contacts("contacts.txt");
		//	break;

		default:
			puts("메뉴는 1-6 사이 입니다.");
			break;
		}

		puts("");
	}

	return 0;
}

#pragma endregion

#pragma region 사용자함수 정의 영역

// 메뉴 출력 함수
static void print_menu(void) {
	puts("========================================");
	puts("        주소록 프로그램 (Step 5)        ");
	puts("========================================");
	puts("1. 추가");
	puts("2. 목록");
	puts("3. 검색");
	puts("4. 수정");
	puts("5. 삭제");
	puts("6. 종료");
	//puts("7. 저장");	// 데이터 저장
	//puts("8. 로드");	// 데이터 로드
	puts("----------------------------------------");
}

// 메뉴 번호 읽기 함수
static int read_menu(void) {
	int choice, ch;

	printf("선택 > ");
	if (scanf("%d", &choice) != 1) {
		while ((ch = getchar()) != '\n' && ch != EOF) {}
		return -1;
	}

	while ((ch = getchar() != '\n' && ch != EOF)) {}

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

// 문자열 마지막에 엔터가 있으면 제거하는 함수
static void trim_newline(char* s) {
	s[strcspn(s, "\n")] = '\0';
}

// 메뉴 1번 기능, 연락처 추가
static void add_contact(void) {
	if (count >= MAX_CONTACTS) {
		puts("주소록 최대 인원 100명에 도달했습니다.");
		return;
	}

	puts("[ADD] 새 연락처 입력");

	printf("[ADD] 이름 (최대 10자) : ");
	read_line(contacts[count].name, NAME_LEN);

	printf("[ADD] 전화 (최대 20자) : ");
	read_line(contacts[count].phone, PHONE_LEN);

	printf("[ADD] 주소 (최대 40자) : ");
	read_line(contacts[count].address, ADDR_LEN);

	printf("[ADD] 이메일 : ");
	read_line(contacts[count].email, EMAIL_LEN);

	printf("[ADD] 메모 (최대 30자) : ");
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
	printf("%4s | %-10s | %-17s | %-30s | %-25s \n", "No", "이름", "전화번호", "주소", "이메일");
	puts("-------------------------------------------------------------------------------------");

	// contacts 배열에 들어있는 주소록 출력
	for (i = 0; i < count; i++) {
		printf("%4d | %-11s | %-15s | %-36s | %-25s\n", i + 1, contacts[i].name, contacts[i].phone, contacts[i].address, contacts[i].email);
	}

	puts("-------------------------------------------------------------------------------------");

}

// 메뉴 3번 기능, 검색 함수
static void search_contact(void) {
	char keyword[NAME_LEN];
	int found = 0;
	int i;

	if (count == 0) {
		puts("[SEARCH] 검색할 연락처가 없습니다.");
		return;
	}

	printf("[SEARCH] 검색할 이름 입력 : ");
	read_line(keyword, NAME_LEN);

	if (strlen(keyword) == 0) {
		puts("[SEARCH] 검색할 이름이 없습니다.");
		return;
	}

	puts("[SEARCH] 검색 결과 : ");
	puts("-------------------------------------------------------------------------------------");

	for (i = 0; i < count; i++) {
		// strcmp와 유사한 기능, strstr(찾을 문자열, 찾는 문자열)
		if (strstr(contacts[i].name, keyword) != NULL) {
			printf("[SEARCH] 순번 : %d\n", i + 1);
			print_contact(i);
			// 상세 출력
			puts("-------------------------------------------------------------------------------------");
			found = 1;
		}
	}

	if (found < 1) {
		puts("[SEARCH] 일치하는 연락처가 없습니다.");
	}
}

// 메뉴 3-1. 주소록 1건 상세출력 함수
static void print_contact(int index) {
	printf("[SEARCH] 이름   : %s\n", contacts[index].name);
	printf("[SEARCH] 전화   : %s\n", contacts[index].phone);
	printf("[SEARCH] 주소   : %s\n", contacts[index].address);
	printf("[SEARCH] 이메일 : %s\n", contacts[index].email);
	printf("[SEARCH] 메모   : %s\n", contacts[index].memo);
}

// 메뉴 4번 기능, 수정 함수
static void update_contact(void) {
	char buf[MEMO_LEN];
	int index, ch;

	if (count == 0) {
		puts("[UPDATE] 수정할 연락처가 없습니다.");
		return;
	}

	printf("[UPDATE] 수정할 번호 (1 ~ %d) > ", count);
	if (scanf("%d", &index) != 1) {
		while ((ch = getchar() != '\n' && ch != EOF)) {}
		puts("[UPDATE] 숫자를 입력하세요.");
		return;
	}
	// 이전 버퍼에 남아있는 데이터 삭제 기능
	while ((ch = getchar()) != '\n' && ch != EOF) {}	// 첫 번째 이름을 수정할 수 없음.

	if (index < 1 || index > count) {
		puts("[UPDATE] 입력 범위를 초과했습니다.");
		return;
	}

	puts("[UPDATE] 현재 정보 : ");
	print_contact(index - 1);	// 실제 인덱스는 0, 1, 2 지만 검색 순번은 1, 2, 3 을 사용하기 때문에 -1을 해줘야한다.
	puts("----------------------------------------");

	// 일단 검색해서 나온 결과 보기까지 구현해둠.

	// 실제 수정 로직
	puts("[UPDATE] 새 값을 입력하세요. (ENTER만 입력하면 기존값은 유지됩니다.)");

	printf("[UPDATE] 이름 (%s) > ", contacts[index - 1].name);
	read_line(buf, NAME_LEN);

	if (buf[0] != '\0') {	// 엔터만 친게 아니면, 내용을 입력했으면.
		strncpy(contacts[index - 1].name, buf, NAME_LEN);
		contacts[index - 1].name[NAME_LEN - 1] = '\0';	// 안전빵용, 글자를 MAX 적으면 \0이 들어가야 문자열 끝을 알려준다.
	}

	printf("[UPDATE] 전화 (%s) > ", contacts[index - 1].phone);
	read_line(buf, PHONE_LEN);

	if (buf[0] != '\0') {	// 엔터만 친게 아니면, 내용을 입력했으면.
		strncpy(contacts[index - 1].phone, buf, PHONE_LEN);
		contacts[index - 1].phone[PHONE_LEN - 1] = '\0';	// 안전빵용, 글자를 MAX 적으면 \0이 들어가야 문자열 끝을 알려준다.
	}

	printf("[UPDATE] 주소 (%s) > ", contacts[index - 1].address);
	read_line(buf, ADDR_LEN);

	if (buf[0] != '\0') {	// 엔터만 친게 아니면, 내용을 입력했으면.
		strncpy(contacts[index - 1].address, buf, ADDR_LEN);
		contacts[index - 1].address[ADDR_LEN - 1] = '\0';	// 안전빵용, 글자를 MAX 적으면 \0이 들어가야 문자열 끝을 알려준다.
	}

	printf("[UPDATE] 이메일 (%s) > ", contacts[index - 1].email);
	read_line(buf, EMAIL_LEN);

	if (buf[0] != '\0') {	// 엔터만 친게 아니면, 내용을 입력했으면.
		strncpy(contacts[index - 1].email, buf, EMAIL_LEN);
		contacts[index - 1].email[EMAIL_LEN - 1] = '\0';	// 안전빵용, 글자를 MAX 적으면 \0이 들어가야 문자열 끝을 알려준다.
	}

	printf("[UPDATE] 메모 (%s) > ", contacts[index - 1].memo);
	read_line(buf, MEMO_LEN);

	if (buf[0] != '\0') {	// 엔터만 친게 아니면, 내용을 입력했으면.
		strncpy(contacts[index - 1].memo, buf, MEMO_LEN);
		contacts[index - 1].memo[MEMO_LEN - 1] = '\0';	// 안전빵용, 글자를 MAX 적으면 \0이 들어가야 문자열 끝을 알려준다.
	}

	puts("[UPDATE] 수정이 완료되었습니다.");

}

// 메뉴 5번 기능, 삭제 함수
static void delete_contact(void) {
	int index, i, ch;
	char yn[8];

	if (count == 0) {
		puts("[DELETE] 삭제할 연락처가 없습니다.");
		return;
	}

	printf("[DELETE] 삭제할 번호 (1 ~ %d) > ", count);
	if (scanf("%d", &index) != 1) {
		while ((ch = getchar() != '\n' && ch != EOF)) {}
		puts("[DELETE] 숫자를 입력하세요.");
		return;
	}
	// 이전 버퍼에 남아있는 데이터 삭제 기능
	while ((ch = getchar()) != '\n' && ch != EOF) {}	// 첫 번째 이름을 수정할 수 없음.

	if (index < 1 || index > count) {
		puts("[DELETE] 입력 범위를 초과했습니다.");
		return;
	}

	puts("[DELETE] 삭제할 정보 : ");
	print_contact(index - 1);

	printf("[DELETE] 정말 삭제하시겠습니까? (Y/N) > ");
	read_line(yn, (int)sizeof(yn));

	if (!(yn[0] == 'y' || yn[0] == 'Y')) {	// 소문자 'y' 이거나 대문자 'Y'가 아니면?
		puts("[DELETE] 삭제를 취소합니다.");
		return;
	}

	// 현재 삭제할 값 이후의 배열 요소를 앞으로 당긴다.
	for (i = index - 1; i < count - 1; i++) {
		contacts[i] = contacts[i + 1];	// 전부 앞으로.
	}
	count--;	// 한 건을 지웠으니 전체 수를 1 감소 시킨다.

	puts("[DELETE] 삭제가 완료되었습니다.");

}

// 메뉴 7번 기능, 저장 함수
static int save_contacts(const char* filename) {
	FILE* fp = fopen(filename, "w");	// 쓰기 모드로 open.
	int i;

	if (!fp) {	// fp == NULL
		puts("[SAVE] 파일 저장을 실패했습니다. (경로나 권한을 확인하세요.)");
		return 0;
	}

	// 저장 작업
	for (i = 0; i < count; i++) {
		// 구분자 |(파이프) 사용, |를 주소록에 사용하면 문제가 발생한다.
		fprintf(fp, "%s|%s|%s|%s|%s\n", 
			contacts[i].name, 
			contacts[i].phone, 
			contacts[i].address, 
			contacts[i].email, 
			contacts[i].memo
		);
	}

	fclose(fp);
	puts("[SAVE] 저장이 완료되었습니다.");

	return 1;	// 한 건 성공했다는 의미.
}

// 메뉴 8번 기능, 로드 함수
static int load_contacts(const char* filename) {
	FILE* fp = fopen(filename, "r");
	char line[600];

	if (!fp) {
		puts("[LOAD] 불러올 파일이 없습니다.");
		return 0;
	}

	count = 0;

	while (fgets(line, sizeof(line), fp) != NULL) {
		char* name;
		char* phone;
		char* address;
		char* email;
		char* memo;

		trim_newline(line);	// 메모 이후 \n을 삭제

		// |로 분리, 토큰 분리
		name = strtok(line, "|");
		phone = strtok(NULL, "|");
		address = strtok(NULL, "|");
		email = strtok(NULL, "|");
		memo = strtok(NULL, "|");

		// contacts 배열에 하나씩 대입
		// 다섯 개 데이터 중 하나라도 없으면 패스
		if (!name || !phone || !email || !memo || !address) continue;

		if (count >= MAX_CONTACTS) break;	// 현재 100개 밖에 못 넣음.

		strncpy(contacts[count].name, name, NAME_LEN);
		contacts[count].name[NAME_LEN - 1] = '\0';	// 이름 길이보다 길게 쓰면 정리

		strncpy(contacts[count].phone, phone, PHONE_LEN);
		contacts[count].phone[PHONE_LEN - 1] = '\0';	// 번호 길이보다 길게 쓰면 정리

		strncpy(contacts[count].email, email, EMAIL_LEN);
		contacts[count].email[EMAIL_LEN - 1] = '\0';	// 이메일 길이보다 길게 쓰면 정리

		strncpy(contacts[count].memo, memo, MEMO_LEN);
		contacts[count].memo[MEMO_LEN - 1] = '\0';	// 메모 길이보다 길게 쓰면 정리

		strncpy(contacts[count].address, address, ADDR_LEN);
		contacts[count].address[ADDR_LEN - 1] = '\0';	// 번호 길이보다 길게 쓰면 정리

		count++;
	}

	fclose(fp);
	puts("[LOAD] 주소록을 불러오는데 성공했습니다.");

	return 1;

}

#pragma endregion