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

// we have given the sorted linked list, we just need to remove the duplicate node from this.

void removeDuplicate(Node *&head)
{

    if (head == NULL)
        return;

    Node *prev = head;
    Node *curr = head->next;

    while (curr != NULL)
    {

        if (prev->data != curr->data)
        {
            prev = curr;
            curr = curr->next;
        }

        else
        {
            prev->next = curr->next;
            curr->next = NULL;
            curr = prev->next;
        }
    }

    return;
}

int main()
{

    return 0;
}