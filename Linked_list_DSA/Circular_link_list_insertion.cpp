#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node() {}
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        cout << "memory freed for " << this->data << endl;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

void insertAfter(Node *&tail, int element, int d)
{

    Node *newNode = new Node(d);
    // when the list is empty,having no elements.
    if (tail == NULL)
    {
        tail = newNode;
        newNode->next = newNode;
        return;
    }

    Node *temp = tail;
    while (temp->data != element)
    {
        temp = temp->next;
    }

    // we assuming that the element is present in the list.
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(Node *&tail, int val)
{

    if (tail == NULL)
    {
        cout << "not able to delete" << endl;
        return;
    }

    Node *prev = tail;
    Node *curr = prev->next;

    while (curr->data != val)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == prev)
    {
        tail = NULL;
        return;
    }

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}


void print(Node *tail)
{

    Node *temp = tail;
    if (tail == NULL)
    {
        cout << "list is empty" << endl;
    }

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    cout << endl;
}

bool isCircular(Node* head){
    // if the list has no node or the list is null -> then the list is circular;
    if(head == NULL){
        return true;
    }

    Node* temp = head->next;
    while(temp != head){
        temp = temp->next;
        if(temp == NULL){
            return false;
        }
    }

    return true;
}

int main()
{
    Node *tail = NULL;
    insertAfter(tail, 3, 4);
    print(tail);
    insertAfter(tail, 4, 2);
    print(tail);
    insertAfter(tail, 4, 1);
    print(tail);
    insertAfter(tail, 2, 10);
    print(tail);
    deleteNode(tail, 1);
    print(tail);
    if(isCircular(tail)){
        cout<<"linked list is circular."<<endl;
    }
    else{
        cout<<"linked list is not circular."<<endl;
    }

    return 0;
}