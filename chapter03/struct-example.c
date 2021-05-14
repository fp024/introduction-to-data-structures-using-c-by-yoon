#include <stdio.h>
/*
    //구조체 정의 문법
    struct 구조체_이름{
        자료형 변수명;
        자료형 변수명;
        //...
    };

    typedef struct 구조체_이름{
        자료형 변수명;
        자료형 변수명;
        //...
    } 구조체_별칭;

    // typedef와 구조체 별칭을 사용하면 구조체 변수 선언할 때,
    // struct 키워드를 생략할 수 있음.
*/

typedef struct _wallet {
    // 100원짜리 동전의 수
    int coin100Num;
    // 5,000원짜리 지폐의 수
    int bill5000Num;
} Wallet;

/**
 * 지갑에서 돈을 꺼낸다
 * 
 * @param wallet        지갑 참조
 * @param coin100Num    100원짜리 동전 수
 * @param bill5000Num   5000원 짜리 지폐 수
 * @return 꺼낸 돈의 합계금액
 */
int takeOutMoney(Wallet* wallet, int coin100Num, int bill5000Num);

/**
 * 지갑에 돈을 넣는다.
 * 
 * @param wallet        지갑 참조
 * @param coin100Num    100원짜리 동전 수
 * @param bill5000Num   5000원 짜리 지폐 수
 */
void putMoney(Wallet* wallet, int coin100Num, int bill5000Num);

int main(void) {
    Wallet wallet = {0, 0};

    putMoney(&wallet, 10, 1);
    printf("wallet.coin100Num: %d, wallet.bill5000Num: %d\n", wallet.coin100Num, wallet.bill5000Num);

    putMoney(&wallet, 5, 4);
    printf("wallet.coin100Num: %d, wallet.bill5000Num: %d\n", wallet.coin100Num, wallet.bill5000Num);

    int remain = takeOutMoney(&wallet, 1, 1);
    printf("wallet.coin100Num: %d, wallet.bill5000Num: %d, take: %d\n", wallet.coin100Num, wallet.bill5000Num, remain);

    remain = takeOutMoney(&wallet, 13, 3);
    printf("wallet.coin100Num: %d, wallet.bill5000Num: %d, take: %d\n", wallet.coin100Num, wallet.bill5000Num, remain);

    remain = takeOutMoney(&wallet, 1, 1);
    printf("wallet.coin100Num: %d, wallet.bill5000Num: %d, take: %d\n", wallet.coin100Num, wallet.bill5000Num, remain);

    remain = takeOutMoney(&wallet, 1, 1);
    printf("wallet.coin100Num: %d, wallet.bill5000Num: %d, take: %d\n", wallet.coin100Num, wallet.bill5000Num, remain);

    return 0;
}

void putMoney(Wallet* wallet, int coin100Num, int bill5000Num) {
    wallet->coin100Num += coin100Num;
    wallet->bill5000Num += bill5000Num;
}

int takeOutMoney(Wallet* wallet, int coin100Num, int bill5000Num) {
    if (wallet->coin100Num < coin100Num || wallet->bill5000Num < bill5000Num) {
        printf("개수를 초과해서 돈을 꺼낼 수 없습니다.\n");
        return 0;
    }

    wallet->coin100Num -= coin100Num;
    wallet->bill5000Num -= bill5000Num;

    return coin100Num * 100 + bill5000Num * 5000;
}
