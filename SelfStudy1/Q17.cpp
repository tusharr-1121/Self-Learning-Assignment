#include<iostream>
#include<fstream>
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

    void acceptRecord(void)
    {
        cout<<"Enter Roll No : ";
        cin>>rollNo;

        cout<<"Enter Name : ";
        cin>>name;

        cout<<"Enter Marks : ";
        cin>>marks;
    }

    void displayRecord(void)
    {
        cout<<"Roll No : "<<rollNo<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Marks : "<<marks<<endl;
    }

    void saveToFile(void)
    {
        ofstream fout("student.txt");

        fout<<rollNo<<endl;
        fout<<name<<endl;
        fout<<marks<<endl;

        fout.close();
    }

    void loadFromFile(void)
    {
        ifstream fin("student.txt");

        fin>>rollNo;
        fin>>name;
        fin>>marks;

        fin.close();
    }
};

int main()
{
    Student student;

    cout<<"========== ENTER STUDENT DETAILS =========="<<endl;
    student.acceptRecord();

    student.saveToFile();

    cout<<"\nStudent object saved successfully."<<endl;

    Student student2;

    student2.loadFromFile();

    cout<<"\n========== LOADED STUDENT DETAILS =========="<<endl;
    student2.displayRecord();

    return 0;
}