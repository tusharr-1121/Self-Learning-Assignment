#include<iostream>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    Person(void): name(" "), age(0)
    {
    }

    Person(string name, int age): name(name), age(age)
    {
    }

    void setName(string name)
    {
        this->name = name;
    }

    string getName(void)
    {
        return this->name;
    }

    void setAge(int age)
    {
        this->age = age;
    }

    int getAge(void)
    {
        return this->age;
    }

    virtual void display(void)
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
    }

    virtual void work(void) = 0;

    virtual ~Person(void)
    {
    }
};


class Student : public Person
{
private:
    double marks;

public:
    Student(void): Person(), marks(0.0)
    {
    }

    Student(string name, int age, double marks):
        Person(name, age), marks(marks)
    {
    }

    void setMarks(double marks)
    {
        this->marks = marks;
    }

    double getMarks(void)
    {
        return this->marks;
    }

    void acceptRecord(void)
    {
        cout<<"Enter Student Name : ";
        cin>>name;

        cout<<"Enter Student Age : ";
        cin>>age;

        cout<<"Enter Marks : ";
        cin>>marks;
    }

    void display(void)
    {
        Person::display();
        cout<<"Marks : "<<marks<<endl;
    }

    void study(void)
    {
        cout<<name<<" is studying."<<endl;
    }

    void work(void)
    {
        cout<<name<<" is doing student work."<<endl;
    }
};


class Teacher : public Person
{
private:
    double salary;

public:
    Teacher(void): Person(), salary(0.0)
    {
    }

    Teacher(string name, int age, double salary):
        Person(name, age), salary(salary)
    {
    }

    void setSalary(double salary)
    {
        this->salary = salary;
    }

    double getSalary(void)
    {
        return this->salary;
    }

    void acceptRecord(void)
    {
        cout<<"Enter Teacher Name : ";
        cin>>name;

        cout<<"Enter Teacher Age : ";
        cin>>age;

        cout<<"Enter Salary : ";
        cin>>salary;
    }

    void display(void)
    {
        Person::display();
        cout<<"Salary : "<<salary<<endl;
    }

    void teach(void)
    {
        cout<<name<<" is teaching."<<endl;
    }

    void work(void)
    {
        cout<<name<<" is doing teacher work."<<endl;
    }
};


int main()
{
    Student student;
    Teacher teacher;

    cout<<"STUDENT"<<endl;

    student.acceptRecord();
    student.display();
    student.study();

    cout<<" TEACHER "<<endl;

    teacher.acceptRecord();
    teacher.display();
    teacher.teach();

    cout<<" RUNTIME POLYMORPHISM "<<endl;

    Person *person;

    person = &student;
    person->work();

    person = &teacher;
    person->work();

    return 0;
}