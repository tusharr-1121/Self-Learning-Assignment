#include<iostream>
#include<string>
using namespace std;

class NegativeMarksException
{
private:
    string message;

public:
    NegativeMarksException(string message)
    {
        this->message = message;
    }

    string getMessage(void)
    {
        return this->message;
    }
};

class Student
{
private:
    int rollNo;
    string name;
    double marks;

public:
    Student(void): rollNo(0), name(" "), marks(0.0)
    {
    }

    Student(int rollNo, string name, double marks)
        : rollNo(rollNo), name(name), marks(0.0)
    {
        setMarks(marks);
    }

    void setMarks(double marks)
    {
        if(marks < 0)
        {
            throw NegativeMarksException("Marks cannot be negative.");
        }

        this->marks = marks;
    }

    double getMarks(void)
    {
        return this->marks;
    }

    void acceptRecord(void)
    {
        cout<<"Enter Roll No : ";
        cin>>rollNo;

        cout<<"Enter Name : ";
        cin>>name;

        cout<<"Enter Marks : ";
        cin>>marks;

        if(marks < 0)
        {
            throw NegativeMarksException("Marks cannot be negative.");
        }
    }

    void displayRecord(void)
    {
        cout<<"Roll No : "<<rollNo<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Marks : "<<marks<<endl;
    }
};

int main()
{
    Student student;

    try
    {
        student.acceptRecord();

        cout<<"\n========== STUDENT DETAILS =========="<<endl;
        student.displayRecord();
    }
    catch(NegativeMarksException exception)
    {
        cout<<"Exception Caught : "<<exception.getMessage()<<endl;
    }

    return 0;
}