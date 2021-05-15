#include <stdio.h>
#include <stdlib.h>
#include "namecard/NameCard.h"
#include "arraylist/ArrayList.h"

int main(void) {
    List list;
    ListInit(&list);

    LInsert(&list, MakeNameCard("학생1", "010-1111-1111"));
    LInsert(&list, MakeNameCard("학생2", "010-2222-2222"));
    LInsert(&list, MakeNameCard("학생3", "010-3333-3333"));

    NameCard *ptrCard;

    printf("1. 학생2 탐색하여 정보출력\n");
    if (LFirst(&list, &ptrCard)) {
        if (NameCompare(ptrCard, "학생2") == 0) {
            ShowNameCardInfo(ptrCard);
            printf("\n");
        }
        while (LNext(&list, &ptrCard)) {
            if (NameCompare(ptrCard, "학생2") == 0) {
                ShowNameCardInfo(ptrCard);
                printf("\n");
            }
        }
    }

    printf("\n2. 학생3 탐색하여 전화번호 변경\n");
    if (LFirst(&list, &ptrCard)) {
        if (NameCompare(ptrCard, "학생3") == 0) {
            ChangePhoneNum(ptrCard, "010-9999-9999");
            ShowNameCardInfo(ptrCard);
        }
        while (LNext(&list, &ptrCard)) {
            if (NameCompare(ptrCard, "학생3") == 0) {
                ChangePhoneNum(ptrCard, "010-9999-9999");
                ShowNameCardInfo(ptrCard);
            }
        }
    }

    printf("\n\n3. 학생1 탐색하여 정보삭제\n");
    if (LFirst(&list, &ptrCard)) {
        if (NameCompare(ptrCard, "학생1") == 0) {
            free(LRemove(&list));
        }
        while (LNext(&list, &ptrCard)) {
            if (NameCompare(ptrCard, "학생1") == 0) {
                free(LRemove(&list));
            }
        }
    }

    printf("\n4. 남아있는 모든 사람의 전화번호 정보 출력\n");
    if (LFirst(&list, &ptrCard)) {
        ShowNameCardInfo(ptrCard);
        printf("\n");
        while (LNext(&list, &ptrCard)) {
            ShowNameCardInfo(ptrCard);
            printf("\n");
        }
    }
    return 0;
}