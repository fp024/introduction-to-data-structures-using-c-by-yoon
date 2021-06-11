@echo off

cd namecard
:: 1. LData 를 NameCard 타입으로 정의하는 메크로를 전달 (-D _USE_NAMECARD_DATATYPE)
:: 2. build-lib.bat 에 의해 생성된 공유라이브러리 libnamecardlist.so를 실행파일과 같은 경로에 복사해서 위치시킴
call build-lib.bat
copy libnamecardlist.so ..
cd ..

C:\MinGW-w64\bin\gcc -g -Wall -D _USE_NAMECARD_DATATYPE -o ListExam03-2.exe ListExam03-2.c libnamecardlist.so 
