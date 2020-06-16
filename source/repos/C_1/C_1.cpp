/*
... iss Crew
... Made by Mukho
... 2020-06-16 Tue
... Practice for C
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num;
	printf("숫자 입력 : ");
	scanf("%d", &num); // "정수" 형식으로, num에 저장해라. / 숫자 2개 입력 " scanf("%d %d", &num1, &num2);
	printf("숫자는 %d.", num);

	return 0;
	/* C언어는 저급 언어와 고급 언어의 특징을 모두 가지고 있는 절차 지향 프로그래밍 언어(Procedure-oriented programming language)이다.
	*장점
	다양한 하드웨어로의 이식성이 좋다.
	코드가 복잡하지 않아 상대적으로 유지보수가 쉽다.
	어셈블리어 수준으로 하드웨어를 제어할 수 있다.
	코드가 간결해 완성된 프로그램의 크기가 작고 실행 속도가 빠르다.
	*단점
	배우기 어렵다.
	시스템 자원을 직접 제어할 수 있으므로 프로그래밍하는데 세심한 주의가 필요.
	*/

	/* 소스파일 -> 선행처리기 -> 컴파일러 -> 오브젝트 파일 - 시동 코드 + 표준 라이브러리 파일 -> 링커 -> 실행 파일
	1. Source file의 작성(.c)
	2. Preprocessor에 의한 선행처리(선행처리 문자 #로 시작하는 선행처리 지시문의 처리 작업. 소스를 재구성하는 것)
	3. Compiler에 의한 컴파일(소스파일->기계어, .o or .obj)
	4. Linker에 의한 링크(하나 이상의 오브젝트 파일과 라이브러리 파일, 시동 코드 등을 합쳐 하나의 파일로 만드는 작업)
	5. Executable file의 생성
	*/

	// C Program이 실행되면 Computer는 제일 먼저 main() function을 찾아서 Call한다.

	/* 서식 지정자(format specifier)
	%c : 하나의 문자
	%s : 문자열
	%d : 부호 있는 10진 정수
	%i : 부호 있는 10진 정수
	%f : 고정 소수점으로 표현한 실수(소수점 이하 6자리까지 표현)
	%o : 부호 없는 8진 정수
	%u : 부호 없는 10진 정수
	%x : 부호 없는 16진 정수
	%X : 부호 없는 16진 정수
	%e : 부동 소수점으로 표현한 실수 (e-표기법)
	%E : 부동 소수점으로 표현한 실수 (E-표기법)
	%g : 값에 따라 %f나 %e를 사용함
	%G : 값에 따라 %f나 %E를 사용함
	%% : 퍼센트 기호 % 출력
	*/

	/* 출력 필드의 폭 설정
	%nd 
	n : 필드의 폭
	%-nd = 왼쪽 정렬
	%+nd = 양수면 +기호, 음수면 -기호를 붙여서 출력
	%n.xd = x, 소수 부분의 숫자는 출력되는 소수의 자릿수
	*/

	/*
	정수형 변수 : char, int, long
	실수형 변수 : float, double

	bit -> 0 또는 1 저장
	8bit = 1byte

	변수 : 메모리의 address를 기억하는 역할.
	Memory Address : 메모리 공간에서의 정확한 위치를 식별하기 위한 고유 주소

	변수의 선언만 : int num;
	변수의 선언과 동시에 초기화 : int num = 0;
	*/

	/*
	상수(Constant)
	데이터를 저장할 수 있는 메모리 공간. 프로그램이 실행되는 동안 상수에 저장된 데이터는 변경할 수 없다.

	- Literal Constant : 변수와는 달리 데이터가 저장된 메모리 공간을 가리키는 이름을 가지고 있지 않다.
		정수형 : 123, -456과 같이 아라비아 숫자와 부호로 직접 표현
		실수형 : 3.14, -45.6과 같이 소수 부분을 가지는 아라비아 숫자로 표현
		문자형 : 'a', 'Z'와 같이 따옴표로 감싸진 문자로 표현
	- Symbolic Constant : 반드시 선언과 동시에 초기화되어야 한다.
		const int MAX = 10; : const 키워드를 이용한 심볼릭 상수
		#define MAX 10; : #define 선행처리 지시자를 이용한 매크로 심볼릭 상수
	*/

	/*
	정수형 타입
		2byte
		short : -32,768 ~ 32,767
		unsigned short : 0 ~ 65,535
		4byte
		int : - 2,147,483,648 ~ 2,147,483,647
		unsigned int : - 0 ~ 4,294,967,296
		long : - 2,147,483,648 ~ 2,147,483,647
		unsigned long : - 0 ~ 4,294,967,296

	실수형 타입
		4byte
		float : (3.4 * 10^-38) ~ (3.4 * 10^38)
		8byte
		double / long double : (1.7 * 10^-308) ~ (1.7 * 10^308)

	문자형 타입
		1byte
		char : 2^7 ~ 2^-7
		2byte
		unsigned char : 0 ~ 2^8
		char ch = 'a';
			printf("변수 ch에 저장된 값은 %c입니다.\n", ch); // a
			printf("변수 ch에 저장된 값은 %d입니다.\n", ch); // 97 -> 아스키 코드
	*/

	/*
	타입 변환
		묵시적 타입 변환(자동 타입 변환, inplicit type conversion)
			C 컴파일러가 자동으로 실행해주는 타입 변환.
			연산자의 오른쪽에 존재하는 data type이 왼쪽에 있는 data type으로 변환됨.
			산술 연산에서는 데이터의 손실이 최소화되는 방향으로 진행됨.
			- char -> short -> int -> long -> float -> double -> long double
		명시적 타입 변환(강제 타입 변환, explicit type conversion)
			사용자가 Type Cast 연산자를 사용하여 강제적으로 수행하는 타입 변환.
			변환하고자 하는 데이터의 앞에 괄호를 추가하고, 그 안에 변환할 타입을 적으면 됨.
	*/

	/*
	산술 연산자 : +, -, *, /, %
	연산자 우선순위<참고용>
		1. 후위 증가/감소 연산자, 함수 호출(), 첨자 연산자[], 참조에 의한 선택(.), 포인터를 통한 선택(->)
		2. 논리 NOT 연산자(!), 비트 NOT 연산자(~), 단항 연산자(+, - 부호), 전위 증가/감소 연산자, 타입 캐스트 연산자, 참조/주소 연산자(*, &), 크기(sizeof)
		3. *, /, %
		4. +, -
		5. 비트 시프트 연산자 <<, >> : Left Shift는 *2, Right Shift는 /2, ~(not)은 1의 보수와 같다.
		6. 관계 연산자 <, >, >=, <=
		7. 관계 연산자 ==, !=
		8. 비트 AND 연산자 &
		9. 비트 XOR 연산자 ^
		10. 비트 OR 연산자 |
		*11. 논리 AND 연산자 &&
		*12. 논리 OR 연산자 ||
		13. 삼항 조건 연산자 ? : ( 조건식 ? 참일 때 반환값 : 거짓일 때 반환값 )
		14. 대입 연산자 및 복합 대입 연산자 =, +=, -=, *=, /=, %=, <<=, >>=, &=, ^=, |=
		15. 쉼표 연산자 ,

		주소 연산자(&) : 변수의 이름 앞에 사용하여, 해당 변수의 주소값을 반환
		참조 연산자(*) : 포인터의 이름이나 주소 앞에 사용하여, 포인터에 가리키는 주소에 저장된 값을 반환
	*/

	/*
		if문 : if,  else if, else
		switch문 : 가독성이 좋고, 컴파일러가 최적화를 쉽게 할 수 있어 속도도 빠르나
				   switch문의 조건 값으로는 int형으로 승격할 수 있는(integer promotion) 값만이 사용될 수 있다. - char, short, int, literal, enum
		switch(조건값)
		{
			case 값1:
				조건값이 값1일 때 실행할 명령문;
				break;
			case 값2:
				조건값이 값2일 때 실행할 명령문;
				break;
			default:
				조건값이 어떠한 case 절에도 해당하지 않을 때 실행할 명령문;
				break;
		}
	*/

	/*
	반복문 while, do while, for

	do while : 먼저 루프를 한 번 실행한 후에 조건식을 검사.
	do{
		조건식의 결과가 참인 동안 반복적으로 실행하고자 하는 명령문;
	}while (조건식);

	loop의 control
		continue : loop 내에서 사용하여 해당 loop의 나머지 부분을 건너뛰고, 바로 다음 조건식의 판단으로 넘어가게 함(특정 조건에 대한 예외 처리를 할 때 사용)
			** 1부터 100까지의 정수 중에서 3의 배수를 제외하고 출력하는 예제
			int i;
			int except_num = 3;
			for (i = 1; i <= 100; i++){
				if (i % except_num == 0)
					continue;
				printf("%d ", i);
			}
		break : loop 내에서 사용하여 해당 반복문을 완전히 종료시킨 뒤, 반복문 바로 다음에 위치한 명령문을 실행(반복문을 완전히 빠져나가고 싶을 때 사용)
		goto : 프로그램의 흐름을 지정된 label로 무조건 변경시키는 명령문이나, 프로그램의 흐름을 매우 복잡하게 만들기도 해 디버깅 이외에는 거의 사용하지 않는다.
	*/

	/*
	Function : 표준 함수, 사용자 정의 함수
		사용하는 이유 : 반복적인 프로그래밍을 피할 수 있기 때문.
						프로그램을 여러 개의 함수로 나누어 작성하면, 모듈화로 인해 전체적인 코드의 가독성이 좋아짐
						프로그램에 문제가 발생하거나 기능의 변경이 필요할 때에도 손쉽게 유지보수를 할 수 있음
	
	int sum(x, y) -> 반환자료형 함수이름(매개변수 목록)
	{
		함수 몸체
	}

	int bigNum(int, int); // 함수의 원형 선언
	int main(){...}
	int bigNum(int num1, int num2){...} // 함수의 정의
	*/

	/*
	메모리의 구조
		Code / Data / Stack / Heap
	변수의 유효 범위
		- Local variable(지역 변수) : Block 내에서 선언된 변수. 변수가 선언된 블록 내에서만 유효. 메모리상의 Stack 영역에 저장, 초기화안하면 쓰레기값.
		- Global variable(전역 변수) : 함수의 외부에서 선언된 변수. 프로그램 어디서나 접근할 수 있으며 프로그램이 종료되어야만 메모리에서 사라짐.
									   메모리상의 Data 영역에 저장됨. 초기화 안해도 0으로 자동 초기화됨. 전역 변수와 같은 이름으로 지역 변수를 선언하는 것은 좋지 않다.
		- Static variable(정적 변수) : static 키워드로 선언한 변수. 지역 변수와 전역 변수의 특징을 모두 가지게 됨. 단 한번만 초기화되며 "프로그램이 종료되어야 메모리에서 사라짐". "해당 함수 내에서만 접근할 수 있음".
									   함수 내에서 스택같은 걸로 사용 가능할 듯.
									   void staticVar(){ static int static_count = 1; static_count++;}
									   ㄴ 호출할 때 마다 static_count가 1씩 증가함.
		- Register variable(레지스터 변수) : 지역 변수를 선언할 때 register 키워드를 붙여 선언한 변수. CPU의 register 메모리에 저장되어 빠르게 접근할 수 있게 됨.

		[변수 종류 : 키워드 / 선언 위치 / 유효 범위 / 메모리 소멸 시기 / 초깃값 / 저장 장소]
		[지역 변수 : auto / 함수,블록의 내부 / 함수,블록의 내부 / 함수 종료시 / 초기화되지 않음 / 스택 영역]
		[전역 변수 : extern / 함수의 외부 / 프로그램 전체 / 프로그램 종료시 / 0 / 데이터 영역]
		[정적 변수 : static / 함수,블록의 내부 / 함수,블록의 내부 / 프로그램 종료시 / 0 / 데이터 영역]
		[레지스터 변수 : register / 함수,블록의 내부 / 함수,블록의 내부 / 함수 종료시 / 초기화되지 않음 / CPU의 레지스터]
	*/
}