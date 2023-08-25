#include <iostream>
#include <map>
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

// This function is to remove the duplicate elements from unsorted linked list.

/*
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
*/

Node *RemoveDuplicate(Node *head)
{
    map<int, bool> mp;
    Node *prev = head;
    mp[prev->data] = true;
    Node *temp = head->next;

    while (temp != NULL)
    {
        if (mp[temp->data] == true)
        {
            prev->next = temp->next;
            temp->next = NULL;
            delete (temp);
            temp = prev->next;
        }
        else
        {
            mp[temp->data] = true;
            prev = temp;
            temp = temp->next;
        }
    }

    return head;
}

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
    Node *head = NULL;
    Node *tail = NULL;

    head = new Node(4);
    tail = head;
    tail->next = new Node(5);
    tail = tail->next;
    tail->next = new Node(4);
    tail = tail->next;
    tail->next = new Node(4);
    tail = tail->next;
    tail->next = new Node(5);
    tail = tail->next;
    print(head);

    head = RemoveDuplicate(head);
    cout << "after coming from the remove function." << endl;
    print(head);

    return 0;
}