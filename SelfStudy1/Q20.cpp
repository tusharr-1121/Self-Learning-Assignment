#include<iostream>
#include<memory>
using namespace std;

class Student
{
private:
    int rollNo;
    string name;

public:
    Student(int rollNo, string name)
    {
        this->rollNo = rollNo;
        this->name = name;

        cout<<"Student object created"<<endl;
    }

    void display(void)
    {
        cout<<"Roll No : "<<rollNo<<endl;
        cout<<"Name : "<<name<<endl;
    }

    ~Student(void)
    {
        cout<<"Student object destroyed"<<endl;
    }
};

int main()
{
    // ================= UNIQUE POINTER =================

    cout<<"\n========== UNIQUE_PTR =========="<<endl;

    unique_ptr<Student> p1(new Student(101, "Mohit"));

    cout<<"p1 is pointing to:"<<endl;
    p1->display();

    // Ownership is transferred from p1 to p2
    unique_ptr<Student> p2 = move(p1);

    cout<<"\nAfter ownership transfer:"<<endl;

    if(p1 == NULL)
    {
        cout<<"p1 does not own the object"<<endl;
    }

    cout<<"p2 is pointing to:"<<endl;
    p2->display();


    // ================= SHARED POINTER =================

    cout<<"\n========== SHARED_PTR =========="<<endl;

    shared_ptr<Student> s1(new Student(102, "Rahul"));

    cout<<"Reference Count : "<<s1.use_count()<<endl;

    // Shared ownership
    shared_ptr<Student> s2 = s1;

    cout<<"After creating s2:"<<endl;
    cout<<"Reference Count : "<<s1.use_count()<<endl;

    s2->display();


    // ================= WEAK POINTER =================

    cout<<"\n========== WEAK_PTR =========="<<endl;

    weak_ptr<Student> w1 = s1;

    cout<<"Reference Count after weak_ptr : "
        <<s1.use_count()<<endl;

    if(!w1.expired())
    {
        cout<<"weak_ptr is referring to the Student object"<<endl;

        shared_ptr<Student> s3 = w1.lock();

        if(s3 != NULL)
        {
            s3->display();
        }
    }

    cout<<"\nweak_ptr does not increase reference count."<<endl;

    return 0;
}