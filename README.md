##  윤성우의 열혈 자료구조 스터디
* 저자: 윤성우 님

* yes24 도서 판매 링크
	
* http://www.yes24.com/Product/Goods/6214396
	
* 진행방향
  * `윤성우의 열혈 자료구조` 책의 내용을 연습합니다.

  * 코드 편집/컴파일:  윈도우 환경의 MinGW gcc와 Notepad++를 연동해서 사용

  * 디버깅:  필요시 GDB로 시도.

  * 적절한 주제마다 디렉토리별로 소스를 나눕니다.

  * 소스파일 인코딩은 UTF-8을 유지하고, 
    윈도우의 CMD에서 exe 실행파일 실행 확인시에 코드페이지를 65001로 변경해서 확인되도록 합니다.
    실행파일 실행 전에 `chcp 65001` 을 전달하는 실행코드 추가함. (Notepad++의 shortcut.xml)

    ```xml
    <Command name="&#xBE4C;&#xB4DC;&#xB41C; &#xC2E4;&#xD589;&#xD30C;&#xC77C; &#xC2E4;&#xD589;" Ctrl="yes" Alt="yes" Shift="no" Key="48">%ComSpec% /c pushd &quot;$(CURRENT_DIRECTORY)&quot; &amp;&amp; chcp 65001 &amp;&amp; &quot;$(NAME_PART).exe&quot; &amp;&amp; popd &amp; pause</Command>
    ```

* NppExec 설정 

  * C 빌드 - MinGW (명령어 확인)

    ```bash
    NPP_SAVEALL
    SET PATH_0 = $(SYS.PATH)
    SET WIN_BUILD_PATH = G:\WinBuilds
    cd $(CURRENT_DIRECTORY)
    ENV_SET PATH = $(WIN_BUILD_PATH)\bin;$(SYS.PATH)
    INPUTBOX "[MinGW - C (gcc)] 만들어진 컴파일/빌드 명령 문자열을 확인하세요." : gcc.exe -g -D_UNICODE -DUNICODE  -W -Wall -mconsole -lws2_32 -o "$(CURRENT_DIRECTORY)\$(NAME_PART).exe" "$(FULL_CURRENT_PATH)" -lm
    $(INPUT)
    ENV_SET PATH = $(PATH_0)
    UNSET PATH_0
    UNSET WIN_BUILD_PATH
    cd $(NPP_DIRECTORY)
    
    # 라이브러리 설명
    # -lws2_32   // TCP/IP 네트워크 프로그래밍을 위해서...
    #
    # gcc 4.6.1버전으로 업그레이드 후 -mno-cygwin 옵션 제거
    # 
    # 2021-03-28 
    #   오랜만에 다시사용하는데... WinBuilds의 통합 설치프로그램에서 MinGW x64를 설치했고, gcc버전은 4.8.3 이다.
    
    ```

    예전에 라이브러리 명령 실행전에 넣으려고, 위처럼 INPUTBOX를 항상 노출되게 했었는데, 

    자료구조 학습 할 때는, 필요없을 것 같다.  ws2_32도 필요없긴하다.

  * GDB 디버깅

    ```bash
    cd $(CURRENT_DIRECTORY)
    G:\WinBuilds\bin\gdb.exe "$(CURRENT_DIRECTORY)\$(NAME_PART).exe" 
    cd $(NPP_DIRECTORY)
    #
    # GDB 디버깅 실행
    # 
    ```

    list, b, q 등 명령어 기억이 안나는데, 진행보면서 필요시 사용해보자.

    
