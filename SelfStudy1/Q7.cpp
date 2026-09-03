#include<iostream>
using namespace std;
namespace College
{
  class Student
  {
    private:
    string name;
    int marks;
    int studentId;
    public:
    Student(void): name(" "),marks(0), studentId(0)
    {  }
    Student(string name, int marks, int studentId): name(name), marks(marks), studentId(studentId)
    {  } 
    void setName(string name)
    {
      this->name = name;
    }
    string getName(void)
    {
      return getName();
    }
    void setMarks(int marks)
    {
      this->marks = marks;
    }
    int getMarks(void)
    {
      return getMarks();
    }
    void setStudentId(int studentId)
    {
      this->studentId = studentId;
    }
    int getStudentId(void)
    {
      return getStudentId();
    }
    void display()
    {
      cout<<"Student Name :"<<name<<endl;
      cout<<"Student ID :"<<studentId<<endl;
      cout<<"Marks :"<<marks<<endl;
    }
  };
  class Teacher
  {
    private:
    string name;
    int id;
    string subject;
    public:
    Teacher(void): name(" "),id(0), subject(" ")
    {  }
    Teacher(string name, int id, string subject): name(name), id(id), subject(subject)
    {  } 
    void setName(string name)
    {
      this->name = name;
    }
    string getName(void)
    {
      return getName();
    }
    void setId(int id)
    {
      this->id = id;
    }
    int getId(void)
    {
      return getId();
    }
    void setSubject(string subject)
    {
      this->subject = subject;
    }
    int getSubject(void)
    {
      return getSubject();
    }
    void display()
    {
      cout<<"Teacher Name :"<<name<<endl;
      cout<<"ID :"<<id<<endl;
      cout<<"Subject :"<<subject<<endl;
    }
  };
}
int main()
{
  College :: Student s1;
  s1.setName("rahul");
  s1.setMarks(500);
  s1.setStudentId(12512);
  s1.display();

  College ::Teacher t1;
  t1.setName("rohit");
  t1.setId(024652);
  t1.setSubject("Computer");
  t1.display();
  return 0;
}