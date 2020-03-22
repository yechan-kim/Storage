#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_INDEX 100
#define MAX_VALUE 100000

int arr[MAX_INDEX];

void printArr() {
	for (int i = 0; i < MAX_INDEX; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return;
}

void mergeSort(int start, int end) {
	int mid = (start + end) / 2;
	if (start < end) {
		mergeSort(start, mid);
		mergeSort(mid + 1, end);
	}
	int *tempArr = (int *)malloc(sizeof(int) * MAX_INDEX),
		tempMid = mid + 1, a = 0;
	for (int i = start; i <= end; i++)
		tempArr[i] = arr[i];
	while (start <= mid && tempMid <= end)
		if (tempArr[start] < tempArr[tempMid])
			arr[start + a] = tempArr[start], start++;
		else
			arr[start + a] = tempArr[tempMid], tempMid++, a++;
	for (; start <= mid; start++)
		arr[start + a] = tempArr[start];
	for (; tempMid <= end; tempMid++)
		arr[start + a++] = tempArr[tempMid];
	free(tempArr);
	return;
}

void shuffle() {
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX_INDEX; i++)
		arr[i] = rand() % MAX_VALUE + 1;
	return;
}

int main() {
	shuffle();
	printArr();
	mergeSort(0, MAX_INDEX - 1);
	printArr();
	return 0;
}