#include <stdio.h>

/**
 * 이진 탐색의 재귀 버전
 * 
 * (기타)
 *    포인터형에 대해서 상위에서 값을 고정하기위해 const를 입력하면, 
 *    관련 함수까지 전부 const선언이 명시되어야 컴파일러 경고가 뜨지 않는다.
 */
int BSearchRecursive(const int array[], int first, int last, int target) {
    // 탈출 조건
    if (first > last) {
        return -1;
    }

    const int mid = first + (last - first) / 2;

    if (array[mid] == target) {
        return mid;
    } else if (array[mid] > target) {
        return BSearchRecursive(array, first, mid - 1, target);
    } else {
        return BSearchRecursive(array, mid + 1, last, target);
    }
}

void searchWithPrintResult(const int array[], int length, int target);

int main(void) {
    const int array[] = {1, 3, 5, 7, 9, 11};
    const int length = sizeof(array) / sizeof(int);

    searchWithPrintResult(array, length, 7);
    searchWithPrintResult(array, length, 4);
    searchWithPrintResult(array, length, 1);
    searchWithPrintResult(array, length, 9);
    searchWithPrintResult(array, length, 11);
    searchWithPrintResult(array, length, 3);
    searchWithPrintResult(array, length, 5);

    return 0;
}

void searchWithPrintResult(const int array[], int length, int target) {
    int idx = BSearchRecursive(array, 0, length - 1, target);
    if (idx == -1) {
        printf("타겟(%d) 탐색 실패\n", target);
    } else {
        printf("타겟(%d) 저장 인덱스: %d\n", target, idx);
    }
}

/* === 결과 ===
타겟(7) 저장 인덱스: 3
타겟(4) 탐색 실패
타겟(1) 저장 인덱스: 0
타겟(9) 저장 인덱스: 4
타겟(11) 저장 인덱스: 5
타겟(3) 저장 인덱스: 1
타겟(5) 저장 인덱스: 2

*/