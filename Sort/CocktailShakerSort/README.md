# CocktailShakerSort
  > 배열의 수를 정렬하는 알고리즘

## 개념
  * 칵테일을 섞듯이 왼쪽 오른쪽을 번갈아가며 정렬
  * 우측 순회하며 최댓값을 정렬, 좌측 순회하며 최솟값을 정렬
## 시간복잡도
  |최선|최악|평균|
  |:-:|:-:|:-:|
  |O(n)|O(n^2)|O(n^2)|
## 예시
  ```css
  Origin
  168 735 79 4 562

  First shake
  126 79 4 562 735 => 735 set
  4 79 126 562 735 => 4 set

  Second shake
  4 79 126 562 735 => 562 set
  4 79 126 562 735 => 79 set

  Third set
  4 79 126 562 735 / only 126 left
  ```
## 수도코드
  ```
  procedure cocktailShakerSort(Array[]):
    for i from 0 to len(Array) / 2:
      func(BubbleSort, straight)
      func(BubbleSort, reverse)
  end procedure
  ```
## 참고
  * 거품정렬