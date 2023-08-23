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


// here we use the two pointer -> prev and curr.
// Time complexity -> O(n) n is the number of nodes
// Space complexity -> O(1) constant space.
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
            Node *deleteNode = curr;
            prev->next = curr->next;
            curr->next = NULL;
            delete (curr);
            curr = prev->next;
        }
    }

    return;
}

// very brutforce approach. No need to delete the element.
// Method 2:
Node* deleteDuplicate(Node* head){

    if(head == NULL) return head;

    Node* curr = head;
    while(curr -> next != NULL){

        if(curr -> data != (curr->next)->data){
            curr = curr->next;
        }
        else{
            curr -> next = (curr->next)->next;
        }

    }

    return head;
}

int main()
{

    return 0;
}