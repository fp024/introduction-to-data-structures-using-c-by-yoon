@echo off
cd arraylist
:: build-lib.bat 에 의해 생성된 공유라이브러리 libarraylist.so를 실행파일과 같은 경로에 복사해서 위치시킴
call build-lib.bat
copy libarraylist.so ..
cd ..
C:\MinGW-w64\bin\gcc -g -Wall -o ListMain.exe ListMain.c libarraylist.so
