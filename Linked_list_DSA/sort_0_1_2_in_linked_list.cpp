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

// algorithm 1 -> count the total number of occurrence of the 0,1 and 2 . then store them in the linked list.
/*
Time complexity -> O(n)+ O(n) = O(n) where n is number of nodes in the linked list.
Space complexity -> O(1) constant space.
Here, the data is replacing in the nodes data.
*/

/*
void counting(Node *head,int &zeros, int &ones,int &twos)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
            zeros++;
        else if(temp ->data == 1)
            ones++;
        else if(temp->data == 2)
            twos++;

        temp = temp->next;
    }

}


Node *sorting(Node *head)
{
    int countZero = 0, countOnes = 0, countTwos = 0;
    counting(head,countOnes,countTwos,countZero);
    Node *temp = head;

    while (temp != NULL)
    {
        // inserting zeros
        while (countZero && temp != NULL)
        {
            temp->data = 0;
            temp = temp->next;
            countZero--;
        }
        // inserting ones
        while (countOnes && temp != NULL)
        {
            temp->data = 1;
            temp = temp->next;
            countOnes--;
        }
        // inserting twos
        while (countTwos && temp != NULL)
        {
            temp->data = 2;
            temp = temp->next;
            countTwos--;
        }
    }
    return head;
}
*/

// algorithm 2: Without replacing the data of the nodes.
/*
Time complexity -> O(n) where n is size of the nodes.
Space complexity -> O(1) consant space.

Concept -> Deep concept in the copy.

        We are creating the small separate nodes for 0,1,and 2.
        Dummy node is created with some values.
Importance of the dummy node -> if the dummy nodes are not present there then, we need to apply more the if statements.

        Now after traversing whole linked list and storing the 0s, 1s and 2s in the new linked list.
        Our list becomes like -> ( -1 -> 0 -> 0 -> 1 -> 1 -> 1 -> 2 -> 2 -> NULL );
        -1 is dummy link.
        1 node is also pointed by some dummy link.
        2 node is also pointed by some dummy link.
*/
Node *sorting(Node *head)
{
    Node *ZeroHead = new Node(-1);
    Node *ZeroTail = ZeroHead;
    Node *OneHead = new Node(-1);
    Node *OneTail = OneHead;
    Node *TwoHead = new Node(-1);
    Node *TwoTail = TwoHead;

    Node *curr = head;
    // traversing the whole node and storing the occurrence of 0,1 and 2 in the nodes.
    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            ZeroTail->next = curr;
            ZeroTail = curr;
        }
        else if (curr->data == 1)
        {
            OneTail->next = curr;
            OneTail = curr;
        }
        else if (curr->data == 2)
        {
            TwoTail->next = curr;
            TwoTail = curr;
        }

        curr = curr->next;
    }

    // Now till small list of 0s, 1s and 2s are created then linking them to make the new linked list.
    if (OneHead->next == NULL)
    {
        ZeroTail->next = TwoHead->next;
    }
    else
    {
        ZeroTail->next = OneHead->next;
    }

    OneTail->next = TwoHead->next;
    TwoTail->next = NULL;

    // correcting the dummy nodes
    head = ZeroHead->next;

    delete (ZeroHead);
    delete (OneHead);
    delete (TwoHead);

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

    head = new Node(1);
    tail = head;
    tail->next = new Node(2);
    tail = tail->next;
    tail->next = new Node(0);
    tail = tail->next;
    tail->next = new Node(0);
    tail = tail->next;
    tail->next = new Node(1);
    tail = tail->next;
    print(head);

    head = sorting(head);

    print(head);

    return 0;
}