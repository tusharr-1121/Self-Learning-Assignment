
#include <stdio.h>
#include <iostream>
using namespace std;
inline int factorial(int number)
{
    int fact = 1;
    while (number != 1)
    {
        fact = fact * number;
        number--;
    }
    return fact;
}

inline int pow(int base, int index)
{
    int pow = 1;

    for (int i = 1; i <= index; i++)
    {
        pow *= base;
    }
    return pow;
}

int main()
{
    int num;
    cout << "Enter The Number" << endl;
    cin >> num;
    cout << "Factorial is : " << factorial(num) << endl;

    int base;
    int index;
    cout << "Enter The Base :" << endl;
    cin >> base;
    cout << "Enter The Index :" << endl;
    cin >> index;
    cout << "Power : " << pow(base, index) << endl;

    return 0;
}