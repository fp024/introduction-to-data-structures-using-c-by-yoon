#include "ArrayList.h"

#include <stdio.h>

/**
 * 공유라이브러리로 만들어서 실행
 *    gcc -g -W -Wall -shared -o libArrayList.so ArrayList.c
 *    gcc -g -Wall -o ListMain.exe ListMain.c libArrayList.so
 * 
 *  build.bat를 실행해도 됨.
 */
void ListInit(List *ptrList) {
    // 리스트에 저장된 데이터 수 0
    ptrList->numOfData = 0;
    // 현재 아무 위치도 가리키지 않음.
    ptrList->currentPosion = -1;
}

void LInsert(List *ptrList, LData ptrData) {
    if (ptrList->currentPosion >= LIST_LEN) {
        puts("저장이 불가능합니다.");
        return;
    }

    // 데이터 저장
    ptrList->array[ptrList->numOfData] = ptrData;
    // 저장된 데이터의 수 증가
    (ptrList->numOfData)++;
}

int LFirst(List *ptrList, LData *ptrData) {
    // 데이터가 하나도 없다면
    if (ptrList->numOfData == 0) {
        return FALSE;
    }

    // 참조 위치 초기화. 첫번째 데이터 의 참조를 의미함.
    (ptrList->currentPosion) = 0;

    // ptrData가 가리키는 공간에 데이터 저장
    // 리스트의 첫번째 값을 외부 main에서 전달받아온 포인터 변수에 값으로 할당한다.
    *ptrData = ptrList->array[0];

    return TRUE;
}

int LNext(List *ptrList, LData *ptrData) {
    if ((ptrList->currentPosion) >= (ptrList->numOfData - 1)) {
        return FALSE;
    }

    (ptrList->currentPosion)++;
    *ptrData = ptrList->array[ptrList->currentPosion];
    return TRUE;
}

LData LRemove(List *ptrList) {
    int toRemovePosion = ptrList->currentPosion;
    int numOfData = ptrList->numOfData;
    // 삭제할 데이터 임시저장
    LData toRemoveData = ptrList->array[toRemovePosion];

    // 삭제를 위한 데이터의 이동을 진행하는 반복문
    for (int i = toRemovePosion; i < numOfData - 1; i++) {
        ptrList->array[i] = ptrList->array[i + 1];
    }

    // 데이터의 수 감소
    (ptrList->numOfData)--;

    // 참조위치를 하나 되돌린다.
    (ptrList->currentPosion)--;

    // 삭제된 데이터의 반환
    return toRemoveData;
}

int LCount(List *ptrList) {
    return ptrList->numOfData;
}
