/* Created by Tony Schneider on 2/3/2012
 * Last Modified by Tony Schneider on 2/17/2012
 *
 * ithOrder.c
 * This program finds the ith order statistic of
 * a list of numbers passed on the command line
 * by using the select recursive algorithm.
 *
 * See http://en.wikipedia.org/wiki/Selection_algorithm#Partition-based_general_selection_algorithm
 * for a fairly brief explanation of how the algorithm works. * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ithOrder.h"

     
/*Uses recursion to find the ith highest element in the passed list. */
int quickSelect(int numList[], int begIndex, int endIndex, int ithElem)
{
    //Found the element we're looking for
    if (begIndex == endIndex)
    {
        return numList[ithElem + begIndex];
    }
    
    //Splits list (or sublist) in half at q
    int q = partition(numList, begIndex, endIndex);
    
    //Size of numList[begIndex ... q]
    int k = q - begIndex + 1;

    if (ithElem + 1 == k)
    {
        //Partition happens to be the element we were looking for
        return numList[ithElem + begIndex];
    }
    else if (ithElem + 1 < k)
    {
        //Look in the partition with the ith element (left half)
        return quickSelect(numList, begIndex, q - 1, ithElem);
    }
    else
    {
        //Look in the partition with the ith element (right half)
        return quickSelect(numList, q + 1, endIndex, ithElem - k);
    }
}

/*Partitions the list around a pivot, where everything left of the pivot is smaller*
 *and everything to the right is larger.                                           */
int partition(int numList[], int begIndex, int endIndex)
{
    int pivot = choosePivotElem(numList, begIndex, endIndex);
    swap(numList, pivot, endIndex);

    int i = begIndex - 1;
    int j, temp;

    //Separates list into two halves: smaller than x and larger than x
    for (j = begIndex; j < endIndex; j++)
    {
        if (numList[j] <= numList[endIndex])
        {
            i++;
            swap(numList, i, j);
        }
    }
    
    //Final swap
    swap(numList, i+1, endIndex);

    return i+1;
}

/*Swaps two indices in numList*/
void swap(int numList[], int firstIndex, int secondIndex)
{
    int temp = numList[firstIndex];
    numList[firstIndex] = numList[secondIndex];
    numList[secondIndex] = temp;
}

/*Chooses the pivot element by finding the median of medians (using quickSelect). */
int choosePivotElem(int numList[], int begIndex, int endIndex)
{
    //Find how many groups of 5 the list can be split into
    int numElems = (endIndex - begIndex) + 1;
    int m = floor((double)numElems / 5);
    int numGroups;
    
    //Need m groups if number of elements is evenly divisible by 5
    if ((numElems % 5) == 0)
        numGroups = m;
    else
        numGroups = m+1;

    int numListPrime[numGroups];
    int tempArray[5];
    int i, j;
    
    //Gets median of every five elems in numList
    for (j = 0; j < m; j++)
    {
        for (i = 0; i < 5; i++)
        {
            int index = (j * 5) + i + begIndex;
            tempArray[i] = numList[index];
        }
        
        numListPrime[j] = findMedian(tempArray, 5);
    }

    if ((numElems % 5) != 0)
    {
        for (i = 0; i < (numElems - (m * 5)); i++)
            tempArray[i] = numList[(m*5)+i+begIndex];

        numListPrime[m] = findMedian(tempArray, numElems - (m * 5));
    }

    //Gets the median of numListPrime 
    int newEnd = ceil((double)numElems / 5) - 1;
    int value = quickSelect(numListPrime, 0, newEnd, floor(ceil((double)numElems/5.0) / 2.0));

    //Naively finds index of returned value
    for (i = begIndex; i <= endIndex; i++)
    {
        if (value == numList[i])
            return i;
    }

    //Median of numListPrime wasn't in numList
    fprintf(stderr, "Something went horribly wrong\n");
    exit(-1);
}

int findMedian(int array[], int size)
{
    //Simple bubble sort
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (array[j] > array[i])
            {
                swap(array, i, j);
            }
        }
    }

    //Getting the median is trivial for a sorted list
    int medianIndex = floor(size/2);
    return array[medianIndex];
}

/*Converts list of character representations of ints to integer array*/
void getIntArray(int numElems, char **elems, int destList[])
{
    int i;
    for (i = 0; i < numElems; i++)
    {
        destList[i] = atoi(elems[i]);
    }
}

