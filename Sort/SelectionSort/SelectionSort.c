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

void selectionSort() {
	for (int i = 0; i < MAX_INDEX; i++) {
		int min = i;
		for (int j = i; j < MAX_INDEX; j++)
			if (arr[j] < arr[min])
				min = j;
		int temp = arr[min];
		arr[min] = arr[i], arr[i] = temp;
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
	selectionSort();
	printArr();
	return 0;
}