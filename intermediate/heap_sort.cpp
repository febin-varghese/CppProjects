/*
Heap sort algorithm
Generates an array with a random numbers in the range of 0 to 100.
Sorts the numbers using heap sort algorithm.
*/

#include <iostream>
#include <ctime>
using namespace std;

void printNumbers(int numbers[], int lim);
void heapify(int numbers[], int lim, int root_idx);
void heapSort(int numbers[], int lim);
int getUserInput(void);
void swapNumbers(int &, int &);

int main()
{
    cout << "heap sort algorithm \n";
    const int limit = getUserInput();
    int rand_array[limit];

    // Random number generation
    srand((unsigned) time(0)); // Same random numbers are generated without this statement.
    for(int i=0; i<limit; i++)
        rand_array[i] = rand() % 100;
    cout << "Numbers: \n";
    printNumbers(rand_array, limit);

    // Sorting
    heapSort(rand_array, limit);

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

int getUserInput(void)
{
    int user_input;
    cout << "Enter the limit: ";
    cin >> user_input;
    return user_input;
}

void printNumbers(int numbers[], int lim)
{
    for(int i=0; i<lim; i++)
        cout << numbers[i] << '\t';
    cout << endl;
}

void swapNumbers(int &a, int&b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void heapify(int numbers [], int lim, int root_idx)
{
    int largest_node_idx = root_idx;
    int lft_idx = 2 * root_idx + 1;
    int rht_idx = 2 * root_idx + 2;
    if(lft_idx < lim && numbers[lft_idx] > numbers[largest_node_idx])
        largest_node_idx = lft_idx;
    if(rht_idx < lim && numbers[rht_idx] > numbers[largest_node_idx])
        largest_node_idx = rht_idx;
    if(largest_node_idx != root_idx)
    {
        swapNumbers(numbers[root_idx], numbers[largest_node_idx]);
        heapify(numbers, lim, largest_node_idx);
    }
}

void heapSort(int numbers[], int lim)
{
    // Build heap
    for(int idx=lim/2-1; idx>=0; idx--)
        heapify(numbers, lim, idx);
    // sort
    for(int idx=lim-1; idx>0; idx--)
    {
        swapNumbers(numbers[idx], numbers[0]);
        heapify(numbers, idx, 0);
    }

}
