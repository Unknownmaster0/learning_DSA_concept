#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *bottom;

    Node() {}
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->bottom = NULL;
    }
};

/* question link -> https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1?page=1&category[]=Linked%20List&sprint=94ade6723438d94ecf0c00c3937dad55&sortBy=difficulty */

Node *merge(Node *down, Node *right)
{

    Node *dummyHead = new Node(-1);
    Node *dummyTail = dummyHead;

    while (down != NULL && right != NULL)
    {
        if (down->data < right->data)
        {
            dummyTail->bottom = down;
            dummyTail = down;
            down = down->bottom;
        }
        else
        {
            dummyTail->bottom = right;
            dummyTail = right;
            right = right->bottom;
        }
    }

    if (down != NULL)
        dummyTail->bottom = down;

    else if (right != NULL)
        dummyTail->bottom = right;

    dummyHead = dummyHead->bottom;
    return dummyHead;
}

Node *flatten(Node *root)
{
    // base case for the recursion.
    if (root->next == NULL)
        return root;

    // step 1 -> dividing into two parts

    // 1st part -> down
    Node *down = root;
    // 2nd part -> right
    Node *right = root->next;

    // after pointing to the right part -> make the head ->next to NULL.
    root->next = NULL;

    // step 2 -> recursive call for flatten the right.
    right = flatten(right);

    //   step 3 -> finally merge two flatten sorted list.
    Node *ans = merge(down, right);

    return ans;
}

int main()
{

    return 0;
}