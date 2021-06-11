@echo off

cd point
:: 1. LData 를 Point 타입으로 정의하는 메크로를 전달 (-D _USE_POINT_DATATYPE)
:: 2. build-lib.bat 에 의해 생성된 공유라이브러리 libpointlist.so를 실행파일과 같은 경로에 복사해서 위치시킴
call build-lib.bat
copy libpointlist.so ..
cd ..

C:\MinGW-w64\bin\gcc -g -Wall -D _USE_POINT_DATATYPE -o PointListMain.exe PointListMain.c libpointlist.so