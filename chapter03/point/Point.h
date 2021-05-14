#ifndef __POINT_H__
#define __POINT_H__

#define USE_CUSTOM_DATATYPE

typedef struct _point {
    int xPos;
    int yPos;
} Point;

// Array에 있는 타입을그대로 쓰면 int가됨 
// 64비트 환경에서 주소값이 8바이트인데, 4바이트 int형에 주소형인 Point * 을 넣으려믄 동작이 있어서,
// 아래와 같이 처리, 컴파일시 Point.h를 먼저 컴파일 해야함.
typedef Point *LData;  

/**
 * Point 변수의 xPos, yPos 값 설정
 */
void setPointPos(Point *ptrPos, int xPos, int yPos);

/**
 * Point 변수의 xPos, yPos 정보 출력
 */
void ShowPointPos(Point *ptrPos);

/**
 * 두 Point 변수의 비교
 */
int PointComp(Point *pos1, Point *pos2);

#endif