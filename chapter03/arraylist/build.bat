@echo off
:: ArrayList.c를 공유라이브러리로 만든 후 빌드
C:\MinGW-w64\bin\gcc -g -W -Wall -shared -o libArrayList.so ArrayList.c
C:\MinGW-w64\bin\gcc -g -Wall -o ListMain.exe ListMain.c libArrayList.so
