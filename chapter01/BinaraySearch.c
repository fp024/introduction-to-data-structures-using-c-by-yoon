#include <stdio.h>
#include <stdlib.h>

/**
 * 이진 검색
 * 
 * 입력된 배열은 정렬된 상태여야함.
 * 
 * @param array   검색할 배열
 * @param length  검색할 배열의 크기
 * @param target  검색할 값
 * 
 * @return 검색된 값의 배열 인덱스번호, 찾지 못했을 경우 -1
 */
int BSearch(int array[], int length, int target);

/**
 * qsort에서 사용할 비교함수
 *  a < b 일 때는 -1 반환
 *  a > b 일 때는 1반환
 *  a = b 일 때는 0을 반환
 */
int compare(const void *a, const void *b);

/**
 * 배열 내용 화면 출력
 */
void printArray(int array[], int length);

/**
 * 검색 후 결과 출력
 */
void searchWithPrintResult(int array[], int length, int target);

int main(void) {
    // 정렬되지 않은 배열
    int array[] = {9, 7, 1, 5, 3};
    int length = sizeof(array) / sizeof(int);

    printf("정렬 전...\n");
    printArray(array, length);

    // qsort 정의 <stdlib.h>
    /*
        void qsort(
                    void *__base               // 정렬할 배열
                , size_t __nmemb             // 배열의 요소 개수
                , size_t __size              // 요소 크기
                , __compar_fn_t __compar     // 비교 함수
    )
    */
    qsort(array, length, sizeof(int), compare);

    printf("정렬 후...\n");
    printArray(array, length);

    // 이진 검색
    searchWithPrintResult(array, length, 7);
    searchWithPrintResult(array, length, 4);

    return 0;
}

int BSearch(int array[], int length, int target) {
    int first = 0;          // 탐색 대상의 시작 인덱스 값
    int last = length - 1;  // 탐색 대상의 마지막 인덱스 값
    int mid = 0;

    while (first <= last) {
        // mid = (first + last) / 2;
        mid = first + (last - first) / 2;  // 오버플로우 방지를 위해, 이런 방식으로 연산하기도 했다.
        // int 표현범위의 절반을 넘게 되는 크기의 배열을 검색할 때의 오버플로우 문제를 고려한것 같다.

        if (array[mid] == target) {
            return mid;
        } else if (array[mid] > target) {
            last = mid - 1;  // 왜? -1을 하였을까?
            // 중간값이 타겟보다 크므로, 타겟이 중간기준 왼쪽에 위치할 수 있으므로,
            // 탐색대상의 마지막 인덱스 값을 중간값의 바로 직전으로 설정한다.
        } else {
            first = mid + 1;  // 왜? +1을 하였을까?
            // 중간 값이 타겟보다 작으므로, 타겟의 중간 기준 오른쪽에 위치할 수 있으므로,
            // 탐색 대상의 시작 인덱스 값을 중간 값의 바로 이후로 설정한다.
        }
    }

    return -1;  // 찾지 못했을 때 반환되는 값
}

int compare(const void *a, const void *b) {
    int aValue = *(int *)a;
    int bValue = *(int *)b;

    if (aValue < bValue) {
        return -1;
    }

    if (aValue > bValue) {
        return 1;
    }

    return 0;
}

void printArray(int array[], int length) {
    printf("배열: [");
    for (int i = 0; i < length; i++) {
        if (i == length - 1) {
            printf("%d", array[i]);
        } else {
            printf("%d, ", array[i]);
        }
    }
    printf("]\n");
}

void searchWithPrintResult(int array[], int length, int target) {
    int idx = BSearch(array, length, target);
    if (idx == -1) {
        printf("탐색 실패\n");
    } else {
        printf("타겟 저장 인덱스: %d\n", idx);
    }
}