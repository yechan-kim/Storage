#include <stdio.h>
#include <stdlib.h> // using malloc() function

int *createNewArray(int size) {
	// memory allocated
	int *temp = (int *)malloc(sizeof(int) * size);

	// return allocated pointer
	return temp;
}

int main() {
	int *tempArr;
	int arraySize;
	printf("[In] Input array sizes you want to create");
	scanf("%d", &arraySize);
	tempArr = createNewArray(arraySize);
	/*
		Some commands..
	*/
	// delete when you use all
	free(tempArr);
	return 0;
}