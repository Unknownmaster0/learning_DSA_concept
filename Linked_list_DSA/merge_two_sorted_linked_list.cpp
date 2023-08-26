#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node() {}
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

/*
Node *merge(Node *head1, Node *head2)
{
    Node *first = head1;
    Node *second = head2;
    Node *dummyHead = new Node(-1);
    Node *dummyTail = dummyHead;
    while (first != NULL && second != NULL)
    {
        if (first->data < second->data) 
        {
            dummyTail->next = first;
            dummyTail = first;
            first = first->next;
        }
        else
        {
            dummyTail->next = second;
            dummyTail = second;
            second = second->next;
        }
    }

    while (first != NULL)
    {
        dummyTail->next = first;
        dummyTail = first;
        first = first->next;
    }

    while (second != NULL)
    {
        dummyTail->next = second;
        dummyTail = second;
        second = second->next;
    }

    // adjusting the head
    Node *head = dummyHead->next;

    // deleting the dummy node
    delete dummyHead;

    return head;
}
*/

/*
Concept ->
             Step 1 -> find the first smallest node among the two
             Step 2 -> make the first list two which the whose first node is small
             Step 3 -> 

*/

Node* merge(Node* first,Node* seocnd)

void print(Node *head)
{
    if (head == NULL)
    {
        cout << "the linked list is empty." << endl;
    }
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{

    Node *head1 = NULL;
    Node *tail1 = NULL;

    head1 = new Node(2);
    tail1 = head1;
    tail1->next = new Node(4);
    tail1 = tail1->next;
    tail1->next = new Node(5);
    tail1 = tail1->next;
    tail1->next = new Node(6);
    tail1 = tail1->next;
    cout << "printing the first linked list." << endl;
    print(head1);

    Node *head2 = NULL;
    Node *tail2 = NULL;

    head2 = new Node(1);
    tail2 = head2;
    tail2->next = new Node(5);
    tail2 = tail2->next;
    tail2->next = new Node(7);
    tail2 = tail2->next;
    cout << "Printing the second linked list." << endl;
    print(head2);

    // now sending the head of two linked list to the merge function
    Node *head = merge(head1, head2);
    print(head);

    return 0;
}