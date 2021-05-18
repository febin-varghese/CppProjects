/*
Interpolation search algorithm
Generates an array with a random numbers in the range of 0 to 100.
Sorts the numbers using quick sort algorithm.
Searches for an element using interpolation search algorithm
*/

#include <iostream>
#include <ctime>
#include "user_functions.h"
using namespace std;

int interpolationSearch(int [], int, int, int);

int main()
{
    cout << "Interpolation search algorithm \n";
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
    int index = interpolationSearch(rand_array, element, 0, limit);
    if(index != -1)
        cout << element << " found at index " << index << " of the sorted array.";
    else
        cout << element << " not found in the array.";

    return 0;
}

int interpolationSearch(int sorted_numbers[], int integer, int low, int high)
{
    if(low <= high && sorted_numbers[low] <= integer <= sorted_numbers[high])
    {
        int position;
        position = low + (((double)(high - low) / (sorted_numbers[high] - sorted_numbers[low])) * (integer - sorted_numbers[low]));
        if(sorted_numbers[position] == integer)
            return position;
        if(sorted_numbers[position] < integer)
            return interpolationSearch(sorted_numbers, integer, position + 1, high);
        if(sorted_numbers[position] > integer)
            return interpolationSearch(sorted_numbers, integer, low, position - 1);
    }
    return -1;
}