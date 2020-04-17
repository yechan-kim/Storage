# InsertionSort
  > 배열의 수를 정렬하는 알고리즘

## 개념
  * 하나씩 배열에 정렬하여 저장
  * 이미 정렬된 배열에서 순서를 찾은 다음, 배열의 중간에 삽입하며 정렬
## 시간복잡도
  |최선|최악|평균|
  |:-:|:-:|:-:|
  |O(n) 비교, O(1) 교환|O(n^2) 비교, O(n^2) 교환|O(n^2) 비교, O(n^2) 교환|
## 예시
  ```css
  Origin
  168 735 79 4 562

  First insert
  168                 (168)

  Second insert
  168 735             (735)

  Third insert
  79 168 735          (79)

  Fourth insert
  4 79 168 735        (4)

  Fifth insert
  4 79 168 562 735    (562)
  ```
## 수도코드
  ```
  procedure insertionSort(Array[]):
    for i from 1 to len(Array):
      j := i, r = Array[j]
      while r < Array[j]:
        push Array from j to end, 1 right position
        j -= 1
      Array[j] = r
  end procedure
  ```

## 수정일
  > 2020 / 2 / 20