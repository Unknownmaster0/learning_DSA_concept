#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node() {}
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory freed for " << val << endl;
    }
};

void insertAtPosition(Node *&head, Node *&tail, int pos, int d)
{

    if (pos == 1)
    {
        /*
        insertAtHead(head,d);
        return;
        */
        Node *newNode = new Node(d);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        return;
    }

    // at random position

    int count = 1;
    Node *temp = head;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    Node *newNode = new Node(d);

    if (temp->next == NULL)
    {
        /*
            insertAtTail(tail,d);
            return;
        */

        temp->next = newNode;
        newNode->prev = temp;
        tail = newNode;
        return;
    }

    newNode->next = temp->next;
    (temp->next)->prev = newNode;

    newNode->prev = temp;
    temp->next = newNode;
}

void deleteAtPosition(Node *&head, Node *&tail, int pos)
{

    Node *temp = head;

    if (pos == 1)
    {
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    Node *previous = NULL;
    int count = 1;
    while (count < pos)
    {
        previous = temp;
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL){
        previous->next = temp->next;
        temp->prev = NULL;
        tail = previous;
        delete temp;
        return;
    }

    previous->next = temp->next;
    temp->prev = NULL;
    temp->next->prev = previous;
    temp->next = NULL;

    delete temp;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtPosition(head, tail, 1, 3);
    print(head);
    insertAtPosition(head, tail, 1, 4);
    print(head);
    insertAtPosition(head, tail, 3, 5);
    print(head);
    insertAtPosition(head, tail, 2, 2);
    print(head);
    deleteAtPosition(head, tail, 4);
    print(head);
    cout<<"head -> "<<head->data<<endl;
    cout<<"tail -> "<<tail->data<<endl;

    return 0;
}