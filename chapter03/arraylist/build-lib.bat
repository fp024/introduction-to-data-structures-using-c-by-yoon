@echo off
:: 하위 폴더에다두고 -L.\arraylist -lArrayList 옵션이 먹히질 않음...
:: 사용처에서 so파일을 복사해서 가져가도록 한다.
C:\MinGW-w64\bin\gcc -c -g -fPIC ArrayList.c
C:\MinGW-w64\bin\gcc -shared -o libarraylist.so ArrayList.o
