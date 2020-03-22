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

void flip(int target) {
	int progress = 0, temp;
	while (progress < target - progress)
		temp = arr[progress],
		arr[progress] = arr[target - progress],
		arr[target - progress] = temp,
		progress++;
	return;
}

int maxIndex(int cur) {
	int result = cur;
	for (int i = 0; i < cur; i++)
		if (arr[i] > arr[result])
			result = i;
	return result;
}

void pancakeSort() {
	for (int i = MAX_INDEX - 1; i; i--) {
		int temp = maxIndex(i);
		if (temp != i) {
			flip(temp);
			flip(i);
		}
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
	pancakeSort();
	printArr();
	return 0;
}