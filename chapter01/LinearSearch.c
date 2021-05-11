#include <stdio.h>

int LSearch(int ar[], int len, int target) {  // 순차 탐색 알고리즘 적용함수
    for (int i = 0; i < len; i++) {
        if (ar[i] == target) {
            return i;  // 찾은 대상의 인덱스 값 반환
        }
    }
    return -1;  // 찾지 못했음을 의미하는 값 반환
}

void LSearchWithPrintResult(int ar[], int len, int target) {
    int idx = LSearch(ar, len, target);
    if (idx == -1) {
        printf("탐색 실패\n");
    } else {
        printf("타겟 저장 인덱스: %d\n", idx);
    }
}

int main(void) {
    int arr[] = {3, 5, 2, 4, 9};
    LSearchWithPrintResult(arr, sizeof(arr) / sizeof(int), 4);
    LSearchWithPrintResult(arr, sizeof(arr) / sizeof(int), 7);
    return 0;
}

/*
    >LinearSearch.exe
    타겟 저장 인덱스: 3
    탐색 실패

 */