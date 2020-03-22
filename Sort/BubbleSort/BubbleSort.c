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

void bubbleSort() {
	for (int i = 0; i < MAX_INDEX; i++)
		for (int j = 0; j < MAX_INDEX - i - 1; j++)
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1], arr[j + 1] = temp;
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
	bubbleSort();
	printArr();
	return 0;
}