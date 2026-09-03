
#include <stdio.h>
#include <iostream>
using namespace std;
class BankAccount
{
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount() : balance(0.0),accountNumber(1),accountHolderName("XYZ")
    {
    }

    void deposite(double amount)
    {
        balance += amount;
    }
    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
        }
        else
        {
            cout << "INSUFFICIENT BALANCE" << endl;
        }
    }

    void display()
    {
        cout << "Current Balance :" << this->balance << endl;
    }
};
int acceptRecord()
{
    int choice;
    cout << "Menu" << endl;
    cout << "1.Deposite" << endl;
    cout << "2.Withdraw" << endl;
    cout << "3.Display" << endl;
    cout << "0.Exit" << endl;
    cout << "Enter The Choice" << endl;
    cin >> choice;
    return choice;
}
int main()
{
    int choice;
    double amount;
    BankAccount B1;

    while ((choice = ::acceptRecord()) != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter The Amount" << endl;
            cin >> amount;
            B1.deposite(amount);
            break;
        case 2:
            cout << "Enter The Amount" << endl;
            cin >> amount;
            B1.withdraw(amount);
            break;
        case 3:
            B1.display();
            break;
        }
    }

    return 0;
}