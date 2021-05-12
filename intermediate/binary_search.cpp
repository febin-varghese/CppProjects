/*
Binary search algorithm
Generates an array with a random numbers in the range of 0 to 100.
Sorts the numbers using quick sort algorithm.
Searches for an element using binary search algorithm
*/

#include <iostream>
#include <ctime>
#include "user_functions.h"
using namespace std;

int binarySearch(int [], int, int, int);

int main()
{
    cout << "Binary search algorithm \n";
    cout << "Enter the limit: ";
    const int limit = getUserInput();
    int rand_array[limit];

    // Random number generation
    srand((unsigned)time(0)); // Same random numbers are generated without this statement.
    for (int i = 0; i < limit; i++)
        rand_array[i] = rand() % 100;
    cout << "Numbers: \n";
    printNumbers(rand_array, limit);

    // Sorting
    quickSort(rand_array, 0, limit - 1);
    cout << "Sorted numbers: \n";
    printNumbers(rand_array, limit);

    // Searching
    cout << "Enter the number to search: ";
    int element = getUserInput();
    int index = binarySearch(rand_array, element, 0, limit);
    if(index != -1)
        cout << element << " found at index " << index << " of the sorted array.";
    else
        cout << element << " not found in the array.";

    return 0;
}

int binarySearch(int sorted_numbers[], int integer, int low, int high)
{
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(integer == sorted_numbers[mid])
            return mid;
        else if(integer < sorted_numbers[mid])
            high = mid -1;
        else
            low = mid + 1;    
    }
    return -1;
}