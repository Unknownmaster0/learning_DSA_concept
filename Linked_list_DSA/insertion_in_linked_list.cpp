#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next; // this store the next address of the node.

    // making the constructor for this class.
    Node() {} // default constructor.
    // parametrised constructor.
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// insertion at front fuction of the LL
void insertAtFront(Node *&head, Node *&tail, int d)
{

    // creating the new node with data-> d
    Node *newNode = new Node(d);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head; // newNode->next is pointing to the previous node head address
        head = newNode;       // here the head is pointing to the newNode address
    }
}

void insertAtEnd(Node *&tail, int d)
{

    Node *newNode = new Node(d); // creating a new node.
    tail->next = newNode;
    // newNode->next = NULL; // at the creation of the new node, its next is alredy pointing to the NULL.
    tail = tail->next; // now tail goes to the last node.
}

void insertAtPosition(Node *&head, Node *&tail, int pos, int d)
{
    // pos -> position.
    Node *temp = head;

    if (pos == 1)
    { // if you want to insert at head with this function.
        /*
         insertAtFront(head,d);
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
            newNode->next = temp;
            head = newNode;
        }
        return;
    }

    int i = 1;
    // iterating the temp Node
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    // After coming out the loop the temp is poinitng to the node just before the position where we want to add the element.
    Node *newNode = new Node(d); // creating the node that to be added.

    // this condition is for updating the tail pointer which should always have to point the last element only.
    if (temp->next == NULL)
    { // it means we are inserting element at last node
        tail = newNode;
    }

    newNode->next = temp->next; // i.e. newNode ka next jo hai, wo next position wale element ko point krega jiska address already temp->next me tha.
    temp->next = newNode;       // temp->next ka address update hoga
}

// print function to print the whole link list by traversing the whole linked list
void print(Node *&head)
{
    // we send the refrence because we don't want to create the copy of the linked list
    Node *temp = head; // new object for iterating and preserving the address stored at head
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next; // iterating the temp to point to the next node if not null
    }
    cout << endl;
}

int main()
{
    // creating the new node of the linked list.
    // Node *node1 = new Node(10);

    // now make the head pointing towards the new node -> node1
    // Node *head = node1;
    // Node *tail = node1; // at start the head and tail are at same position.

    // if the list is null in starting.
    Node *head = NULL;
    Node *tail = NULL;
    print(head);

    insertAtFront(head, tail, 12);
    print(head);

    insertAtFront(head, tail, 13);
    print(head);

    insertAtEnd(tail, 15);
    print(head);

    // insertAtEnd(tail, 20);
    // print(head);

    // insertAtEnd(tail, 125);
    // print(head);

    insertAtPosition(head, tail, 4, 9);
    print(head);

    insertAtPosition(head, tail, 1, 11);
    print(head);

    insertAtPosition(head, tail, 3, 99);
    print(head);

    // this is insert at last wala case hai, but in this tail is not updated to the last element if we have not write the
    // if(temp -> next == NULL) condition in function insertAtPosition.
    // insertAtPosition(head,tail, 10, 99);
    // print(head);

    // cout<<"head -> "<<head->data<<endl;
    // cout<<"tail -> "<<tail->data<<endl;

    return 0;
}