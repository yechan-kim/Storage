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

void insertionSort() {
	for (int i = 1; i < MAX_INDEX; i++) {
		int j = i, r = arr[j];
		while (--j >= 0 && r < arr[j])
			arr[j + 1] = arr[j], arr[j] = r;
	}
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
	insertionSort();
	printArr();
	return 0;
}