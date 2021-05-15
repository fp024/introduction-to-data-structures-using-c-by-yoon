#define NAME_LEN 30
#define PHONE_LEN 30

#define USE_CUSTOM_DATATYPE

typedef struct __namecard {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
} NameCard;

// 리스트는 NameCard 구조체의 주소값을 다룬다
typedef NameCard *LData;

/**
 * NameCard 구조체 변수의 동적 할당 및 초기화후 주소값 반환
 * @param name  이름
 * @param phone 전화번호
 * @return NameCard 구조체 주소
 */
NameCard *MakeNameCard(char *name, char *phone);

/**
 * NameCard 구조체 변수의 정보출력
 * @param ptrCard   NameCard 구조체 주소
 */
void ShowNameCardInfo(NameCard *ptrCard);

/**
 * NameCard 의 이름 비교
 * @param ptrCard   이름을 확인할 NameCard 구조체 주소
 * @param name      비교할 이름
 * @return 이름이 같으면 0, 다르면 0이 아닌 값을 반환
 */
int NameCompare(NameCard *ptrCard, char *name);

/**
 * 전화번호 정보를 변경
 * @param ptrCard   전화번호를 변경할 NameCard 구조체 주소
 * @param phone     전화번호
 */
void ChangePhoneNum(NameCard *ptrCard, char *phone);