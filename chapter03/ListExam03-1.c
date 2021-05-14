#include <stdio.h>

#include "arraylist/ArrayList.h"

/**
 * 85쪽 문제 03-1
 */

/**
 * 삭제 조건 성립 여부 확인
 */
int toRemove(int data);

int main(void) {
    List list;
    ListInit(&list);

    for (int i = 1; i < 10; i++) {
        LInsert(&list, i);
    }

    LData data;
    int sum = 0;
    if (LFirst(&list, &data)) {
        sum += data;
        while (LNext(&list, &data)) {
            sum += data;
        }
    }
    printf("리스트에 저장된 총합: %d\n", sum);

    if (LFirst(&list, &data)) {
        if (toRemove(data)) {
            LRemove(&list);
        }
        while (LNext(&list, &data)) {
            if (toRemove(data)) {
                LRemove(&list);
            }
        }
    }

    if (LFirst(&list, &data)) {
        printf("%d\t", data);
        while (LNext(&list, &data)) {
            printf("%d\t", data);
        }
    }

    return 0;
}

int toRemove(int data) {
    if (data == 0) {
        return FALSE;
    }
    return ((data % 2 == 0) || (data % 3 == 0)) ? TRUE : FALSE;
}