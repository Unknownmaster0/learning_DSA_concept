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

// Time complexity of this function -> O(n * n) where n is the number of nodes.
Node *RemoveDuplicate(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *curr = head;
    while (curr != NULL)
    {
        Node *prev = curr;
        Node *temp = curr->next;
        while (temp != NULL)
        {
            if (curr->data == temp->data)
            {
                prev->next = temp->next;
                temp->next = NULL;
                delete (temp);
                temp = prev->next;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }

        curr = curr->next;
    }

    return head;
}

int main()
{

    return 0;
}