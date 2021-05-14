@echo off

cd point
:: 1. LData를 결정하는 전처리기 메크로 때문에, point관련을 먼저 컴파일 해야함.
:: 2. build-lib.bat 에 의해 생성된 공유라이브러리 libpoint.so를 실행파일과 같은 경로에 복사해서 위치시킴
call build-lib.bat
copy libpoint.so ..
cd ..

cd arraylist
:: 1. build-lib.bat 에 의해 생성된 공유라이브러리 libarraylist.so를 실행파일과 같은 경로에 복사해서 위치시킴
call build-lib.bat
copy libarraylist.so ..
cd ..

C:\MinGW-w64\bin\gcc -g -Wall -o PointListMain.exe PointListMain.c libarraylist.so libpoint.so
