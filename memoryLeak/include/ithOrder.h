/* Created by Tony Schneider on 2/17/2012
 * Last Modified by Tony Schneider on 2/17/2012
 *
 * ithOrder.h
 * Functions to sort a list and find the ithOrder element
 * of a list.
 *
 * Uses the recursive algoritm quickSelect.  
 * 
 */

//Top level call. Some general hackery needs to be done to compensate for
//0-based indexing in C (namely subtracting 1 from the desired ithElem).
int quickSelect(int numList[], int begIndex, int endIndex, int ithElem);

//Used to split the list into two halves about a center pivot
int parition(int numList[], int begIndex, int endIndex);

//Chooses the center pivot used in partition
int choosePivotElem(int numList[], int begIndex, int endIndex);

//Swaps to elements in the passed array
void swap(int numList[], int firstIndex, int secondIndex);

//Finds the median of a list using insertion sort
int findMedian(int array[], int size);

