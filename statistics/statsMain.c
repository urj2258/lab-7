/**
 * Statistics main driver program
 * Arrays & Dynamic Memory Lab
 * CSCE 155E 
 */
#include<stdlib.h>
#include<stdio.h>

#include "stats.h"

#define MAX_SIZE 100

int main(int argc, char** argv) {
    
    //pay no attention to the man behind the curtain
	srand(time(NULL));
	
    int min, max, size;
    double mean;
    
    printf("Enter the amount of numbers you'd like to find the stats for: ");
    scanf("%d", &size);
	
	if(size > MAX_SIZE) {
	  printf("ERROR: program does not support that many integers!");
	  exit(1);
	}
    
	//TODO: declare a static array "large enough" to hold as many integers as we'll need

	//TODO (Activity 3): change your delcaration and initialization to use
	// a dynamic array and malloc instead
	
	//TODO: pass the appropriate variable
	readInArray(, size);
    
	//TODO: pass the appropriate variables to your functions here
	min = getMin( , );
    max = getMax( , );
    mean = getMean( , );
	printArray( , );
	
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
    printf("Mean: %.2f\n", mean);

    return 0;
}