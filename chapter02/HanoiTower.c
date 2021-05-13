#include <stdio.h>

/**
 * @param n     이동할 원반 번호 번호가 클 수록 큰 원반이다.
 * @param from  원반이 꽂여있는 기둥
 * @param temp  목적지에 거쳐가기위한 임시 기둥
 * @param to    원반이 최종적으로 가야할 목적지 기둥
 */
void HanoiTower(int num, char from, char temp, char to);

int main(void) {
    HanoiTower(3, 'A', 'B', 'C');
    return 0;
}

void HanoiTower(int n, char from, char temp, char to) {
    if (n == 1) {
        printf("원반%d : %c에서 %c로 이동\n", n, from, to);
        return;
    }

    // 1. 작은 원반 n - 1 개를 A에서 B로 이동
    HanoiTower(n - 1, from, to, temp);

    // 2. 큰 원반 1개를 A에서 C로 이동
    printf("원반%d : %c에서 %c로 이동\n", n, from, to);

    // 3. 작은 원반 n - 1개를 B에서 C로 이동
    HanoiTower(n - 1, temp, from, to);
}

/* === 실행 결과 ===
    원반1 : A에서 C로 이동
    원반2 : A에서 B로 이동
    원반1 : C에서 B로 이동
    원반3 : A에서 C로 이동
    원반1 : B에서 A로 이동
    원반2 : B에서 C로 이동
    원반1 : A에서 C로 이동

*/