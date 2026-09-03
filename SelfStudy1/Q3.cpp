
#include <stdio.h>
#include <iostream>
using namespace std;
int acceptRecord()
{

    int choice;
    cout << "Menu" << endl;
    cout << "0.Exit" << endl;
    cout << "1.Enter The No. Of Students" << endl;
    cout << "2.Find Highest Marks Student" << endl;
    cout << "Enter The Choice" << endl;
    cin >> choice;
    return choice;
};

class Student
{

private:
    double marks;
    int roll;

public:
    Student(int roll, int marks) : marks(marks), roll(roll)
    {
    }

    Student() : marks(0), roll(0)
    {
    }
    void acceptStudentRecord()
    {
        cout << "Enter The Roll" << endl;
        cin >> this->roll;
        cout << "Enter The Marks :" << endl;
        cin >> this->marks;
    }
    void printStudent()
    {
        cout << "Roll No : " << this->roll << endl;
        cout << "Marks :" << this->marks << endl;
    }
    double getMarks()
    {
        return this->marks;
    }

    int getRoll()
    {
        return this->roll;
    }
};
class MemoryAllocator
{

public:
    int size;
    Student **student;

    MemoryAllocator(int size) : size(0)
    {
    }

    MemoryAllocator()
    {
    }
    void setSize()
    {
        cout << "Enter the Size" << endl;
        cin >> this->size;
    }

    int getSize()
    {
        return this->size;
    }

    Student **allocation()
    {
        return new Student *[this->size];
    }

    ~MemoryAllocator()
    {
        for (int i = 0; i < this->size; i++)
        {
            delete[] student[i];
            student[i] = NULL;
        }
        delete[] student;
        student = NULL;
    }
};
int main()
{
    int choice;

    MemoryAllocator memory;
    Student std;
    Student **student;
    while ((choice = acceptRecord()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            memory.setSize();
            student = memory.allocation();
            int size = memory.getSize();
            for (int i = 0; i < size; i++)
            {
                std.acceptStudentRecord();
                student[i] = new Student(std.getRoll(), std.getMarks());
            }
            break;
        }

        case 2:
        {
            double max;
            for (int i = 0; i < memory.getSize(); i++)
            {
                if (max < student[i]->getMarks())
                {
                    max = student[i]->getMarks();
                }
            }
            cout << "Max Marks: " << max << endl;
        }

        default:
            break;
        }
    }
    return 0;
}