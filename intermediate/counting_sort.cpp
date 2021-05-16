/*
Counting sort algorithm
Generates an array with a random numbers in the range of 0 to 100.
Sorts the numbers using counting sort algorithm.
*/

#include <ctime>
#include<iostream>
#include "user_functions.h"


using namespace std;

void countingSort(int numbers[], int lim);


int main()
{
    cout << "counting sort algorithm \n";
    cout << "Enter limit\n";
    const int limit = getUserInput();
    int rand_array[limit];

    // Random number generation
    srand((unsigned) time(0)); // Same random numbers are generated without this statement.
    for(int i=0; i<limit; i++)
        rand_array[i] = rand() % 100;
    cout << "Numbers: \n";
    printNumbers(rand_array, limit);

    // Sorting
    countingSort(rand_array, limit);

    // Check
    bool sorted = true;
    for(int i=0; i< limit-1; i++)
        if(rand_array[i+1] < rand_array[i])
        {
            sorted = false;
            break;
        }
    if (sorted)
    {
        cout << "Numbers are sorted.\n";
        cout << "Sorted numbers: \n";
        printNumbers(rand_array, limit);
    }
    else
    {
        cout << "Numbers are not sorted.\n";
    }
    return 0;
}

void countingSort(int numbers[], int lim)
{
    int maxSize = 100;
    int countingArray[maxSize] = {0};
    for(int idx=0; idx<lim; idx++)
        countingArray[numbers[idx]] += 1;
    for(int idx=1; idx<maxSize; idx++)
        countingArray[idx] += countingArray[idx-1];
    int sortedArray[lim];
    for(int idx=0; idx<lim; idx++)
    {
        int outIndex = --countingArray[numbers[idx]];
        sortedArray[outIndex] = numbers[idx];
    }
    for(int idx=0; idx<lim; idx++)
        numbers[idx] = sortedArray[idx];
}
