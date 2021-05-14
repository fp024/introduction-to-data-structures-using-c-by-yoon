#include <stdio.h>
#include <stdlib.h>
#include "point/Point.h"  // 전처리기 메크로에 의존하는 부분이 생겨서 Point.h를 먼저 읽어야한다.
#include "arraylist/ArrayList.h"

int main(void) {
    List list;
    Point compPos;
    Point *ptrPos;

    ListInit(&list);

    // 4개의 데이터 저장
    ptrPos = (Point *)malloc(sizeof(Point));
    setPointPos(ptrPos, 2, 1);

    // LInsert의 두번째 인자가 int 형인데... 구조체 포인터를 주소값을 넣게된듯.
    // 문제는... 64bit 컴파일 환경이라서 ... 주소 전달값은 8바이트인데... 전달받는 int는 4바이트여서 문제가 있을 것 같은데...
    // 형변환 없이 포인터로 integer를 만들어서 문제가 있다고 경고 뜸.
    // passing argument 2 of 'LInsert' makes integer from pointer without a cast [-Wint-conversion]
    // ==> 메크로 사용해서 LData의 타입을 Point* 으로 변경하여 해결
    LInsert(&list, ptrPos);

    ptrPos = (Point *)malloc(sizeof(Point));
    setPointPos(ptrPos, 2, 2);
    LInsert(&list, ptrPos);

    ptrPos = (Point *)malloc(sizeof(Point));
    setPointPos(ptrPos, 3, 1);
    LInsert(&list, ptrPos);

    ptrPos = (Point *)malloc(sizeof(Point));
    setPointPos(ptrPos, 3, 2);
    LInsert(&list, ptrPos);

    // 저장된 데이터 출력
    printf("현재 데이터의 수: %d\n", LCount(&list));

    if (LFirst(&list, &ptrPos)) {
        ShowPointPos(ptrPos);
        while (LNext(&list, &ptrPos)) {
            ShowPointPos(ptrPos);
        }
    }
    printf("\n");

    // xPos가 2인 모든 데이터 삭제
    compPos.xPos = 2;
    compPos.yPos = 0;

    if (LFirst(&list, &ptrPos)) {
        if (PointComp(ptrPos, &compPos) == 1) {
            ptrPos = LRemove(&list);
            free(ptrPos);
        }

        while (LNext(&list, &ptrPos)) {
            if (PointComp(ptrPos, &compPos) == 1) {
                ptrPos = LRemove(&list);
                free(ptrPos);
            }
        }
    }

   // 저장된 데이터 출력
    printf("현재 데이터의 수: %d\n", LCount(&list));

    if (LFirst(&list, &ptrPos)) {
        ShowPointPos(ptrPos);
        while (LNext(&list, &ptrPos)) {
            ShowPointPos(ptrPos);
        }
    }
    printf("\n");
    return 0;
}