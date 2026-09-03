
#include<iostream>
using namespace std;

class Programmer
{
public:
    Programmer(void)
    {
        cout<<"Programmer Constructor"<<endl;
    }
    void work(void)
    {
        cout<<"Programmer is working"<<endl;
    }
};

class Teacher
{
public:
    Teacher(void)
    {
        cout<<"Teacher Constructor"<<endl;
    }

    void work(void)
    {
        cout<<"Teacher is working"<<endl;
    }
};

class ProgrammingTeacher : public Programmer, public Teacher
{
public:
    ProgrammingTeacher(void)
    {
        cout<<"ProgrammingTeacher Constructor"<<endl;
    }
};

int main()
{
    ProgrammingTeacher pt;

    cout<<"\nCalling Programmer work()"<<endl;
    pt.Programmer::work();

    cout<<"\nCalling Teacher work()"<<endl;
    pt.Teacher::work();

    return 0;
}