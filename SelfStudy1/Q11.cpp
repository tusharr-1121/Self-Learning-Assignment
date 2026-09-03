#include<iostream>
using namespace std;

class LinkedList;

class Node
{
private:
    int data;
    Node *next;

public:
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    friend class LinkedList;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList(void)
    {
        head = NULL;
    }

    void add_first(int data)
    {
        Node *newNode = new Node(data);

        newNode->next = head;
        head = newNode;
    }

    void add_last(int data)
    {
        Node *newNode = new Node(data);

        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    void display(void)
    {
        if(head == NULL)
        {
            cout<<"Linked List is Empty"<<endl;
            return;
        }

        Node *temp = head;

        while(temp != NULL)
        {
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }

        cout<<"NULL"<<endl;
    }

    ~LinkedList(void)
    {
        Node *temp;

        while(head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int menuList(void)
{
    int choice;

    cout<<"\n";
    cout<<"0. EXIT"<<endl;
    cout<<"1. Add First"<<endl;
    cout<<"2. Add Last"<<endl;
    cout<<"3. Display"<<endl;
    cout<<"Enter Choice : ";
    cin>>choice;

    return choice;
}

int main()
{
    LinkedList list;

    int choice;
    int data;

    while((choice = ::menuList()) != 0)
    {
        switch(choice)
        {
        case 1:
            cout<<"Enter Data : ";
            cin>>data;

            list.add_first(data);
            break;

        case 2:
            cout<<"Enter Data : ";
            cin>>data;

            list.add_last(data);
            break;

        case 3:
            cout<<"\nLinked List : ";
            list.display();
            break;

        default:
            cout<<"Invalid Choice"<<endl;
            break;
        }
    }

    return 0;
}