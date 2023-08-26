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
    given two sorted linked list we need to return the new linked list with the elements common in both the
    linked list.
*/

/*
Solution -> step 1 -> make a dummy node with the head and tail.
            step 2 -> traverse both the linked list till head of any one not get to null.
            step 3 -> if the data of any node in both linked list comes equal, then store it in the tail of the new node that you make.
            step 4 -> update the head of both linked list to next iteration and also the tail of new node.
            step 5 -> As after coming from loop, new node head is some dummy node then delete it, and iterate the head to next node.
            step 6 -> check after traversing the loop if the tail of new node is null or not. It must points to null.
            step 7 -> if not then make tail -> next = NULL;
*/

Node *findIntersection(Node *head1, Node *head2)
{
    // step 1 -> make a dummy node with the head and tail.
    Node *head = new Node(-1);
    Node *tail = head;

    // step 2 -> traverse both the linked list till head of any one not get to null.
    while (head1 != NULL && head2 != NULL)
    {
        // step 3 -> if the data of any node in both linked list comes equal,
        //           then store it in the tail of the new node that you make.
        if (head1->data == head2->data)
        {
            tail->next = head1;
            tail = tail->next;
            // step 4 -> update the head of both linked list to next iteration and also the tail of new node.
            head1 = head1->next;
            head2 = head2->next;
        }
        // if not equal then check kiska wala head to iterate krna hai.
        else if (head1->data < head2->data)
        {
            head1 = head1->next;
        }

        else
        {
            head2 = head2->next;
        }
    }
    //  step 5 -> As after coming from loop, new node head is some dummy node then delete it, and iterate the head to next node.
    head = head->next;

    // step 6 -> check after traversing the loop if the tail of new node is null or not. It must points to null.
    // step 7 -> if not then make tail -> next = NULL;
    if (tail->next != NULL)
    {
        tail->next = NULL;
    }

    return head;
}

int main()
{

    return 0;
}