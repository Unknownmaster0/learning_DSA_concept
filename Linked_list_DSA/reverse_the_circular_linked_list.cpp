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

/* Function to delete a given node from the list */
void deleteNode(struct Node **head, int key)
{

    struct Node *prev = *head;
    struct Node *curr = (*head)->next;

    while (curr != *head)
    {
        if (curr->data == key)
        {
            prev->next = curr->next;
            curr = prev->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }

    if (curr->data == key)
    {
        prev->next = curr->next;
        curr = prev->next;
    }

    *head = curr;
}

/* Function to reverse the list */
void reverse(struct Node **head_ref)
{

    struct Node *curr = *head_ref;
    struct Node *prev = NULL;
    struct Node *forward;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    *head_ref = (*head_ref)->next; // or (*head_ref) = prev -> next;

    /* -> Another way to reverse the list.

    // for finding the last node of the linked list.
    while(curr -> next != *head_ref)
    {
        curr = curr -> next;
    }
    // this is the last node of the linked list.
    struct Node* tail = curr;
    curr = *head_ref;

    // A poiter which is pointing to the tail
    struct Node* prev = tail;

    // reversing the list.

    // reversing the first node first.
    struct Node* forward = curr -> next;
    curr -> next = tail;
    prev = curr;
    curr = forward;

    // reversing the left list.
    while(prev != tail)
    {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }

    *head_ref = tail;

    */
}

int main()
{

    return 0;
}