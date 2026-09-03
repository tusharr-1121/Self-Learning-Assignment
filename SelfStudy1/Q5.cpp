
#include <stdio.h>
#include <iostream>
using namespace std;

class String
{

public:
    static int strLen(string name)
    {
        int length = 0;
        for (int i = 1; i <= name.length(); i++)
        {
            length++;
        }
        return length;
    }

    static string strcpy(string &desitination, string source)
    {
        return desitination = source;
    }
};

int main()
{
    string s;
    cout << "Enter The String" << endl;
    cin >> s;
    cout << "Length :" << String::strLen(s) << endl;
    string destination;
    cout << "Destination:" << String::strcpy(destination, s) << endl;

    return 0;
}