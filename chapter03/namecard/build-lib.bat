@echo off
:: 사용처에서 so파일을 복사해서 가져가도록 한다.
C:\MinGW-w64\bin\gcc -c -g -W -Wall -fPIC NameCard.c
C:\MinGW-w64\bin\gcc -shared -o libnamecard.so NameCard.o
