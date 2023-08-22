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


/*
Concept -> If the loop is present in the linked list then remove this from the linked list.
            We just find the find the fist Node of the linked list and then point the next pointer of the previous node
            to the NULL.
*/

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

    // fast is null it means NO loop is present inside the linked list.
    if(fast == NULL) return NULL;

    Node* slow = head;

    while( slow != fast ){
        fast = fast -> next;
        slow = slow -> next;
    }

    return slow;
}

Node* removeLoop(Node* head){

    if(head == NULL) return NULL;

    Node* startNOdeLoop = first_Node(head);

    if(startNOdeLoop == NULL){
        return head;
    }

    Node* temp = startNOdeLoop;
    
    while(temp -> next != startNOdeLoop){

        temp = temp -> next;

    }
    // after coming out of the loop, temp is pointing to the node whose next is pointing to the startNodeLoop
    temp -> next = NULL;

    return head;

}


int main()
{
    
    return 0;
}