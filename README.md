# iot-basic-programming-2026
IoT 개발자 과정 기초 프로그래밍 언어 학습 repository 

## 1일차

- Git, Github Desktop 설치
- Visual Studio Code 설치
- README 미리보기 : Ctrl + Shift + V

### C언어 학습 순서
- 기본
    1. 프로그램 기본
    2. 상수와 데이터 출력
    3. 변수와 데이터 입력
    4. 연산자
    5. 제어문, `분기문`과 `반복문`
    6. 함수

- 고급
    1. 배열
    2. `포인터`!
    3. 배열과 포인터
    4. 문자열과 포인터
    5. 변수의 영역과 데이터 공유
    6. 다차원 포인터
    7. 구조체 자료형
    8. 파일 입출력
    9. 전처리와 분할 컴파일

### 프로그램 개요
- 프로그램 : `사용자의 요구`에 따라 `데이터를 처리`(표현, 이동, 저장, 로드 등) 할 수 있는 `소프트웨어`
- 일의 순서를 의미, 일의 순서를 컴퓨터 내에서 실행하는 것
- 프로그램을 만드는 작업 : 프로그래밍(코딩, SW 개발, 소프트웨어 엔지니어)

### C언어
- 1972년, 켄 톰슨과 데니스 리치가 Unix 운영체제 개발하기 위해서 만든 언어
- C++, Java, C#, Python 등 모든 언어의 기본이 되는 언어
- C99 표준에 따라서 학습

### 컴파일과 컴파일러
- 컴파일 : 소스코드파일(텍스트파일)을 컴퓨터가 실행할 수 있는 파일로 변경, 생성
    - 전처리, 링킹, 오브젝트화, 실행파일로...
    - c, cpp -> 확장자 exe 파일로 생성
- 컴파일러 : IDE(Integrity Development Environment) 툴을 사용
    - `Visual Studio`, Visual Code, Rider, Eclipse 등 

### 비주얼 스튜디오 설치
- https://visualstudio.microsoft.com/ko/ 에서 무료 다운로드 받기 버튼 클릭

    1. Visual Studio Installer 실행

        ![alt text](image.png)

    2. 설치 중

        ![alt text](image-1.png)

### 비주얼 스튜디오 프로젝트 생성

1. 새 프로젝트 만들기

    ![alt text](image-2.png)

2. 새 프로젝트 구성

    - 솔루션 이름, 프로젝트 이름을 다르게 지정
    - 위치는 GitHub 저장소 하위 위치

    ![alt text](image-3.png)


3. 새 프로젝트 추가

    - 기존 솔루션에 새 프로젝트 추가

    ![alt text](image-4.png)

4. 소스코드 확장자를 변경

    - *.cpp -> *.c 로 변경

5. 01, 02 c 코딩

6. 메뉴 디버그 > 디버그 하지 않고 시작 (Ctrl + F5) 클릭

7. 전체 컴파일 과정

    ![alt text](image-5.png)

9. 프로젝트가 여러 개 일때
    - `솔루션 속성` > `시작 프로젝트 구성` > `현재 선택 영역`으로 선택


### C 기본 문법

1. 기본 사용법

    - 메인 함수 작성법 : [확인](./Day-01/Chap02-Solution/Chap02-01-app/main.c)

    - 데이터 출력 방법 : [확인](./Day-01/Chap02-Solution/Chap02-02-app/main.c)

    - 진법 사용방법 : 아래 확인
        - 2진수 -> 컴퓨터의 데이터가 모두 0, 1로만 저장되어 있으므로
        - 8진수 -> 비트로 데이터를 처리할 때 비트 단위가 8이므로
        - 16진수 -> 255까지의 수를 짧게 표현하고자 사용
        - 10진수 -> 사람이 쓰는 거니까

    - 진수별 표현법 : [확인](./Day-01/Chap02-Solution/Chap02-03-app/main.c)

        |10진수|0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15|
        |:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
        |8진수|0|1|2|3|4|5|6|7|10|11|12|13|14|15|16|17|
        |16진수|0x0|0x1|0x2|0x3|0x4|0x5|0x6|0x7|0x8|0x9|0xA|0xB|0xC|0xD|0xE|0xF|


## 2일차

### C 기본 문법 계속 진행

1. 기본 문법

    - 데이터형 : [확인](./Day-02/Chap03-Solution/Chap03-01-app/main.c)
    - 실수형 및 변수 : [확인](./Day-02/Chap03-Solution/Chap03-02-app/main.c)
    - 데이터 입력 : [확인](./Day-02/Chap03-Solution/Chap03-03-app/main.c)

    - 연산자 : [확인](./Day-02/Chap04-Solution/Chap04-01-app/main.c)

2. 퀴즈
    - 3문제 진행
        - [1] [확인](./Day-02/Chap04-Solution/Chap04-quiz-1/main.c)
        - [2] [확인](./Day-02/Chap04-Solution/Chap04-quiz-2/main.c)
        - [3] [확인](./Day-02/Chap04-Solution/Chap4-quiz-4/main.c)

## 3일차

### C 기본 문법 계속 진행

1. 제어문 - 선택문/분기문
    - if 문 : [확인](./Day-03/Chap05-Solution/Chap05-01-app/main.c)
    - switch-case 문 : [확인](./Day-03/Chap05-Solution/Chap05-02-app/main.c)

2. 반복문
    - while, do-while : [확인](./Day-03/Chap05-Solution/Chap05-03-app/main.c)
    - for : [확인](./Day-03/Chap05-Solution/Chap05-04-app/main.c)
    - 구구단 : [확인](./Day-03/Chap05-Solution/Chap05-05-app/main.c)
    - 무한루프 : [확인](./Day-03/Chap05-Solution/Chap05-06-app/main.c)
    - continue, break : [확인](./Day-03/Chap05-Solution/Chap05-07-app/main.c)

3. **디버깅 기본**
    - 단축키
        - F5 : 디버깅 시작
        - Shift + F5 : 디버깅 종료
        - F9 : break 포인트 toggle
        - F10 : 디버깅 소스코드 한 줄 실행, 함수를 실행하고 그냥 넘어감.
        - F11 : 소스코드 내 `함수`나 `클래스`가 존재하면 내부로 진입
        - 로컬, 조사식 창 활용!

4. 함수
    - 함수 기본 : [확인](./Day-03/Chap07-Solution/Chap07-01-app/main.c)

## 4일차

### C 기본 문법 계속

1. 함수 계속
    - 함수 유형 : [확인](./Day-03/Chap07-Solution/Chap07-02-app/main.c)
        - 매개변수 없는 함수
        - 반환값이 없는 함수
        - 매개변수와 반환값이 없는 함수
        - `매개변수, 반환값이 있는 함수` - Chap07-01-app
    - 재귀호출 함수 : [확인](./Day-03/Chap07-Solution/Chap07-03-app/main.c)
    
2. 배열
    - 동일 자료형의 묶음 - `ary[10]`
    - 배열 선언, 초기화 : [확인](./Day-04/Chap08-Solution/Chap08-01-app/main.c)
    - 문자배열(문자열) : [확인](./Day-04/Chap08-Solution/Chap08-03-app/main.c)
    - 대소문자 변환 : [확인](./Day-04/Chap08-Solution/Chap08-04-app/main.c)

3. 포인터
    - 변수 스코프 : [확인](./Day-04/Chap09-Solution/Chap09-01-app/main.c)
    - 변수에 담긴 데이터를 공유하기 위해서...
    - 프로그램에서 사용하는 `메모리를 절약`하기 위한 목적
    - 메모리 주소
        - 주소 연산자 `&`
        - 간접 참조 연산자(포인터 연산자) `*`
    - 포인터 이해
