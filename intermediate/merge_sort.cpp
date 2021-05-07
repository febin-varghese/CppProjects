/*
Merge sort algorithm
Generates an array with a random numbers in the range of 0 to 100.
Sorts the numbers using merge sort algorithm. Bottom-up approach is used
Reference: https://www.interviewbit.com/tutorial/merge-sort-algorithm/
*/

#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

void printNumbers(int numbers[], int lim);
void mergeSort(int numbers[], int lim);
void merge(int numbers[], int start, int mid, int end);

int main()
{
    int limit;
    cout << "Enter the limit: ";
    cin >> limit;
    int rand_array[limit];

    // Random number generation
    srand((unsigned) time(0)); // Same random numbers are generated without this statement.
    for(int i=0; i<limit; i++)
        rand_array[i] = rand() % 100;
    cout << "Numbers: \n";
    printNumbers(rand_array, limit);

    // Sorting
    mergeSort(rand_array, limit);

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

void printNumbers(int numbers[], int lim)
{
    for(int i=0; i<lim; i++)
        cout << numbers[i] << '\t';
    cout << endl;
}

void mergeSort(int numbers[], int lim)
{
    int width = 1;
    while(width < lim)
    {
        for(int i=0; i < lim; i=i+2*width)
        {
            int start, middle, end;
            start = i;
            middle = i + width;
            middle = min(middle, lim);
            end = i + (2 * width);
            end = min(end, lim);
            merge(numbers, start, middle, end);
        }
        width = width * 2;
    }
}

void merge(int numbers[], int start, int mid, int end)
{
    const int array_size = end - start;
    int temp_array[array_size];
    int i = start, j = mid, k = 0;
    
    while(i < mid || j < end)
    {
        if(i < mid && j < end)
        {
            if(numbers[i] < numbers[j])
            {
                temp_array[k] = numbers[i];
                ++k;
                ++i;
            }
            else
            {
                temp_array[k] = numbers[j];
                ++k;
                ++j;
            }

        }
        else if(i == mid)
        {
            temp_array[k] = numbers[j];
            ++k;
            ++j;
        }
        else if (j == end)
        {
            temp_array[k] = numbers[i];
            ++k;
            ++i;
        }
    }

    // copying temporary array to the original array
    for(i=start; i<end; i++)
        numbers[i] = temp_array[i - start];
}