# PancakeSort
  > 배열의 수를 정렬하는 알고리즘

## 개념
  * 쌓여있는 팬케이크를 뒤집어서 정렬
  * 정렬되지 않은 부분에서의 최댓값을 검색
  * 그 위치를 뒤집어 최댓값을 가장 위로 올림
  * 정렬되지 않은 부분 전체를 뒤집어 큰 순으로 정렬
## 시간복잡도
  |1|2|3|
  |:-:|:-:|:-:|
  |2n|2n - 2|2n - 3|
  |n개의 팬케익을 각각 2번 뒤집어야 함|마지막 팬케익은 뒤집지 않아도 정렬이 되어 있음|2번째로 작은 팬케익은 가장 작은 팬케익과 비교하여 1번만 뒤집어도 정렬|
## 예시
  ```css
  Origin
  4 3 2 5 1

  First flip
  flip 4 : 5 2 3 4 1
  flip 5 : 1 4 3 2 5

  Second flip
  flip 2 : 4 1 3 2 5
  flip 4 : 2 3 1 4 5

  Third flip
  flip 2 : 3 2 1 4 5
  flip 3 : 1 2 3 4 5

  Fourth flip
  No flip : flip 2 is not necessary
  ```
## 수도코드
  ```
  procedure pancakeSort(Array[], start, end):
    while unsorted:
      find the biggest value in unsorted array
      flip that position ( move the biggest value to first position )
      flip all array ( the biggest value )
  end procedure
  ```
## 참고
  * 선택 정렬