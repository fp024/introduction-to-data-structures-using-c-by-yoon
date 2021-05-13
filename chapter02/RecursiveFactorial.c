#include <stdio.h>

/*
    n * f(n -1)   ... n >= 1
    1             ... n = 0

    맨 마지막에 1을 괜히 두번 곱하게 되는게 아닌가 생각할 수 있는데..
    0! 은 1을 만족해야하므로 그렇게 처리하는 것 같다.
    윈도우 공학용 계산기(calc)에서도 0! 을 입력하면 fact(0)으로 처리되고 결과는 1임.
*/
int Factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * Factorial(n - 1);
}

int main(void) {
    printf("0! = %d\n", Factorial(1));
    printf("1! = %d\n", Factorial(1));
    printf("2! = %d\n", Factorial(2));
    printf("3! = %d\n", Factorial(3));
    printf("4! = %d\n", Factorial(4));
    printf("9! = %d\n", Factorial(9));
}

/* ===== 실행결과 =====
    0! = 1
    1! = 1
    2! = 2
    3! = 6
    4! = 24
    9! = 362880
*/
