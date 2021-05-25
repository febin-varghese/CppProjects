/*
Fibonacci search algorithm
Generates an array with a random numbers in the range of 0 to 100.
Sorts the numbers using quick sort algorithm.
Searches for an element using fibonacci search algorithm
*/

#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include "user_functions.h"
using namespace std;

int fibonacciSearch(int [], int, int);

int main()
{
    cout << "Fibonacci search algorithm \n";
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
    int index = fibonacciSearch(rand_array, element, limit);
    if(index != -1)
        cout << element << " found at index " << index << " of the sorted array.";
    else
        cout << element << " not found in the array.";

    return 0;
}

int fibonacciSearch(int sorted_numbers[], int integer, int length)
{
    vector<int> fibonacci_numbers{0, 1};
    int m = 1;
    int k = 1;
    while (m < length)
    {
        m = fibonacci_numbers[k] + fibonacci_numbers[k-1];
        fibonacci_numbers.push_back(m);
        k ++;
    }
    if(m == 0)
        return -1;
    int offset = -1;
    int idx;
    while (m > 1)
    {
        idx = min(offset + fibonacci_numbers[k-2], length-1);
        if(sorted_numbers[idx] == integer)
            return idx;
        else if(integer > sorted_numbers[idx])
        {
            k --;
            m = fibonacci_numbers[k];
            offset = idx;
        }
        else 
        {
            k -= 2;
            m = fibonacci_numbers[k];
        }
    }
    return -1;
}