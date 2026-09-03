#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

int main()
{
    list<int> numbers;

    // Store 10 random numbers
    numbers.push_back(25);
    numbers.push_back(10);
    numbers.push_back(45);
    numbers.push_back(5);
    numbers.push_back(30);
    numbers.push_back(15);
    numbers.push_back(50);
    numbers.push_back(20);
    numbers.push_back(40);
    numbers.push_back(35);

    cout<<"========== LIST IN REVERSE ORDER =========="<<endl;

    list<int>::reverse_iterator rit;

    for(rit = numbers.rbegin(); rit != numbers.rend(); rit++)
    {
        cout<<*rit<<" ";
    }

    cout<<endl;

    // Increment each number by 5
    list<int>::iterator it;

    for(it = numbers.begin(); it != numbers.end(); it++)
    {
        *it = *it + 5;
    }

    cout<<"\n========== LIST AFTER INCREMENT =========="<<endl;

    // Display using const iterator
    list<int>::const_iterator cit;

    for(cit = numbers.cbegin(); cit != numbers.cend(); cit++)
    {
        cout<<*cit<<" ";
    }

    cout<<endl;

    // Sort the list
    numbers.sort();

    cout<<"\n========== SORTED LIST =========="<<endl;

    for(cit = numbers.cbegin(); cit != numbers.cend(); cit++)
    {
        cout<<*cit<<" ";
    }

    cout<<endl;

    // Display modified list using default iterator
    cout<<"\n========== FINAL MODIFIED LIST =========="<<endl;

    for(it = numbers.begin(); it != numbers.end(); it++)
    {
        cout<<*it<<" ";
    }

    cout<<endl;

    return 0;
}