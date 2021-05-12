/*
Quick sort algorithm
Generates an array with a random numbers in the range of 0 to 100.
Sorts the numbers using quick sort algorithm.
*/

#include <iostream>
#include <ctime>
#include "user_functions.h"
using namespace std;

int partition(int numbers[], int low, int high);

int main()
{
    cout << "quick sort algorithm \n";
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

    // Check
    bool sorted = true;
    for (int i = 0; i < limit - 1; i++)
        if (rand_array[i + 1] < rand_array[i])
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



