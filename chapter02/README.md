# Chapter 02 재 귀 (Recursion)

## 02-1 함수의 재귀적 호출의 이해
* 완료되지 않은 함수를 내부에서 다시 호출

* 재귀 동작
  * 재귀 함수를 실행하는 중간에 다시 재귀함수가 호출되면, 재귀 함수의 복사본을 하나 더 만들어서 복사본을 실행
  * 재귀가 무한 실행되지 않게 하기 위해 탈출 조건이 필요


### 재귀 함수의 디자인 사례
* 팩토리얼 (factorial)
  * `n! = n * (n - 1) * (n - 2) * ... * 2 * 1`
  * `n! = n * (n - 1)!`
  * RecursiveFactorial.c 참고



## 02-2 재귀의 활용
### 피보나치 수열: Fibonacci Sequence
* fib(n) 의 조건
  * `n = 1` 이면 0
  * `n = 2` 이면 1
  * `n` 이면 `fib(n - 1) + fib(n - 2)`
* FibonacciFunc.c 참고


### 이진 탐색 알고리즘의 재귀적 구현
* RecursiveBinarySearch.c 참고
  * 반복문으로 구현한 것에 비하면 성능이 떨어지지만 재귀의 이해를 위해 진행함.



## 02-3 하노이 타워: The Tower of Hanoi
### 일반화
1. 작은 원반 n - 1 개를 A 에서 B로 이동
2. 큰원반 1개를 A에서 C로 이동
3. 작은 원반 n - 1 개를 B에서 C로 이동

* HanoiTower.c 참고
  * 반복적인 부분의 규칙성을 찾는게 가장 중요한 것 같다.
