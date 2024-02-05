#include <iostream>
using namespace std;

// Problem link -> https://www.geeksforgeeks.org/problems/insertion-sort-for-singly-linked-list/1

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int main()
{

    return 0;
}

Node *insertionSort(struct Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *dummyNode = new Node(0);
    dummyNode->next = head;

    Node *nodetoInsert, *startnode = NULL;

    while (head != NULL && head->next != NULL)
    {
        if (head->data <= head->next->data)
        {
            head = head->next;
        }
        else
        {
            nodetoInsert = head->next;
            startnode = dummyNode;

            while (startnode->next->data < nodetoInsert->data)
            {
                startnode = startnode->next;
            }

            head->next = nodetoInsert->next;
            nodetoInsert->next = startnode->next;
            startnode->next = nodetoInsert;
        }
    }
    return dummyNode->next;
}