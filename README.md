# iot-basic-programming-2026
IoT 개발자 과정 기초 프로그래밍 언어 학습 repository 

## 1일차

- Git, Github Desktop 설치
    - https://git-scm.com/ 에서 Install for Windows 로 다운로드 진행
    - https://desktop.github.com/download/ 에서 다운로드 후 설치
- Visual Studio Code 설치
    - https://code.visualstudio.com/download 운영체제별 다운로드 버튼 클릭
    - 특정폴더에 지정해서 설치 (예, C:\DEV\IDE)
- VSCode 상의 README 미리보기 : Ctrl + Shift + V

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
- 프로그램 : 컴퓨팅 환경(PC, 모바일, 임베디드 등)에서 `사용자의 요구`에 따라 `데이터를 처리`(표현, 이동, 저장, 로드 등) 할 수 있는 `소프트웨어`
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
    - 컴파일러 - C/C++ 컴파일러, JAVA 컴파일러, C# 등 언어 자체를 컴파일하는 프로그램

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

    ![alt text](image-10.png)

    - 포커스 중인 프로젝트가 시작 프로젝트로 설정됨.


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
        - 많은 데이터형 중에서 char(1), int(4), double(8)만 우선적으로 기억
    - 실수형 및 변수 : [확인](./Day-02/Chap03-Solution/Chap03-02-app/main.c)
    - 데이터 입력 : [확인](./Day-02/Chap03-Solution/Chap03-03-app/main.c)

    - 연산자 : [확인](./Day-02/Chap04-Solution/Chap04-01-app/main.c)
        - 수치연산, 논리연산, 관계연산, 비트연산,

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
        - 주소 연산자 `&` : [확인](./Day-04/Chap09-Solution/Chap09-02-app/main.c)
        - 간접 참조 연산자(포인터 연산자) `*` : [확인](./Day-04/Chap09-Solution/Chap09-03-app/main.c)

## 5일차

### C 중급 문법

1. **포인터**

    ![alt text](image-6.png)
    - 포인터 이해 : [확인](./Day-05/Chap09-Solution/Chap09-02-app/main.c)
        - 변수의 주소(메모리상)를 담고, 간접참조연산자(*)로 그 변수의 값을 사용하기 위한 것
        - 변수의 주소를 변경해서 `여러 변수를 사용 가능`
        - 변수의 주소는 바뀌지 않는 값 (상수). 변수의 주소는 바꿀 수 없다.
        - 변수의 가리키는 값(*)은 변경 가능 (변수)
        - 포인터에 주소를 저장할 때는 자료형이 동일해야

    - 포인터 크기 : [확인](./Day-05/Chap09-Solution/Chap09-03-app/main.c)
        - 주소의 크기와 동일 - 8bytes(64비트이므로)

    - 포인터 사용 이유 : [확인](./Day-05/Chap09-Solution/Chap09-05-app/main.c)
        - 용량이 제한된 [임베디드 시스템](https://ko.wikipedia.org/wiki/%EC%9E%84%EB%B2%A0%EB%94%94%EB%93%9C_%EC%8B%9C%EC%8A%A4%ED%85%9C)에서 데이터를 공유하는 목적
        - 함부로 변수를 마구 찍어서 만들 수 없음! (용량 제한이 있기 때문에!)
        - 주소를 공유해서 함수 어디서나 변수의 값을 변경할 수 있음!
        - 함수 간에 효과적으로 데이터를 공유하고 용량(메모리, 저장소)을 절약!
    
2. 배열과 포인터 : [확인](./Day-05/Chap10-Solution/Chap10-01-app/main.c)
    - 배열과 포인터는 매우 흡사해서 유사하게 사용 가능하다.
    - scanf() 배열 str[80] 선언 후, &str로 사용
    - 직접적인 연관이 있음
    - 실무에서 데이터를 공유하면 보통 배열도 많이 사용됨
    - 배열을 매개변수로 전달하면 메모리를 많이 사용하게 됨
    - int ary[100] -> main에서 400bytes, 함수에서 400bytes를 메모리공간 확보(`메모리 부족사태`)
    - 배열의 주소를 함수에 전달 : [소스](./Day-05/Chap10-Solution/Chap10-03-app/main.c)

3. 문자 : [확인](./Day-05/Chap11-Solution/Chap11-01-app/main.c)
    - getchar() 입력버퍼 한글자 지우기 : [확인](./Day-05/Chap11-Solution/Chap11-02-app/main.c)

4. 문자 기본 : [확인](./Day-05/Chap12-Solution/Chap12-01-app/main.c)
    - 문자열 상수와 문자 포인터 변수 사용법

## 6일차

### C 중급 문법

4. 문자열과 포인터 : [확인](./Day-06/Chap12-Solution/Chap12-01-app/main.c)
    - 문자열 연산 함수
        - 자주 사용하는 문자열 처리 내장 함수
        - `strlen()` : 문자열 길이 리턴 함수
        - `strcpy()`, strncpy() : 문자열 대입 함수, n은 글자 갯수만큼 대입
        - strcat(), strncat() : 문자열 합치기 함수
        - `strcmp()`, strncmp() : 문자열 비교 함수, 두 문자열이 같은지 확인
        - strcspn() : 문자열에서 찾고자 하는 문자열에 포함된 문자를 검색, 일치할 때까지 읽어들인 문자의 갯수 리턴
        - strtok() : 패턴 문자열로 기존 문자열을 자르는 함수
        - strchr() : 문자열에서 특정 문자가 가장 먼저 나타나는 곳의 위치를 리턴하는 함수
    
5. TIP
    - #pragma region, #pragma endregion
        - 소스코드 영역에서 일부 내용을 축소(확장)시키고자 할 때 사용한다.

6. 변수 영역 : [확인](./Day-06/Chap13-Solution/Chap13-01-app/main.c)
    - 같은 이름의 변수가 있으면 코드블록 내의 변수가 우선적으로 사용된다!!
    - `auto` : 지연변수. auto라는 키워드를 사용 안 함. (안 써도 무방하다는 의미!)
    - global : 전역변수. ~~global~~라는 키워드를 사용 안 함. (그냥 의미 표시!) 
        - 전역변수는 문제가 많으므로 제한적으로 사용할 것!
    - `static` : 정적변수. 소스코드 전체가 실행되는 동안 살아있는 변수 [확인](./Day-06/Chap13-Solution/Chap13-02-app/main.c)
    - `register` : CPU내 존재하는 메모리, 데이터 처리속도가 가장 빠르다. (거의 쓸 일 없음!)
    - `extern` : 외부 소스에서 사용할 변수.

7. 데이터 공유 방법!! : [확인](./Day-06/Chap13-Solution/Chap13-03-app/main.c)
    - 데이터를 필요할 때마다 복사하는 것보다, 같이 공유하는 것이 메모리를 절약하는 방법
    - `값을 복사해서 전달(Call by value), 주소를 전달(Call by reference)`
    - 포인터변수로 리턴
    
8. 다차원 배열 : [확인](./Day-06/Chap14-Solution/Chap14-01-app/main.c)
    - 1차원 배열 : score[4], 크기 4의 배열 score
    - 2차원 배열 : score[4], 배열이 3개. score[3][4], 3행(row) 4열(column).

9. 포인터 배열 : [확인](./Day-06/Chap14-Solution/Chap14-02-app/main.c)
    - 2차원 배열과 유사

10. 이중포인터 : [확인](./Day-06/Chap15-Solution/Chap15-01-app/main.c)
    - 값은 a = 10 밖에 없음!!
    - 나머지는 모두 주소!!

    ![alt text](image-7.png)

    - [단일포인터](./Day-05/Chap10-Solution/Chap10-03-app/main.c) VS [이중포인터](./Day-06/Chap15-Solution/Chap15-02-app/main.c) 비교

## 7일차

### C 중급 문법

1. 함수와 void 포인터 : [확인](./Day-07/Chap15-Solution/Chap15-01-app/main.c)
    - 함수 포인터 - 함수도 메모리상에 주소를 가지고 있음.
    - 변수와 동일하게 함수도 주소를 통해서 여러 함수를 변경해서 사용
    - `어떤 함수를 연결하느냐에 따라 동작이 바뀐다.`
    - 실행 시점에 어떤 함수가 실행 될 지 모를 때 -> [확인](./Day-07/Chap15-Solution/Chap15-02-app/main.c)
    - 조건문을 줄이고, 구조를 유연하게 만들기 위해서 사용
    - 사용 예 - 임베디드 하드웨어 이벤트 인터럽트, 상태머신, GUI 이벤트, 게임 상태별 로직

2. void 포인터 : [확인](./Day-07/Chap15-Solution/Chap15-03-app/main.c)
    - void - 리턴 값이 없을 때, 매개변수가 없을 때 사용한다.
    - 포인터 특징 - int형 int*, double형 double* 와 같이 타입형이 일치해야한다.
    - 가리키는 자료형이 달라도 사용할 수 있는 포인터 -> void 포인터
    - void는 아직 자료형이 정해지지 않았음.
    - void 포인터에서 형변환을 제거하면 오류! - (int*), (double*) 등

3. 메모리 동적할당
    - 프로그램에 필요한 메모리를 원하는 만큼 확보
    - malloc - memory allocation. 메모리 동적할당 : [확인](./Day-07/Chap16-Solution/Chap16-01-app/main.c)
    - calloc - contiguos allocation. 연속된 메모리 동적할당. 0으로 초기화. malloc보다 느림. : [확인](./Day-07/Chap16-Solution/Chap16-03-app/main.c)
    - realloc - re-allocation. 메모리 크기 조정.
    - free - 메모리 반환
    - **NULL** - 아무것도 가리키지 않는 포인터 값!

4. 프로그램의 메모리 영역

    ![alt text](image-8.png)

    - 코드영역, 스택, 힙, 기타 데이터 영역 구분
    - 코드 영역 - 소스코드가 실행하는 영역
    - 스택 - 지역변수 영역
    - 힙 - 동적할당 영역, Pointer, NULL...
    - 기타 데이터 영역 - 전역변수, static 변수 영역

5. 동적 할당 저장공간 활용 : [확인](./Day-07/Chap16-Solution/Chap16-04-app/main.c)
    - 영어사전과 같은 데이터를 저장할 때 : [확인](./Day-07/Chap16-Solution/Chap16-05-app/main.c)
        - 배열로 처리하면 메모리 낭비가 심함.
        - 동적할당으로 메모리 절약

6. main 함수 명령행 인수 사용 : [확인](./Day-07/Chap16-Solution/Chap16-06-app/main.c)
    - int main(int argc, char** argv) 가 기본 메인 함수
    - 프로젝트 속성에서 명령인수 입력 방법

    ![alt text](image-9.png)

7. 사용자 정의 자료형 - 구조체 : [확인](./Day-07/Chap17-Solution/Chap17-01-app/main.c)
    - C언어는 절차적 프로그래밍 언어
    - C++는 객체지향 프로그래밍 언어. C#, Java, Python...
    - 객체지향적 개념을 사용하기 시작한 것 - 구조체

## 8일차
### C 중급 문법

1. 사용자 정의 자료형 - 구조체 : [확인](./Day-08/Chap17-Solution/Chap17-01-app/main.c)

    - 구조체 사용 : [확인](./Day-08/Chap17-Solution/Chap17-02-app/main.c)
    - 구조체 내 구조체 : [확인](./Day-08/Chap17-Solution/Chap17-03-app/main.c)
    - 구조체 포인터 : [확인](./Day-08/Chap17-Solution/Chap17-04-app/main.c)

2. 사용자 정의 자료형 - 공용체, 열거형 : [확인](./Day-08/Chap17-Solution/Chap17-05-app/main.c)

3. 파일 입출력
    - 파일 종류 : 텍스트 파일, 바이너리(2진) 파일
    - 바이너리 파일 : 데이터 파일, 내부적으로 0과 1로 저장된 파일. .dat, .exe, .mp3, .mp4...

        ![alt text](image-11.png)
    
    - 텍스트 파일 : 사람이 읽을 수 있는 문자로 된 파일. .txt, .log, .cmd, .bat, .docx, .hwpx, .pptx...

        ![alt text](image-12.png)

    - 파일 오픈 : [확인](./Day-08/Chap18-Solution/Chap18-01-app/main.c)

## 9일차
### C 중급 문법 - 마지막

1. 파일 확장명(확장자) 확인

    ![alt text](image-13.png)

    - 윈도우 탐색기 > 보기 > 표시 > `파일 확장명` 활성화
    - 각 파일 확장자를 확인 필요!

2. 폴더 및 파일경로

    - 절대 경로 - `C:\DEV\IDE\Microsoft VS Code\591199df40\resources\app\LICENSE.rtf` 와 같이, 드라이브부터 전체 경로를 모두 기재
        - 장점 - 정확한 경로가 표시
        - 단점 - 경로 문자열이 아주 길어질 수 있음.
    - 상대 경로 - `.\LICENSE.rtf` 와 같이, .(현재폴더), ..(부모폴더) 기호를 사용해서 짧게 경로를 표시 방법
        - 장점 - 경로를 짧게 표시 가능
        - 단점 - 개발자가 직접 경로가 어떤 식으로 구성되는지 파악 필요. 같은 폴더에 존재하는 경우 사용 가능.

3. 파일 입출력 : [확인](./Day-09/Chap18-Solution/Chap18-01-app/main.c)
    - 키보드 등 입력은 입력 스트림(stream)에, 출력은 출력 스트림(stream)에 보관되어 있음.
    - 파일, 콘솔 등에 전달.

    ![alt text](image-14.png)

    - fgetc() - 파일에서 글자 파일의 마지막(EOF - End Of File)까지 하나씩 읽는 함수.
    - fputc() - 파일에 글자를 한자씩 출력(쓰는)하는 함수.
    - fseek(), rewind() - 파일에 처음으로 돌아가서 다시 읽기
    - feof() - 파일을 끝까지 다 읽었는지 확인 함수
    - `fgets()` - 파일의 커서(현재위치)에서 한 줄을 읽는 함수
    - `fputs()` - 파일에 한 줄을 출력(쓰는) 함수
    - fscanf() - 포맷에 맞춰서 파일에서 쓰기 함수
    - fprintf() - 포맷에 맞춰서 파일에서 읽기 함수
    - stdio.h - stdin(표준입력), stdout(표준출력), stderr(표준에러) 포함.
    - 인코딩 방식 - EUC-KR(CP-949, 멀티바이트, 한글만 표현, 2byte), UTF-8(한글자 최대 6byte, 한글을 3byte)

4. 파일 입출력 모드 - 바이너리, 텍스트 : [확인](./Day-09/Chap18-Solution/Chap18-05-app/main.c)
     - r = 읽기(read) 모드
     - w = 쓰기(write) 모드
     - a = 추가(append) 모드
     - t = 텍스트(text) 모드 (생략)
     - b = 이진(binary) 모드
     - + = 복합 모드
     - 위의 단어를 조합해서 사용 - "rb+", "r+", etc
     - 경로를 표시하는 문자열에서 폴더 구분을 기존 "\\"와 유닉스, 리눅스, 맥OS 공통의 구분 "/" 사용 가능

5. 한글 깨짐 현상 : [확인](./Day-09/Chap18-Solution/Chap18-02-app/main.c)
    - EUC-KR 과 UTF-8 사이에서 변환 문제로 발생
    - 윈도우 설정 필요 - intl.cpl 실행 (국가 또는 지역설정 제어판 실행)
        - 국가 또는 지역 > 관리자 옵션 > 시스템 로캘 변경 > Beta: 세계 언어 지원을 위해 Unicode UTF-8 사용

        ![alt text](image-15.png)

6. 파일 핸들링 현상
    - fopen() 이후 fclose() 이전에 탐색기 등에서 파일에 접근하면 파일을 열 수 없음.

    ![alt text](image-16.png)

    - fseek() 함수 사용 시 : [확인](./Day-09/Chap18-Solution/Chap18-03-app/main.c)
        - SEEK_SET - 파일의 최초 위치
        - SEEK_CUR - 파일의 현재 위치
        - SEEK_END - 파일의 마지막 위치

7. 전처리 지시자 : [확인](./Day-09/Chap19-Solution/Chap19-01-app/main.c)
    - #include - 파일 포함 지시자, 내장 헤더파일은 <>로, 사용자 헤더파일은 "" 사용.
    - #define - 새로 정의하는 지시자. 자주 사용될 상수 값을 정의할 때 많이 사용, 주로 대문자로 지정.
    - #line - 라인번호 재정의, 파일명 재정의 지시자
    - #if, #ifdef, #else, #endif - 조건에 따라 컴파일하고자 할 때 사용하는 지시자
    - #pragma - 컴파일러의 컴파일 방법을 세부적으로 제어할때 사용
    - defined, #, ## - 전처리 연산자(나중에)

8. 분할 컴파일 : [확인](./Day-09/Chap19-Solution/Chap19-04-app/main.c)
    - 여러 파일을 분할해서 여럿이 같이 개발, 프로그램 크기 줄이기, 코드 재활용 등  
    - 전역변수 static - 외부에 공개하지않는 내부용 정적 변수
    - ~~전역변수 static은 사용하지 말 것.~~
    - 외부 소스에서는 extern으로 공유할 것. : [확인](./Day-09/Chap19-Solution/Chap19-03-app/input.c)
    - ~~static은 메인 함수가 있는 소스 코드에서 선언해야함.~~
    - extern은 어느 소스에 있는 전역 변수든지 공유할 수 있음.

9. 헤더파일 필요성, 중복 문제 해결

## 10일차
## 11일차

### 토이 프로젝트

1. static (**19장 내용 정정**)
    - 정적 키워드는 소스 코드가 동작하는 동안 끝까지 살아남은 변수, 함수
    - static으로 선언하면 자기 소스 내에서는 위와 같이 동작.
    - 외부 소스로 공유하지 않음. <-> `객체지향 언어와 정반대`!
    - 외부 소스에 공개하지 않을 변수를 static으로 지정할 것.
    - 두 소스의 같은 이름의 함수나 변수를 쓰는데 중복 문제를 해결하기 위해서 나옴.

5. 토이 프로젝트 - [주소록 프로그램](./TOYPROJECT.md)