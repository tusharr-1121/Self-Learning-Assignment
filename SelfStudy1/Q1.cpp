
#include <stdio.h>
#include <iostream>
using namespace std;

void swapByReference(int &a, int &b)
{
    int tem = a;
    a = b;
    b = tem;
}

void swapByValue(int a, int b)
{
    int tem = a;
    a = b;
    b = tem;
}
int main()
{

    int a;
    int b;

    cout << "Enter The Num1:" << endl;
    cin >> a;
    cout << "Enter The Num2:" << endl;
    cin >> b;
    cout << "Before Swapping using Referenece:" << endl;
    cout << "Num1 :" << a << endl;
    cout << "Num2 :" << b << endl;
    swapByReference(a, b);
    cout << "After Swapping using Referenece:" << endl;
    cout << "Num1 :" << a << endl;
    cout << "Num2 :" << b << endl;

    cout << "Before Swapping using Referenece:" << endl;
    cout << "Num1 :" << a << endl;
    cout << "Num2 :" << b << endl;
    swapByValue(a, b);
    cout << "After Swapping using Referenece:" << endl;
    cout << "Num1 :" << a << endl;
    cout << "Num2 :" << b << endl;

    return 0;
}