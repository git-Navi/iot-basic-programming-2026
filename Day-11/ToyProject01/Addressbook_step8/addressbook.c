#define _CRT_SECURE_NO_WARNINGS
#include "addressbook.h"

#pragma region 변수 영역

// 변수 선언
//static Contact contacts[MAX_CONTACTS]; // 배열에서...
static Contact* contacts = NULL;	// 동적배열로...
static int count = 0;
static int capacity = 0;

#pragma endregion

#pragma region 내부함수 선언

static void read_line(char* buf, int size);
static void print_contact(int);
static void trim_newline(char* s);	// 줄바꿈 제거 기능 추가
static int contains_pipe(const char* s);	// 입력 문자열 중에 |가 존재하는지 확인
static int find_by_phone(const char* phone);	// 같은 전화번호 중복 체크
static int cmp_contact_name(const void* a, const void* b);
static int ab_ensure_capacity(int need);	// 용량 추가여부 확인

#pragma endregion

#pragma region 사용자함수 정의 영역

// 메뉴 출력 함수
void print_menu(void) {
	puts("========================================");
	puts("        주소록 프로그램 (Step 8)        ");
	puts("========================================");
	puts("1. 추가");
	puts("2. 목록");
	puts("3. 검색");
	puts("4. 수정");
	puts("5. 삭제");
	puts("6. 정렬");
	puts("7. 종료");
	//puts("7. 저장");	// 데이터 저장
	//puts("8. 로드");	// 데이터 로드
	puts("----------------------------------------");
}

// 메뉴 번호 읽기 함수
int read_menu(void) {
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
void add_contact(void) {
	/*if (count >= MAX_CONTACTS) {
		puts("주소록 최대 인원 100명에 도달했습니다.");
		return;
	}*/

	if (!ab_ensure_capacity(count + 1)) {
		puts("메모리 추가에 실패했습니다.");
		return;
	}

	puts("[ADD] 새 연락처 입력");

	printf("[ADD] 이름 (최대 10자) : ");
	read_line(contacts[count].name, NAME_LEN);
	if (contains_pipe(contacts[count].name)) {	// 이름에 파이프가 들어가면?
		puts("[ADD] '|' 문자는 사용할 수 없습니다. 다시 추가하세요.");
		return;	// 함수 종료
	}

	printf("[ADD] 전화 (최대 20자) : ");
	read_line(contacts[count].phone, PHONE_LEN);
	if (strlen(contacts[count].phone) == 0) {
		puts("[ADD] 전화번호는 필수입니다.");
		return;
	}

	{ // 영역을 구분 짓는 코드블럭
		int dup = find_by_phone(contacts[count].phone);
		if (dup != -1) {
			printf("[ADD] 동일한 전화번호가 존재합니다. (No: %3d, 이름: %10s)\n", dup, contacts[dup].name);
			puts("추가 취소!");
			return;
		}
	}

	printf("[ADD] 주소 (최대 40자) : ");
	read_line(contacts[count].address, ADDR_LEN);
	if (contains_pipe(contacts[count].address)) {	// 이름에 파이프가 들어가면?
		puts("'|' 문자는 사용할 수 없습니다. 다시 추가하세요.");
		return;	// 함수 종료
	}

	printf("[ADD] 이메일 : ");
	read_line(contacts[count].email, EMAIL_LEN);
	if (contains_pipe(contacts[count].email)) {	// 이름에 파이프가 들어가면?
		puts("'|' 문자는 사용할 수 없습니다. 다시 추가하세요.");
		return;	// 함수 종료
	}

	printf("[ADD] 메모 (최대 30자) : ");
	read_line(contacts[count].memo, MEMO_LEN);
	if (contains_pipe(contacts[count].memo)) {	// 이름에 파이프가 들어가면?
		puts("'|' 문자는 사용할 수 없습니다. 다시 추가하세요.");
		return;	// 함수 종료
	}

	count++;
	puts("추가 완료!");
}

// 메뉴 2번 기능, 연락처 목록
void list_contacts(void) {
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
void search_contact(void) {
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
void print_contact(int index) {
	printf("[SEARCH] 이름   : %s\n", contacts[index].name);
	printf("[SEARCH] 전화   : %s\n", contacts[index].phone);
	printf("[SEARCH] 주소   : %s\n", contacts[index].address);
	printf("[SEARCH] 이메일 : %s\n", contacts[index].email);
	printf("[SEARCH] 메모   : %s\n", contacts[index].memo);
}

// 메뉴 4번 기능, 수정 함수
void update_contact(void) {
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
void delete_contact(void) {
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
int save_contacts(const char* filename) {
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
int load_contacts(const char* filename) {
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

		//if (count >= MAX_CONTACTS) break;	// 현재 100개 밖에 못 넣음.
		if (!ab_ensure_capacity(count + 1)) {
			puts("불러오기 중 메모리 부족!");
			break;
		}

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

int contains_pipe(const char* s) {
	return (strchr(s, '|') != NULL);	// 발견된 | 이후의 문자열이 리턴된다.
}

int find_by_phone(const char* phone) {	// 전화번호 중복 체크
	int i;

	for (i = 0; i < count; i++) {
		if (strcmp(contacts[i].phone, phone) == 0) {
			return i;	// 현재 인덱스 값이 폰 번호가 같다.
		}
	}
	return -1;	// 일치하는 게 없음.
}

int cmp_contact_name(const void* a, const void* b) {
	const Contact* ca = (const Contact*)a;
	const Contact* cb = (const Contact*)b;

	return strcmp(ca->name, (*cb).name);	// 둘 다 같은 방식임. 편한 걸로 사용. 1, 0, -1 중 나옴.
}

// 퀵소트로 이름순 정렬
void sort_by_name(void) {
	if (count <= 1) {
		puts("[SORT] 정렬이 필요하지 않습니다.");
		return;
	}

	// 퀵소트
	qsort(contacts, count, sizeof(Contact), cmp_contact_name);
	puts("[SORT] 이름순으로 정렬되었습니다.");
}

// 주소록 초기화
int ab_init(void) {
	capacity = INIT_CAPACITY;
	count = 0;
	// 동적할당
	contacts = (Contact*)malloc(sizeof(Contact) * capacity);	// Contact 구조체를 10개 만들고 시작!
	if (!contacts) {
		puts("메모리 할당에 실패했습니다.");
		return 0;
	}
	return 1;	// 성공
}

// 주소록 메모리 해제
void ab_free(void) {
	free(contacts);
	contacts = NULL;	// NULL로 할당해서 완전제거
	count = 0;
	capacity = 0;
}


// 주소록 크기가 작으면 동적으로 늘리는 함수
static int ab_ensure_capacity(int need) {
	Contact* newbuf;
	int newcap;

	if (need <= capacity) return 1;

	newcap = capacity;
	while (newcap < need) {
		// 2배 확장
		newcap = newcap * 2;
	}

	newbuf = (Contact*)realloc(contacts, sizeof(Contact) * newcap);
	if (!newbuf) {
		puts("메모리 재할당에 실패했습니다. (메모리가 부족합니다.)");
		return 0;
	}

	contacts = newbuf;
	capacity = newcap;	// 10 -> 20 -> 40 ...
	return 1;
}

#pragma endregion