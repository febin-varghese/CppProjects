#include "user_functions.h"


int partition(int numbers[], int low, int high)
{
    int pivot = numbers[high];
    int idx = low - 1;
    for (int j = low; j < high; j++)
    {
        if (numbers[j] < pivot)
        {
            idx++;
            swapNumbers(numbers[idx], numbers[j]);
        }
    }
    swapNumbers(numbers[idx + 1], numbers[high]);
    return idx + 1;
}



void quickSort(int numbers[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(numbers, low, high);
        quickSort(numbers, low, pivot - 1);
        quickSort(numbers, pivot + 1, high);
    }
}
