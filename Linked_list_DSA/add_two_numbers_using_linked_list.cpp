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

Node *reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL)
    {
        Node *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

void insert(Node *&head, Node *&tail, int digit)
{
    // create the new Node for the digit.
    Node *temp = new Node(digit);

    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }

    else
    {
        tail->next = temp;
        tail = temp;
    }
}

Node *add(Node *first, Node *second)
{
    int carry = 0;

    // creating the node to store the ans.
    Node *ansHead = NULL;
    Node *ansTail = ansHead;

    while (first != NULL || second != NULL || carry != 0)
    {

        int value1 = 0, value2 = 0;

        if (first != NULL)
            value1 = first->data;

        if (second != NULL)
            value2 = second->data;

        int sum = value1 + value2 + carry;

        int digit = sum % 10;

        // insert the digit to the ans node which is created.
        insert(ansHead, ansTail, digit);

        carry = sum / 10;

        if (first != NULL)
            first = first->next;

        if (second != NULL)
            second = second->next;
    }

    return ansHead;
}
/*
// another way to write the add function
Node* add(Node* first,Node* second)
{
    int carry = 0;
    Node* ansHead = NULL;
    Node* ansTail = ansHead;

// we go inside till when the first and second both are before NULL.
    while( first != NULL && second != NULL )
    {
        int sum = carry + first->data + second->data;

        int digit = sum % 10;

        // creating Node for the data.
        insert(ansHead,ansTail,digit);

        carry = sum / 10;

        first = first -> next;
        second = second -> next;
    }

    // case when any one of first or second will become NUll and the other not. (means when their nodes number are different)
    while(first != NULL)
    {
        int sum = carry + first->data ;

        int digit = sum % 10;

        // creating Node for the data.
        insert(ansHead,ansTail,digit);

        carry = sum / 10;

        first = first -> next;
    }

    while(second != NULL)
    {
        int sum = carry +  second->data;

        int digit = sum % 10;

        // creating Node for the data.
        insert(ansHead,ansTail,digit);

        carry = sum / 10;

        second = second -> next;
    }

    // case when carry will not become 0, means we will left with carry at last node.
    while(carry != 0)
    {
        int sum = carry +  second->data;

        int digit = sum % 10;

        // creating Node for the data.
        insert(ansHead,ansTail,digit);

        carry = sum / 10;
    }

    return ansHead;
}
*/

// Function to add two numbers represented by linked list.
Node *addTwoLists(Node *first, Node *second)
{
    // step 1 -> reverse both the list
    first = reverse(first);
    second = reverse(second);

    // step 2 -> add both the reversed list.
    Node *ans = add(first, second);

    // step 3 -> reverse the ans linked list.
    ans = reverse(ans);

    return ans;
}

int main()
{

    return 0;
}