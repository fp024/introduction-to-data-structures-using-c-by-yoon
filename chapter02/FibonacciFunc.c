#include <stdio.h>

/*
    fib(n) // n번째 피보나치 수 계산
        n = 1 이면 0
        n = 2 이면 1
        n 이면 fib(n - 1) + fib(n - 2)

    재귀 함수의 호출 흐름은 60페이지의 그림 02-5, 02-6을 참고하자.
*/
int Fibo(int n) {
    if (n == 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else {
        return Fibo(n - 1) + Fibo(n - 2);
    }
}

int main(void) {
    for (int i = 1; i < 15; i++) {
        printf("%d\t", Fibo(i));
    }
    return 0;
}
/* ===== 실행 결과 =====
0       1       1       2       3       5       8       13      21      34      55      89      144     233
*/
