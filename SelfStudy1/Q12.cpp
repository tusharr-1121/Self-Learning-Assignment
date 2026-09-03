#include<iostream>
using namespace std;

class Product
{
protected:
    string title;
    double price;

public:
    Product(void): title(" "), price(0.0)
    {
    }

    Product(string title, double price): title(title), price(price)
    {
    }

    virtual void accept(void)
    {
        cout<<"Enter Title : ";
        cin>>title;

        cout<<"Enter Price : ";
        cin>>price;
    }

    virtual void display(void)
    {
        cout<<"Title : "<<title<<endl;
        cout<<"Price : "<<price<<endl;
    }

    virtual ~Product(void)
    {
    }
};

class Book : public Product
{
private:
    int pages;

public:
    Book(void): Product(), pages(0)
    {
    }

    Book(string title, double price, int pages)
        : Product(title, price), pages(pages)
    {
    }

    void accept(void)
    {
        Product::accept();

        cout<<"Enter Pages : ";
        cin>>pages;
    }

    void display(void)
    {
        Product::display();

        cout<<"Pages : "<<pages<<endl;
    }

    int getPages(void)
    {
        return this->pages;
    }
};

class Tape : public Product
{
private:
    double playtime;

public:
    Tape(void): Product(), playtime(0.0)
    {
    }

    Tape(string title, double price, double playtime)
        : Product(title, price), playtime(playtime)
    {
    }

    void accept(void)
    {
        Product::accept();

        cout<<"Enter Playtime : ";
        cin>>playtime;
    }

    void display(void)
    {
        Product::display();

        cout<<"Playtime : "<<playtime<<endl;
    }

    double getPlaytime(void)
    {
        return this->playtime;
    }
};

int main()
{
    Product **arr = new Product*[5];

    int choice;

    for(int i = 0; i < 5; i++)
    {
        cout<<"\n1. Book"<<endl;
        cout<<"2. Tape"<<endl;
        cout<<"Enter Choice : ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            arr[i] = new Book();
            arr[i]->accept();
            break;

        case 2:
            arr[i] = new Tape();
            arr[i]->accept();
            break;

        default:
            cout<<"Invalid Choice"<<endl;
            i--;
            break;
        }
    }

    cout<<"\n========== PRODUCT DETAILS =========="<<endl;

    for(int i = 0; i < 5; i++)
    {
        cout<<"\nProduct "<<i + 1<<endl;
        arr[i]->display();
    }

    cout<<"\n========== ONLY PAGES AND PLAYTIME =========="<<endl;

    for(int i = 0; i < 5; i++)
    {
        Book *book = dynamic_cast<Book*>(arr[i]);
        Tape *tape = dynamic_cast<Tape*>(arr[i]);

        if(book != NULL)
        {
            cout<<"Pages : "<<book->getPages()<<endl;
        }

        if(tape != NULL)
        {
            cout<<"Playtime : "<<tape->getPlaytime()<<endl;
        }
    }

    for(int i = 0; i < 5; i++)
    {
        delete arr[i];
    }

    delete[] arr;

    return 0;
}