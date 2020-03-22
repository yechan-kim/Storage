# BubbleSort
  > 배열의 수를 정렬하는 알고리즘

## 개념
  * 서로 인접한 2개의 원소를 비교
  * 1번의 순회 이후에는 큰 값부터 배열의 가장 뒤로 이동
## 시간복잡도
  |최선|최악|평균|
  |:-:|:-:|:-:|
  |O(n)|O(n^2)|O(n^2)|
## 예시
  ```css
  Origin
  168 735 79 4 562

  First compare
  168 735 79 4 562    (168, 735)
  168 79 735 4 562    (735, 79)
  168 79 4 735 562    (735, 4)
  168 79 4 562 735    (735, 562)
  => 735 set

  Second compare
  79 168 4 562 735    (168, 79)
  79 4 168 562 735    (168, 4)
  79 4 168 562 735    (168, 562)
  => 562 set

  Third compare
  4 79 168 562 735    (79, 4)
  4 79 168 562 735    (79, 168)
  => 168 set

  Fourth compare
  4 79 168 562 735    (4, 79)
  => 79 set

  Fifth compare
  4 79 168 562 735    (no more compare)
  => 4 set
  ```
## 수도코드
  ```
  procedure bubbleSort(Array[]):
    for i from 1 to len(Array):
      for j from 0 to len(Array) - i:
        if Array[j] > Array[j + 1]:
          swap Two value
  end procedure
  ```