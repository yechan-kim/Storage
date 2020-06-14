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

void duplexSelectionSort(int *arr, int left, int right) {
	int min = 0, max = 0;
	while (left < right) {
		min = left, max = left;
		for (int j = left; j <= right; j++) {
			if (arr[min] > arr[j])
				min = j;
			else if (arr[max] < arr[j])
				max = j;
		}
		int temp = arr[left];
		arr[left] = arr[min], arr[min] = temp;

		if (left == max) // max value was swapped
			max = min;

		temp = arr[right];
		arr[right] = arr[max], arr[max] = temp;
		left++, right--;
	}
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
	duplexSelectionSort(0, MAX_INDEX - 1);
	printArr();
	return 0;
}