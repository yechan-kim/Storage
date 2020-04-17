#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 10

int main() {
	int mainArraySize = 10;

	// declare static Array
	// can't use main array size
	int array[ARRAY_SIZE];
	int twoDimensionArray[ARRAY_SIZE][ARRAY_SIZE];
	int threeDimensionArray[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE];

	// declare dynamic Array
	// can use main array size
	int* mallocArray = (int *)malloc(sizeof(int) * mainArraySize);

	/*
		After some commands...
	*/

	// must free dynamic Array after use all
	free(mallocArray);
	mallocArray = NULL;

	return 0;
}