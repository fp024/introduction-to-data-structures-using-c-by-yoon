/**
 * ArrayList.h
 * 
 * 책 80쪽의 명세서 내용 기입, 
 * 저자님 코드 보지말고 실제 구현은 ArrayList.c에 해보는게 낫겠다.
 */

/**
 * 배열기반 리스트
 */
typedef struct _arrayList {
    // TODO

} List;

/**
 * 리스트 요소, 이후 코드를 보니 LData란 구조체는 따로 없는 것 같다. 그냥 int* 쓰신듯...
 */
typedef struct _listData {
    int value;
} LData;

/**
 * 리스트 초기화
 * - 리스트 생성후 제일 먼저 호출 되어야하는 함수
 * @param ptrList   초기화할 리스트의 주소 값을 인자로 전달한다.
 */
void ListInit(List *ptrList);

/**
 * 리스트에 데이터를 저장
 * @param ptrList   데이터를 저장할 리스트 주소값
 * @param ptrData   저장할 데이터의 주소값
 */
void LInsert(List *ptrList, LData *ptrData);

/**
 * 첫번째 데이터를 ptrData가 가리키는 메모리에 저장.
 * @param ptrList   데이터를 저장할 리스트 주소값
 * @param ptrData   저장할 데이터의 주소값
 */
int LFirst(List *ptrList, LData *ptrData);

/**
 * - 참조된 데이터의 다음 데이터가 ptrData가 가리키는 메모리에 저장
 * - 순차적인 참조를 위해 반복 호출이 가능
 * - 참조를 새로 시작하려면 먼저 LFirst 함수를 호출하애함
 * @return 참조성공시 TRUE(1), 실패시 FALSE(0)
 */
int LNext(List *ptrList, LData *ptrData);

/**
 * - LFirst 또는 LNext 함수의 마지막 반환데이터를 삭제
 * - 삭제된 데이터는 반환됨.
 * - 마지막 반환 데이터를 삭제하므로 연이은 반복 호출을 허용하지 않는다.
 * @return 마지막 반환 데이터
 */
LData LRemove(List *ptrList);

/**
 * 리스트에 저장되어있는 데이터 수 반환
 * @param ptrList   데이터의 수를 확인할 리스트
 * @return 데이터의 수
 */
int LCount(List *ptrList);
