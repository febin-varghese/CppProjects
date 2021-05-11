/*
Quick sort algorithm
Generates an array with a random numbers in the range of 0 to 100.
Sorts the numbers using quick sort algorithm.
*/

#include <iostream>
#include <ctime>
using namespace std;

void printNumbers(int numbers[], int lim);
int partition(int numbers[], int low, int high);
void quickSort(int numbers[], int low, int high);
int getUserInput(void);
void swapNumbers(int &, int &);

int main()
{
    cout << "quick sort algorithm \n";
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

int getUserInput(void)
{
    int user_input;
    cout << "Enter the limit: ";
    cin >> user_input;
    return user_input;
}

void printNumbers(int numbers[], int lim)
{
    for (int i = 0; i < lim; i++)
        cout << numbers[i] << '\t';
    cout << endl;
}

void swapNumbers(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

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
