#include<iostream>
#include<string>
using namespace std;

class BankAccount
{
private:
    int accountNo;
    string name;
    double balance;

public:
    BankAccount(void): accountNo(0), name(" "), balance(0.0)
    {
    }

    BankAccount(int accountNo, string name, double balance)
        : accountNo(accountNo), name(name), balance(balance)
    {
    }

    void deposit(double amount)
    {
        if(amount < 0)
        {
            throw amount;
        }

        balance = balance + amount;

        cout<<"Amount deposited successfully."<<endl;
    }

    void withdraw(double amount)
    {
        if(amount < 0)
        {
            throw amount;
        }

        if(amount > balance)
        {
            throw string("Insufficient Balance");
        }

        balance = balance - amount;

        cout<<"Amount withdrawn successfully."<<endl;
    }

    void display(void)
    {
        cout<<"Account No : "<<accountNo<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Balance : "<<balance<<endl;
    }
};

int main()
{
    BankAccount account(101, "Mohit", 5000);

    double amount;

    account.display();

    cout<<"\nEnter amount to deposit : ";
    cin>>amount;

    try
    {
        account.deposit(amount);
    }
    catch(double amount)
    {
        cout<<"Exception Caught : Negative amount "<<amount
            <<" cannot be deposited."<<endl;
    }
    catch(string message)
    {
        cout<<"Exception Caught : "<<message<<endl;
    }

    cout<<"\nEnter amount to withdraw : ";
    cin>>amount;

    try
    {
        account.withdraw(amount);
    }
    catch(double amount)
    {
        cout<<"Exception Caught : Negative amount "<<amount
            <<" cannot be withdrawn."<<endl;
    }
    catch(string message)
    {
        cout<<"Exception Caught : "<<message<<endl;
    }

    cout<<"\n========== FINAL ACCOUNT DETAILS =========="<<endl;
    account.display();

    return 0;
}