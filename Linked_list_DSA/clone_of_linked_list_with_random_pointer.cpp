/*
Question -> https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1
*/
#include<iostream>
#include<map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node* arb; // this is the random pointer.

    Node() {}
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insert(Node* &head, Node*& tail, int d)
{
    Node* newNode = new Node(d);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else{
        tail -> next = newNode;
        tail = newNode;
    }
    
    return ;
}

/*
Node* mapping(Node* &originalHead, Node* &cloneHead)
{
    Node* originalNode = originalHead;
    Node* cloneNode = cloneHead;
    
    map<Node*, Node*>mapp;
    
    while(originalNode != NULL)
    {
        mapp[originalNode] = cloneNode;
        originalNode = originalNode -> next;
        cloneNode = cloneNode -> next;
    }
    
    // step 3.
    originalNode = originalHead;
    cloneNode = cloneHead;
    
    while(originalNode != NULL)
    {
        cloneNode -> arb = mapp[originalNode -> arb];
        cloneNode = cloneNode->next;
        originalNode = originalNode->next;
    }
    
    return cloneHead;
}

Node *copyList(Node *head)
{
    
        step 1 -> first crete the clone list of the given liked list with the next pointer and copy the list.
        step 2 -> store the mapping of the original list to the clone list.
        step 3 -> point the random pointer of the clone list using the map and original list.
    
    
    // step 1.
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
    
    Node* temp = head;
    while(temp != NULL)
    {
        insert(cloneHead,cloneTail, temp->data);
        temp = temp -> next;            
    }
    
    // step 2.
    return mapping(head,cloneHead);
    
}
*/





int main()
{
    
    return 0;
}