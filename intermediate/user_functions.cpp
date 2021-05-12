#include "user_functions.h"
#include <iostream>
using namespace std;

int getUserInput(void)
{
    int user_input;
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
