/**
 * ArrayList.h
 * 
 * 책 80쪽의 명세서 내용 기입, 
 * 저자님 코드 보지말고 실제 구현은 ArrayList.c에 해보는게 낫겠다.
 * => 그래도 아직은 좀 봐야할 것 같음.
 * => 그런데 일반적인 표준 List와 비교해선 동작이 다르긴한데, 이해를 위해 이렇게 하신것 같다.
 */
#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE 1   // '참'을 표현하기 위한 매크로 정의
#define FALSE 0  // '거짓'을 표현하기 위한 매크로 정의

#define LIST_LEN 100

#ifdef _USE_POINT_DATATYPE
#include "../point/Point.h"
typedef Point* LData;
#elif _USE_NAMECARD_DATATYPE
#include "../namecard/NameCard.h"
typedef NameCard *LData;
#else
typedef int LData;
#endif

/**
 * 배열기반 리스트를 정의한 구조체
 */
typedef struct __ArrayList {
    LData array[LIST_LEN];  // 리스트의 저장소인 고정 배열
    int numOfData;          // 저장된 데이터 수
    int currentPosion;      // 현재 데이터 참조위치
} ArrayList;
typedef ArrayList List;

/**
 * 리스트 초기화
 * - 리스트 생성후 제일 먼저 호출 되어야하는 함수
 * @param ptrList   초기화할 리스트의 주소 값을 인자로 전달한다.
 */
void ListInit(List *ptrList);

/**
 * 리스트에 데이터를 저장
 * @param ptrList   데이터를 저장할 리스트 주소값
 * @param ptrData   저장할 데이터의 값
 */
void LInsert(List *ptrList, LData ptrData);

/**
 * 첫번째 데이터 참조
 * @param ptrList   데이터를 저장할 리스트 주소값
 * @param ptrData   저장할 데이터의 주소값
 */
int LFirst(List *ptrList, LData *ptrData);

/**
 * 두번째 이후 데이터 참조
 * - 참조된 데이터의 다음 데이터가 ptrData가 가리키는 메모리에 저장
 * - 순차적인 참조를 위해 반복 호출이 가능
 * - 참조를 새로 시작하려면 먼저 LFirst 함수를 호출하애함
 * @return 참조성공시 TRUE(1), 실패시 FALSE(0)
 */
int LNext(List *ptrList, LData *ptrData);

/**
 * 참조한 데이터 삭제
 * - 현재 List가 참조하고 있는 데이터 삭제
 * - LFirst 또는 LNext 함수의 마지막 반환데이터를 삭제
 * - 삭제된 데이터는 반환됨.
 * - 마지막 반환 데이터를 삭제하므로 연이은 반복 호출을 허용하지 않는다.
 * @param  ptrList 데이터를 삭제하기 위한 리스트 (현재 리스트가 참조중인 데이터를 삭제)
 * @return 마지막 반환 데이터
 */
LData LRemove(List *ptrList);

/**
 * 리스트에 저장되어있는 데이터 수 반환
 * @param ptrList   데이터의 수를 확인할 리스트
 * @return 데이터의 수
 */
int LCount(List *ptrList);

#endif