#include<stdlib.h>
#include<stdio.h>

#include "stats.h"

/**
 * This function prompts and reads in a collection of numbers
 * from the standard input and populates the given array.  The
 * provided array must be properly initialized for this function
 * to work.
 *
 * //TODO: fix the error in this function
 */
void readInArray(int *arr, int size) {
  int i;
  printf("Enter your list of numbers: ");
  for (i = 0; i < size; i++) {
    scanf("%d", arr[i]);
  }
  return;
}

/**
 * Creates an array of the given size and populates it
 * with random integers between 0 and 99.  This function 
 * assumes that the standard library's random number 
 * generator has already been seeded.
 */
int * createRandomArray(int size) {
  int i;
  int *arr = NULL;
  arr = (int *) malloc(sizeof(int) * size);
  for(i=0; i<size; i++) {
    arr[i] = rand() % 100;
  }
  return arr;
}

/**
 * Prints the given array to the standard output in a 
 * nicely formatted, readable manner.
 */
void printArray(const int *arr, int size) {
  int i;
  printf("[");
  for(i=0; i<size-1; i++) {
	printf("%d, ", arr[i]);
  }
  if(size > 0) {
	printf("%d", arr[size-1]);
  }
  printf("]\n");
}

/**
 * TODO: this function computes the mean (average) of
 * the numbers contained in the given array
 */
double getMean(  ,  ) {

}

/**
 * TODO: this function finds and returns the minimum element
 * of the numbers contained in the given array
 */
int getMin(  ,  ) {
}

/**
 * TODO: this function finds and returns the maximum element
 * of the numbers contained in the given array
 */
int getMax(  , ) {

}
