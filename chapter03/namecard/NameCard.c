#include "NameCard.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

NameCard *MakeNameCard(char *name, char *phone) {
    NameCard *ptrCard = (NameCard *)malloc(sizeof(NameCard));
    strncpy(ptrCard->name, name, strlen(name) + 1);
    strncpy(ptrCard->phone, phone, strlen(phone) + 1);
    return ptrCard;
}

void ShowNameCardInfo(NameCard *ptrCard) {
    printf("{이름: %s, 전화번호: %s}", ptrCard->name, ptrCard->phone);
}

int NameCompare(NameCard *ptrCard, char *name) {
    return strcmp(ptrCard->name, name);
}

/**
 * 전화번호 정보를 변경
 * @param ptrCard   전화번호를 변경할 NameCard 구조체 주소
 * @param phone     전화번호
 */
void ChangePhoneNum(NameCard *ptrCard, char *phone) {
    strncpy(ptrCard->phone, phone, strlen(phone) + 1);
}