#ifndef _ADDRESSBOOK_H_
#define _ADDRESSBOOK_H_

#define _CRT_SECURE_NO_WARNINGS

#pragma region 전처리 영역

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma endregion

#pragma region 매크로 선언 영역

// 사람은 숫자보다 이름에 익숙, 유지 보수를 위해서.
#define MAX_CONTACTS	100	// 100명의 주소록 작성
#define INIT_CAPACITY	12	// 초기값 12로 구성
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

#endif

// 외부 main.c에서 호출할 함수 리스트

#pragma region 함수선언 영역

// 함수 선언
// step1
void print_menu(void);	// 해당 소스 내에서만 쓴다.
int read_menu(void);
// step2
void add_contact(void);
void list_contacts(void);
// step3
void search_contact(void);
// step4
void update_contact(void);
void delete_contact(void);
// step5
int save_contacts(const char* filename);	// 파일명이 변경되면 안된다.
int load_contacts(const char* filename);

// step6
void sort_by_name(void);	// 이름순 정렬, qsort() 함수를 사용하므로 stdlib.h 포함해야함.
// step7
int ab_init(void);	// 주소록 초기화
void ab_free(void);	// 주소록 메모리 해제

#pragma endregion