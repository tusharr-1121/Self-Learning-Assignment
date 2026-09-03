#include<iostream>
#include<string>
using namespace std;

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

    void setRollNo(int rollNo)
    {
        if(rollNo < 0)
            throw string("Invalid Roll No");

        this->rollNo = rollNo;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setMarks(double marks)
    {
        if(marks < 0)
            throw string("Marks cannot be negative");

        this->marks = marks;
    }

    void display(void)
    {
        cout<<"Roll No : "<<rollNo<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Marks : "<<marks<<endl;
    }
};

class SmartPointer
{
private:
    Student *ptr;

public:
    SmartPointer(Student *ptr)
    {
        this->ptr = ptr;
    }

    Student* operator->(void)
    {
        return this->ptr;
    }

    ~SmartPointer(void)
    {
        delete ptr;
        cout<<"Student memory released"<<endl;
    }
};

int main()
{
    try
    {
        SmartPointer s(new Student);

        cout<<"Enter Roll No : ";
        int rollNo;
        cin>>rollNo;
        s->setRollNo(rollNo);

        cout<<"Enter Name : ";
        string name;
        cin>>name;
        s->setName(name);

        cout<<"Enter Marks : ";
        double marks;
        cin>>marks;
        s->setMarks(marks);

        cout<<"\n========== STUDENT DETAILS =========="<<endl;
        s->display();
    }
    catch(string message)
    {
        cout<<"Exception Caught : "<<message<<endl;
    }
    catch(...)
    {
        cout<<"Invalid Input"<<endl;
    }

    return 0;
}