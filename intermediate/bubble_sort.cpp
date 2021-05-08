/*
Bubble sort algorithm
Generates an array with a random numbers in the range of 0 to 100.
Sorts the numbers using bubble sort algorithm.
*/

#include <iostream>
#include <ctime>
using namespace std;

void printNumbers(int numbers[], int lim);
void bubbleSort(int numbers[], int lim);
int getUserInput(void);

int main()
{
    cout << "Bubble sort algorithm \n";
    const int limit = getUserInput();
    int rand_array[limit];

    // Random number generation
    srand((unsigned) time(0)); // Same random numbers are generated without this statement.
    for(int i=0; i<limit; i++)
        rand_array[i] = rand() % 100;
    cout << "Numbers: \n";
    printNumbers(rand_array, limit);

    // Sorting
    bubbleSort(rand_array, limit);

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

void bubbleSort(int numbers[], int lim)
{
    int temp;
    for(int j=0; j<lim; j++)
        for(int k=j+1; k<lim; k++)
            if(numbers[k] < numbers[j])
            {
               temp = numbers[j];
               numbers[j] = numbers[k];
               numbers[k] = temp;
            }
}
