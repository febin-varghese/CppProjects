/*
Bucket sort algorithm
Generates an array with a random numbers in the range of 0 to 100.
Sorts the numbers using bucket sort algorithm.
*/

#include<algorithm>
#include <ctime>
#include<iostream>
#include<vector>
#include "user_functions.h"


using namespace std;

void bucketSort(int numbers[], int lim);


int main()
{
    cout << "Bucket sort algorithm \n";
    const int limit = getUserInput();
    int rand_array[limit];

    // Random number generation
    srand((unsigned) time(0)); // Same random numbers are generated without this statement.
    for(int i=0; i<limit; i++)
        rand_array[i] = rand() % 100;
    cout << "Numbers: \n";
    printNumbers(rand_array, limit);

    // Sorting
    bucketSort(rand_array, limit);

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

void bucketSort(int numbers[], int lim)
{
    vector<int> buckets[lim];
    for(int idx=0; idx<lim; idx++)
    {
        int b = numbers[idx] / lim;
        buckets[b].push_back(numbers[idx]);
    }
    for(int idx=0; idx<lim; idx++)
        sort(buckets[idx].begin(), buckets[idx].end());

    int idx = 0;    
    for(int j=0; j<lim; j++)
        for(int k=0; k<buckets[j].size(); k++)
            numbers[idx++] = buckets[j][k];
}
