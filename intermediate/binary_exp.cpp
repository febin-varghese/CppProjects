/*
Binary exponentiation algorithm
*/

#include<iostream>
using namespace std;


long int binaryExp(int a, int n)
{
    if (n == 0)
        return 1;
    long int result = binaryExp(a, n / 2);
    if (n % 2)
        return result * result * a;
    else
        return result * result;
}

int main()
{
    int number;
    int power;
    cout << "Enter number: ";
    cin >> number;
    cout << "Enter power: ";
    cin >> power;
    cout << number << "^" << power << " = " << binaryExp(number, power);
    return 0;
}