# QuickSort
  > 배열의 수를 정렬하는 알고리즘

## 개념
  * 기준값의 좌우로 배열을 분할
  * 기준값보다 작은 값은 왼쪽, 큰 값은 오른쪽으로 분할
## 시간복잡도
  |최선|최악|평균|
  |:-:|:-:|:-:|
  |O(n log n)|O(n^2)|O(n log n)|

## Plain Quick Sort
### 예시
  ```css
  Original
  776 274 256 634 267 873 895 616 544 75

  1 pass pivot : 776
  274 256 634 267 616 544 75 / 776 / 873 895

  1-1 pass pivot : 274
  256 267 75 / 274 / 634 616 544

  1-1-1 pass pivot : 256
  75 / 256 / 267

  1-1-1 combine
  75 256 267

  1-1-2 pass pivot : 634
  544 616 / 634 /

  1-1-2-1 pass pivot : 544
  / 544 / 616

  1-1-2-1 combine
  544 616

  1-1-2 combine
  544 616 634

  1-1 combine
  75 256 267 274 544 616 634

  1-2 pass pivot : 873
  / 873 / 895

  1-2 combine
  873 895

  1 combine
  75 256 267 274 544 616 634 776 873 895
  ```
### 수도코드
  ```
  procedure plainQuickSort(Array[], start, end):
    left := start, right := end
    pivot := Array[left]
    while a from left to right:
      if Array[a] < pivot: enqueue less queue
      else if Array[a] == pivot: enqueue same queue
      else if Array[a] > pivot: enqueue more queue
    re-copy all queue to Array[]
    left := less queue's length
    right := more queue's length
    right := end - right + 1
    if left unsorted part:
      plainQuickSort(Array[], start, left - 1)
    if right unsorted part:
      plainQuickSort(Array[], right, end)
  end procedure
  ```

## In-Place Quick Sort
### 예시
  ```css
  Original
  222 345 489 683 418 631 999 791 12

  1 pass pivot : 418
  222 345 489 683 418 631 999 791 12    a : 489, b : 12
  222 345 12 683 418 631 999 791 489    changed / a : 683, b : 791
  222 345 12 683 418 631 999 791 489    a : 683, b = 418
  222 345 12 418 683 631 999 791 489    changed / a : 683, b : 418
  end pass / quickSort(222 ~ 12), quickSort(6 ~ 489)

  1-1 pass pivot : 345
  222 345 12    a : 345, b : 12
  222 12 345    changed / a : 345, b : 12
  end pass / quickSort(222 ~ 12), X

  1-1-1 pass pivot : 222
  222 12    a : 222, b : 12
  12 222 changed / a : 222, b : 12
  end pass / X, X

  1-1 combine
  12 222 345

  1-2 pass pivot : 999
  683 631 999 791 489    a : 999, b : 489
  683 631 489 791 999    changed / a : 791, b : 791
  end pass / quickSort(683 ~ 791), X

  1-2-1 pass pivot : 631
  683 631 489 791    a : 683, b : 489
  489 631 683 791    changed / a : 631, b : 683
  end pass / X, quickSort(683 ~ 791)

  1-2-1-2 pass pivot : 683
  683 791    a : 683, b : 683
  end pass / X, X

  1-2-1 combine
  489 631 683 791

  1-2 combine
  489 631 683 791 999

  Final combine
  12 222 345 418 489 631 683 791 999
  ```
### 수도코드
  ```
  procedure quickSort(Array[], start, end):
    left := start, right := end
    pivot := Array[middle]
    while left <= right:
      find not smaller value from left
      find not bigger value from right
      swap two value
      left := currentLeft + 1, right := currentRight - 1
    if left unsorted part:
      quickSort(Array[], start, right)
    if right unsorted part:
      quickSort(Array[], left, end)
  end procedure
  ```

## 참고
  * 분할정복

## 수정일
  > 2020 / 6 / 14