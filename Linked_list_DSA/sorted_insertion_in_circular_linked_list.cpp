#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

    void insert(Node*& head, int data){

        // commented line is also correct but looking more lines of code, thus remove this.
 /*       
        Node* prev = NULL;
        Node* curr = head;
        
        prev = curr;
        curr = curr->next;
        
        Node* temp = new Node(data);
        
        while(curr != head && curr->data <= data){
            prev = curr;
            curr = curr->next;
        }
        
        // insert at end
        if(curr == head){
            prev->next = temp;
            temp->next = head;
            return;
        }
        
        // insert at middle.
        prev->next = temp;
        temp->next = curr;
        */
        
        Node* temp = new Node(data);
        Node* curr = head;
        // this will handle the both insert at middle as well as insert at end.
        while(curr->next != head && curr->next->data <= data){
            curr = curr->next;
        }
        
        temp->next = curr->next;
        curr->next = temp;
        
    }
    
    Node *sortedInsert(Node* head, int data)
    {
        Node* temp = new Node(data);
        if(head == NULL){
            temp->next = temp;
            head = temp;
            return head;
        }
        
        // insert at begin
        Node* curr = head;
        if(head->data > data){
            temp->next = head;
        
            while(curr->next != head){
                curr = curr->next;
            }
        
            curr->next = temp;
            head = temp;   
        }
       else 
           insert(head, data);

       return head;
    }

int main()
{

    return 0;
}