# BogoSort
  > 배열의 수를 정렬하는 알고리즘

## 개념
  * 정렬될때 까지 배열을 섞음
  * 운 좋으면 1번에, 나쁘면 무한히 끝나지 않음
## 시간복잡도
  |최선|최악|평균|
  |:-:|:-:|:-:|
  |O(n)|O(n * n!)|O(∞)|
## 예시
  ```css
  Original
  168 735 79 4 562
  ... after many trials..
  Sorted
  4 79 168 562 735
  ```
## 수도코드
  ```
  procedure bogoSort(Array[]):
    while unSorted:
      randomly shuffle all Array
  end procedure
  ```

## 수정일
  > 2020 / 2 / 25