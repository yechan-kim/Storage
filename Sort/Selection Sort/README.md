# Selection Sort
  > 배열의 수를 정렬하는 알고리즘

## 개념
  * 정렬되지 않은 배열에서 최솟값을 찾음
  * 최솟값을 정렬되지 않은 배열의 가장 앞으로 이동
  * 여러 번 반복하여 배열을 정렬
## 시간복잡도
  |최선|최악|평균|
  |:-:|:-:|:-:|
  |O(n^2) 비교, O(n) 교환|O(n^2) 비교, O(n) 교환|O(n^2) 비교, O(n) 교환|
## 예시
  ```css
  Origin
  168 735 79 4 562

  First compare
  168 735 79 4 562    (current min = 168)
  168 735 79 4 562    (current min = 735)
  168 735 79 4 562    (current min = 79)
  168 735 79 4 562    (current min = 4)
  168 735 79 4 562    (current min = 4)
  First change
  4 735 79 168 562    (minimum value = 4)
  => 4 set

  Second compare
  4 735 79 168 562    (current min = 735)
  4 735 79 168 562    (current min = 79)
  4 735 79 168 562    (current min = 79)
  4 735 79 168 562    (current min = 79)
  Second change
  4 79 735 168 562    (minimum value = 79)
  => 79 set

  Third compare
  4 79 735 168 562    (current min = 735)
  4 79 735 168 562    (current min = 168)
  4 79 735 168 562    (current min = 168)
  Third change
  4 79 168 735 562    (minimum value = 168)
  => 168 set

  Fourth compare
  4 79 168 735 562    (current min = 735)
  4 79 168 735 562    (current min = 562)
  Fourth change
  4 79 168 562 735    (minimum value = 562)
  => 562 set

  Fifth compare
  4 79 168 562 735    (current min = 735)
  Fifth change
  4 79 168 562 735    (minimum value = 735)
  => 735 set
  ```
## 수도코드
  ```
  procedure selectionSort(Array[]):
    for i from 0 to len(Array):
      min := i
      for j from i to len(Array):
        if Array[j] < Array[min]:
          min := j
      swap two value (i, min)
  end procedure
  ```
## 참고
  * 선형탐색