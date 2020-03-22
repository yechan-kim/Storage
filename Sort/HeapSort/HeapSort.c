#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_INDEX 100
#define MAX_VALUE 100000

int arr[MAX_INDEX],
heap[MAX_INDEX + 1], rear;

void printArr() {
	for (int i = 0; i < MAX_INDEX; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return;
}

void push(int value) {
	int tempIndex = ++rear;
	while ((tempIndex != 1) && (value < heap[tempIndex / 2]))
		heap[tempIndex] = heap[tempIndex / 2],
		tempIndex /= 2;
	heap[tempIndex] = value;
	return;
}

int pop() {
	if (!rear) {
		printf("Heap is Empty!");
		return -1;
	}
	else {
		int result = heap[1], a = 1, b = 2;
		heap[1] = heap[rear--];
		while (b <= rear) {
			b += (heap[b] > heap[b + 1]);
			if (heap[a] <= heap[b])
				break;
			else {
				int temp = heap[a];
				heap[a] = heap[b], heap[b] = temp,
					a = b, b *= 2;
			}
		}
		return result;
	}
}

void heapSort() {
	for (int i = 0; i < MAX_INDEX; i++)
		push(arr[i]);
	for (int i = 0; i < MAX_INDEX; i++) {
		int temp = pop();
		if (temp != -1)
			arr[i] = temp;
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
	heapSort();
	printArr();
	return 0;
}