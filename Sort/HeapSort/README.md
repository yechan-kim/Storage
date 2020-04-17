# HeapSort
  > 배열의 수를 정렬하는 알고리즘

## 개념
  * 서로 인접한 2개의 원소를 비교
  * 1번의 순회 이후에는 큰 값부터 배열의 가장 뒤로 이동
## 시간복잡도
  |최선|최악|평균|
  |:-:|:-:|:-:|
  |O(n log n)|O(n log n)|O(n log n)|
## 예시
  ```css
  Origin
  168 735 79 4 562

  First push
  168
  Second push
  168 735
  Third push
  79 735 168
  Fourth push
  4 79 168 735
  Fifth push
  4 79 168 735 562

  First pop
  Arr : 4
  Heap : 79 562 168 735
  Second pop
  Arr : 4 79
  Heap : 168 562 735
  Third pop
  Arr : 4 79 168
  Heap : 562 735
  Fourth pop
  Arr : 4 79 168 562
  Heap : 735
  Fifth pop
  Arr : 4 79 168 562 735
  Heap : 
  ```
## 수도코드
  ```
  procedure heapSort(Array[]):
    push value to end of array
    while not root pos:
      if current value is smaller than parent:
        swap two value
      else:
        break
  end procedure
  ```
## 참고
  * 완전 이진 트리

## 수정일
  > 2020 / 4 / 14