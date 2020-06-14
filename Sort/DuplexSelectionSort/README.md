# DuplexSelectionSort
  > 배열의 수를 정렬하는 알고리즘

## 개념
  * 정렬되지 않은 배열에서 최솟값과 최댓값을 찾음
  * 최솟값을 정렬되지 않은 배열의 가장 앞으로 이동
  * 최댓값을 정렬되지 않은 배열의 가장 뒤로 이동
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
  168 735 79 4 562    min = 4, max = 735
  First change
  4 562 79 168 735    
  => 4 set, 735 set

  Second compare
  4 562 79 168 735    min = 79, max = 562
  Second change
  4 79 168 562 735
  => 79 set, 562 set

  Third compare
  4 79 168 562 735    only 1 key left

  Result
  4 79 168 562 735
  ```
## 수도코드
  ```
  procedure selectionSort(Array[], int start, int end):
    for i from start to end:
      min := i
    max := i
      for j from i to len(Array):
        if Array[j] < Array[min]:
          min := j
    else if Array[j] > Array[max]
      max := j
      swap two value (i, min)

    if start == max: // if start key value is max value
      max := min // re-pos

    swap two value (end, max)
    start += 1, end -= 1
  end procedure
  ```
## 참고
  * 선택정렬

## 수정일
  > 2020 / 6 / 14