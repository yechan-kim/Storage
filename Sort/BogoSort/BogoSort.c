#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_INDEX 10
#define MAX_VALUE 100000

int arr[MAX_INDEX];

void printArr() {
	for (int i = 0; i < MAX_INDEX; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return;
}

int check() {
	int res = 0;
	for (int i = 0; i < MAX_INDEX - 1; i++)
		res += (arr[i] > arr[i + 1]);
	return res;
}

void bogoSort() {
	int tempArr[2][MAX_INDEX] = { 0 }, a = 0;
	while (a < MAX_INDEX) {
		int temp = rand() % MAX_INDEX;
		if (!tempArr[1][temp]) {
			tempArr[1][temp] = 1,
				tempArr[0][a++] = arr[temp];
		}
	}
	for (int i = 0; i < MAX_INDEX; i++)
		arr[i] = tempArr[0][i];
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
	while (check())
		bogoSort();
	printArr();
	return 0;
}