#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ithOrder.h"

#define SIZE 500000

int* generateArray(int size);

int main(int argc, char** argv)
{

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <number of random lists to generate>\n", argv[0]);
        exit(-1);
    }

    //Initializes random number algorithm with arbitray number
    unsigned int iseed = (unsigned int)time(NULL);
    srand (iseed);
    
    int i;
    for (i = 0; i < atoi(argv[1]); i++)
    {
        //Generates some random array of size SIZE
        int* randArray = generateArray(SIZE);

        //Gets a random ithOrder number between 0 and SIZE -1
        int randNum = rand() % (SIZE - 1);

        //Finds that ithOrder number and prints the results
        int ithOrder = quickSelect(randArray, 0, SIZE-1, randNum);
        printf("The %5dth element of the randomly generated array is %d\n", randNum, ithOrder);
        sleep(2);
    }

    return 0;
}

int* generateArray(int size)
{
    int i;
    int* dynArray = malloc(sizeof(int) * size);

    for (i = 0; i < size; i++)
    {
        dynArray[i] = rand();
    }

    return dynArray;
}
