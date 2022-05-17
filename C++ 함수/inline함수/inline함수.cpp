#include <iostream>
using namespace std;

// 함수호출과정
// 함수호출 -> 호출된시점의 주소값 스택에 저장 
// => 함수의 매개변수 스택에 저장 -> 함수 실행

// 함수 리턴 과정
// 함수의 종료 -> 함수의 리턴 값을 임시저장소에 저장
// -> 스택에서 호출 시점의 주소값을 꺼냄 -> 호출된시점으로 복귀

// 컴파일 과정
// 프로그램 작성완료 -> 컴파일 -> 링크 -> .exe 실행

// inline함수
// 실행속도가 빠르다 코드가 최적화
// 불필요하게 컴파일속도가 느려진다
// 실행파일의 크기가 커지게된다
inline int fnc_1(int a, int b)
{
    return a + b;
}

int main(void)
{
    int num;

    // 컴파일 과정에서 Inline함수부분이 치환되어
    // 밑의 함수로 들어가게 된다
    num = fnc_1(5,1);
    
    printf("%d\n", num);
    return 0;
}

