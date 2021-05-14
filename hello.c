#include <stdio.h>

int main() {
    int a = 1;
    {
        int a = 2;
        printf("한글: %d\n", a);
    }
    printf("%d\n", a);

    int *intPtr = NULL;
    char *charPtr = NULL;

    // 정수형이나 문자형이나 메모리 주소 크기는 같음
    printf("정수형 주소 바이트수: %I64d\n", sizeof(intPtr));
    printf("문자형 주소 바이트수: %I64d\n", sizeof(charPtr));
    // 64비트 운영체제 환경에서, MinGW-w64의 64비트 빌드를 사용해서,
    // 기본이 64비트 체계로 되는 것 같다.
    //    결과는 8바이트임
    // 그런데 일부러 32bit 로 컴파일하기 위해, -m32를 쓰더라도 오류가난다.
    //    https://stackoverflow.com/questions/19690504/how-do-i-compile-and-link-a-32-bit-windows-executable-using-mingw-w64
    // 내가 SJLJ 배포판을 썼다면 -m32로 그낭 되었을 텐데,
    // SEH 배포판을 사용해서, 필요하다면 32비트 빌드버전 MinGW-w64로 컴파일 해야한다고 함.
	// https://sourceforge.net/projects/mingw-w64/files/mingw-w64/ 에 갔을 때.. 아래와 같이 4가지 종류가 있음.
	// 		i686-posix-sjlj
	// 		i686-posix-dwarf
	//		i686-win32-sjlj
	// 		i686-win32-dwarf

    return 0;
}