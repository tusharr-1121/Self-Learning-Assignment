#include<iostream>
using namespace std;

template <class T>
class Array
{
private:
    int size;
    T *arr;

public:
    Array(void)
    {
        size = 0;
        arr = NULL;
    }

    Array(int size)
    {
        this->size = size;
        arr = new T[size];
    }

    // Copy Constructor
    Array(const Array &a)
    {
        this->size = a.size;
        arr = new T[size];

        for(int i = 0; i < size; i++)
        {
            arr[i] = a.arr[i];
        }
    }

    // Assignment Operator
    Array& operator=(const Array &a)
    {
        if(this != &a)
        {
            delete[] arr;

            this->size = a.size;
            arr = new T[size];

            for(int i = 0; i < size; i++)
            {
                arr[i] = a.arr[i];
            }
        }

        return *this;
    }

    // Subscript Operator
    T& operator[](int index)
    {
        return arr[index];
    }

    int getSize(void)
    {
        return size;
    }

    void acceptRecord(void)
    {
        for(int i = 0; i < size; i++)
        {
            cout<<"Enter Element "<<i + 1<<" : ";
            cin>>arr[i];
        }
    }

    void displayRecord(void)
    {
        for(int i = 0; i < size; i++)
        {
            cout<<arr[i]<<" ";
        }

        cout<<endl;
    }

    ~Array(void)
    {
        delete[] arr;
    }
};

int main()
{
    int size;

    cout<<"Enter Array Size : ";
    cin>>size;

    cout<<"\n========== INTEGER ARRAY =========="<<endl;

    Array<int> a1(size);

    a1.acceptRecord();

    cout<<"Array Elements : ";
    a1.displayRecord();

    cout<<"\nElement at index 2 : ";
    if(size > 2)
        cout<<a1[2]<<endl;

    cout<<"\n========== COPY ARRAY =========="<<endl;

    Array<int> a2 = a1;

    cout<<"Copied Array : ";
    a2.displayRecord();

    cout<<"\n========== ASSIGNMENT OPERATOR =========="<<endl;

    Array<int> a3(size);

    a3 = a1;

    cout<<"Assigned Array : ";
    a3.displayRecord();

    return 0;
}