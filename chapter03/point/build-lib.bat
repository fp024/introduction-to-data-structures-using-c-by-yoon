@echo off
:: 사용처에서 so파일을 복사해서 가져가도록 한다.
C:\MinGW-w64\bin\gcc -c -g -W -Wall -fPIC -D _USE_POINT_DATATYPE Point.c ..\arraylist\arraylist.c
C:\MinGW-w64\bin\gcc -shared -o libpointlist.so Point.o arraylist.o
