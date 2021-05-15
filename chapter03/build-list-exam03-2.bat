@echo off

cd namecard
:: 1. LData를 결정하는 전처리기 메크로 때문에, namecard관련을 먼저 컴파일 해야함.
:: 2. build-lib.bat 에 의해 생성된 공유라이브러리 libnamecard.so를 실행파일과 같은 경로에 복사해서 위치시킴
call build-lib.bat
copy libnamecard.so ..
cd ..

cd arraylist
:: 1. build-lib.bat 에 의해 생성된 공유라이브러리 libarraylist.so를 실행파일과 같은 경로에 복사해서 위치시킴
call build-lib.bat
copy libarraylist.so ..
cd ..

C:\MinGW-w64\bin\gcc -g -Wall -o ListExam03-2.exe ListExam03-2.c libnamecard.so libarraylist.so 
