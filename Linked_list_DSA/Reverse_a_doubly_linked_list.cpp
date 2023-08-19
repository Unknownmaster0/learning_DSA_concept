#include<iostream>
using namespace std;

// created the doubly linked list class.
class Node{
    public:
        int data;
        Node* prev;
        Node* next;
    
    // constructor
    Node(){}
    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insertAtPosition(Node* &head, Node* &tail, int pos, int d){

    if(pos == 1){
        /*
        insertAtHead(head,d);
        return;
        */
       Node* newNode = new Node(d);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        return;
    }

// at random position

    int count = 1;
    Node* temp = head;
    while(count < pos-1){
        temp = temp->next;
        count++;
    }
    Node* newNode = new Node(d);

    if(temp->next == NULL){
        /*
            insertAtTail(tail,d);
            return;
        */

        temp->next = newNode;
        newNode->prev = temp;
        tail = newNode;
        return;
    }

    newNode->next = temp->next;
    (temp->next) -> prev = newNode;

    newNode->prev = temp;
    temp->next = newNode;

}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next; // incrementing the temp
    }
    cout<<endl;
}


void reverse(Node* &head){

    cout<<"IN reverse function "<<endl;
    Node* curr = head;
    Node* temp = NULL;

    // on reversing the doubly linked list we need the one variable which store the value of the prev of each node which is temp here.
    while(curr != NULL){

        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
       
    }
    
    if(temp != NULL){
        head = temp->prev;
    }


}


int main()
{
    Node* head = NULL;
    Node* tail = NULL;
/*
    int num = 1;
    while(num){
        cout<<"enter data ";
        int data;
        cin>>data;

        cout<<"enter position ";
        int pos;
        cin>>pos;

        insertAtPosition(head,tail,pos,data);
        print(head);

        cout<<"1 for continue and 0 to exit -> ";
        cin>>num;
    }
*/

    insertAtPosition(head,tail,1,3);
    insertAtPosition(head,tail,2,2);
    insertAtPosition(head,tail,3,5);
    print(head);

    reverse(head);
    print(head);
    
    return 0;
}