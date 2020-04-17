#include <stdio.h>
#include <stdlib.h> // using malloc() function

int **createNewArray(int size_x, int size_y) {
	// 2D memory allocated
	int **temp = (int **)malloc(sizeof(int *) * size_y);

	// 1D memory allocated
	for (int i = 0; i < size_y; i++)
		temp[i] = (int *)malloc(sizeof(int) * size_x);

	// return allocated pointer
	return temp;
}

int main() {
	int **tempArr;
	int arraySize_x, arraySize_y;
	printf("[In] Input array sizes you want to create");
	scanf("%d %d", &arraySize_x, &arraySize_y);
	tempArr = createNewArray(arraySize_x, arraySize_y);
	/*
		Some commands..
	*/
	// delete when you use all
	for (int i = 0; i < size_y; i++)
		free(temp[i]);
	free(tempArr);
	
	return 0;
}