#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node() {}
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    // Destructor
    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

void insert(Node *&head, Node *&tail, int position, int d)
{

    Node *newNode = new Node(d);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    {
        temp->next = newNode;
        tail = newNode;
        return;
    }

    // insert at position in between head and tail
    newNode->next = temp->next;
    temp->next = newNode;
}

// iteratively
// void reverse_list(Node*& head){

//     // this is the case when our linked list has one or no element.
//     while(head == NULL || head->next == NULL){
//         return; // no need to return anything.
//     }

//     Node* curr = head;
//     Node* prev = NULL;

//     while(curr != NULL){
//         Node* forward = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = forward;
//     }

//     head = prev;

// }

void print(Node *head)
{

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
// recursively
void reverse_recursively(Node *&head, Node *curr, Node *prev)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    if (curr == NULL)
    {
        head = prev;
        return;
    }

    Node *forward = curr->next;

    reverse_recursively(head, forward, curr); // this line explanation in copy
    curr->next = prev;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insert(head, tail, 1, 5);
    print(head);
    insert(head, tail, 2, 4);
    print(head);
    insert(head, tail, 1, 6);
    print(head);
    insert(head, tail, 4, 7);
    print(head);
    insert(head, tail, 3, 1);
    print(head);

    // reverse_list(head);
    Node *prev = NULL;
    Node *curr = head;
    reverse_recursively(head, curr, prev);
    cout << "after recursion " << endl;
    print(head);

    return 0;
}