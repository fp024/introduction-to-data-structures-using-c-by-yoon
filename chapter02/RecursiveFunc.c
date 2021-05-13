#include <stdio.h>

void Recursive(int num) {
    if (num <= 0) {  // 재귀 탈출조건
        return;      // 재귀의 탈출
    }

    printf("Recursive call %d \n", num);

    Recursive(num - 1);
}

void testvoid(void) {
    printf("testvoid() call\n");
}

void test() {
    printf("test() call\n");
}

int main(void) {
    Recursive(3);

    // 아래는 재귀와는 관계없지만 main()의 전달인자로 void를 왜? 넣으셨나해서...
    // 코드 내부의 일반 함수 호출에서는... 
    // void와 빈괄호의 구분이 되는데.. main(void)의 경우는 명령줄에서 파라미터 전달했다고 오류가 나진 않음.
    // 함수의 인자전달 부분에 void가 있는 것과 빈 괄호가 있는 것의 차이?
    test();
    test(1);         // 에러가 없음
    testvoid();
    // testvoid(1);  // 컴파일러 오류  error: too many arguments to function 'testvoid'

    return 0;
}

/* ===== 결과 =====
Recursive call 3 
Recursive call 2
Recursive call 1

*/