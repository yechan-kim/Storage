# MergeSort
  > 배열의 수를 정렬하는 알고리즘

## 개념
  * 배열을 반으로 나누어 정렬 후 합쳐서 전체 배열 정렬
  * 나눠진 배열의 길이가 0 또는 1일 경우 정렬되었다고 가정
  * 정렬된 두 배열을 합쳐 정렬된 큰 배열을 생성
## 시간복잡도
  |최선|최악|평균|
  |:-:|:-:|:-:|
  |O(n log n)|O(n log n)|O(n log n)|
## 예시
  ```css
  Origin
  705 232 600 343 29 922 17 420


  Divide 1
  705 232 600 343

  Divide 1-1
  705 232

  Divide 1-1-1
  705
  => Sorted
  Divide 1-1-2
  232
  => Sorted
  Conquer 1-1
  232 705
  => Sorted

  Divide 1-2
  600 343

  Divide 1-2-1
  600
  => Sorted
  Divide 1-2-2
  343
  => Sorted
  Conquer 1-2
  343 600
  => Sorted

  Conquer 1
  232 343 600 705
  => Sorted


  Divide 2
  29 922 17 420

  Divide 2-1
  29 922

  Divide 2-1-1
  29
  => Sorted
  Divide 2-1-2
  922
  => Sorted
  Conquer 2-1
  29 922
  => Sorted

  Divide 2-2
  17 420

  Divide 2-2-1
  17
  => Sorted
  Divide 2-2-2
  420
  => Sorted
  Conquer 2-2
  17 420
  => Sorted

  Conquer 2
  17 29 420 922
  => Sorted


  Conquer
  17 29 232 343 420 600 705 922
  => Sorted
  ```
## 수도코드
  ```
  procedure mergeSort(Array[], start, end):
    if start < end:
      mid := (start + end) / 2
      mergeSort(Array[], start, mid)
      mergeSort(Array[], mid + 1, end)
      add & sort two array
  end procedure
  ```
## 참고
  * 분할정복