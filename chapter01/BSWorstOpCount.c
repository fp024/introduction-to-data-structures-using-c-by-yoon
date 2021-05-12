#include <stdio.h>

int BSearch(int array[], int length, int target) {
    int first = 0;
    int last = length - 1;
    int mid;
    int opCount = 0;  // 비교연산의 횟수를 기록

    while (first <= last) {
        mid = first + (last - first) / 2;

        if (array[mid] == target) {
            return mid;
        } else if (array[mid] > target) {
            last = mid - 1;
        } else {
            first = mid + 1;
        }
        opCount += 1; // 비교 연산의 횟수 1증가
    }
    printf("비교연산횟수: %d\n", opCount); // 탐색 실패시 연산 횟수 출력
    return -1;
}

void searchWithPrintResult(int array[], int length, int target) {
    int idx = BSearch(array, length, target);
    if (idx == -1) {
        printf("탐색 실패\n");
    } else {
        printf("타겟 저장 인덱스: %d\n", idx);
    }
}


int main(void) {
    int array1[500] = {0,};     // 모든 요소 0으로 초기화
    int array2[5000] = {0,};    // ""
    int array3[50000] = {0,};   // ""

    // 배열 array1을 대상으로, 저장되지 않은 정수 1을 찾으라고 명령
    searchWithPrintResult(array1, sizeof(array1)/ sizeof(int), 1);

    // 배열 array2을 대상으로, 저장되지 않은 정수 1을 찾으라고 명령
    searchWithPrintResult(array2, sizeof(array2)/ sizeof(int), 1);

    // 배열 array2을 대상으로, 저장되지 않은 정수 1을 찾으라고 명령
    searchWithPrintResult(array3, sizeof(array3)/ sizeof(int), 1);

    return 0;
}

/* // 결과  2^9: 512,  2^13: 8192, 2^16: 65536 
    비교연산횟수: 9
    탐색 실패
    비교연산횟수: 13
    탐색 실패
    비교연산횟수: 16
    탐색 실패
*/