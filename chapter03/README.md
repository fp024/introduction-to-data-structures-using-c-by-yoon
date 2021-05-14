# Chapter 03 연결 리스트 (Linked List) 1
* 이번장은 다중 소스파일 빌드가 있다. 필요시 컴파일 명령어를 적어두거나, 별도 전용 빌드 task를 만들어보자!


## 03-1 추상 자료형: Abstract Data Type
* 구체적인 기능의 완성과정은 언급하지 않고, 순수하게 기능이 무엇인지를 나열한 것
* struct-example.c 참조

### 저자님의 학습 방법 순서
1. 리스트 자료구조의 ADT를 정의한다.
2. ADT를 근거로 리스트 자료구조를 활용하는 main함수를 정읳ㄴ다.
3. ADT를 근거로 리스트를 구현한다.

* 자료구조의 내부구현을 알지못해도 제공 인터페이스 함수만으로 사용가능하게 만드는 것이 목표같음...


## 03-2 배열을 이용한 리스트의 구현
* 3장까지는 배열을 이용한 리스트의 구현이므로.. 제목이 연결리스트가 아닌 순차 리스트가 맞긴할 것 같음.

### 리스트
* 데이터를 순서대로 저장
* 데이터 중복저장을 허용

### 리스트의 ADT를 기반으로 정의된 main함수
* 리스트의 ADT는 ArrayList.h 에 정의
* 실제 구현은 ArrayList.c 에 구현
* 사용은 main함수를 정의한 ListMain.c 에서 사용


### 리스트에 구조체 변수 저장하기
* point/Point.h, point/Point.c 참고
* LInsert의 두번째 인자가 LData(int형) 형인데... 구조체 포인터를 주소값을 넣게된듯...  
  32비트 환경이라면 주소값의 바이트가 4바이트이지만, 64비트 환경 컴파일이라면 주소값을 8바이트로 사용함.  
  그래서 형변환 없이 포인터로 integer를 만들어서 문제가 있다고 경고 뜸.  
  `passing argument 2 of 'LInsert' makes integer from pointer without a cast [-Wint-conversion]`  
  => 메크로 사용해서 LData의 타입을 Point* 으로 변경하여 해결!

