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
Concept -> 1. Making a new Node ( temp ) then mark the next of each node to temp at time of traversing
           2. And when in traversing, you get the node pointing to temp earlier, then it means you visited that node earlier.
           3. Return true. i.e. Node exist in the linked list.
*/

bool DetectLoop(Node *head)
{
    if(head == NULL){
        return false;
    }

    Node *ptr;
    Node *temp = head;
    while (temp->next != ptr)
    {
        Node *forward = temp->next;
        temp->next = ptr;
        temp = forward;

        if (temp == NULL)
        {
            return false;
        }
    }

    return true;
}

int main()
{

    return 0;
}