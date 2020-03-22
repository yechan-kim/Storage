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

void quickSort(int left, int right) {
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
		quickSort(left, b);
	if (a < right)
		quickSort(a, right);
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
	quickSort(0, MAX_INDEX - 1);
	printArr();
	return 0;
}