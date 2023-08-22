#include<iostream>
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

Node* FloydsLoopDetection(Node* head){

    if(head == NULL) return head;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){

        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }

        slow = slow -> next;

        if(fast == slow){ // meet at one node, loop exist.
            return fast;
        }

    }

    return NULL;
}

Node* first_Node(Node* head){

    if(head == NULL) return head;

    Node* fast = FloydsLoopDetection(head);
    Node* slow = head;

    while( slow != fast ){
        fast = fast -> next;
        slow = slow -> next;
    }

    return slow;
}

int main()
{
    
    return 0;
}