
#include <stdio.h>
#include <iostream>

using namespace std;

class Laptop
{
private:
    int brandId;
    double price;

public:
    Laptop() : brandId(1), price(50000)
    {
        cout << "Laptop Constructor Called" << endl;
    }

    ~Laptop()
    {
        cout << "Laptop Destructor Called" << endl;
    }

    void display()
    {
        cout << "BRAND ID :" << this->brandId << endl;
        cout << "PRICE :" << this->price << endl;
    }
};
int main()
{
    Laptop laptop;
    laptop.display();
    return 0;
}