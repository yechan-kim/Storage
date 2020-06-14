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

void plainQuickSort(int left, int right) {
	int less[MAX_INDEX], lessLength = 0;
	int same[MAX_INDEX], sameLength = 0;
	int more[MAX_INDEX], moreLength = 0;
	int pivot = arr[left];
	for (int a = left + 1; a <= right; a++)
		if (arr[a] < pivot)
			less[lessLength++] = arr[a];
		else if (arr[a] == pivot)
			same[sameLength++] = arr[a];
		else
			more[moreLength++] = arr[a];
	int i = left;
	for (int a = 0; a < lessLength; a++, i++)
		arr[i] = less[a];
	arr[i++] = pivot;
	for (int a = 0; a < sameLength; a++, i++)
		arr[i] = same[a];
	for (int a = 0; a < moreLength; a++, i++)
		arr[i] = more[a];
	if (lessLength > 1)
		plainQuickSort(left, left + lessLength - 1);
	if (moreLength > 1)
		plainQuickSort(right - moreLength + 1, right);
	return;
}

void inPlaceQuickSort(int left, int right) {
	int a = left, b = right,
		pivot = arr[(left + right) / 2];
	for (; a <= b;) {
		while (arr[a] < pivot)
			a++;
		while (arr[b] > pivot)
			b--;
		if (a <= b) {
			int temp = arr[a];
			arr[a] = arr[b], arr[b] = temp;
			a++, b--;
		}
	}
	if (left < b)
		inPlaceQuickSort(left, b);
	if (a < right)
		inPlaceQuickSort(a, right);
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
	plainQuickSort(0, MAX_INDEX - 1);
	printArr();

	shuffle();
	printArr();
	inPlaceQuickSort(0, MAX_INDEX - 1);
	printArr();
	return 0;
}