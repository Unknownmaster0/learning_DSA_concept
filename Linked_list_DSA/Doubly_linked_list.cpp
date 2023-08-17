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

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next; // incrementing the temp
    }
    cout<<endl;
}

void insertAtHead(Node* &head,Node* &tail, int d){

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

}

void insertAtTail(Node* &tail,Node*&head,int d){

    Node* newNode = new Node(d);

    if(tail == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

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

int getLength(Node* head){

    int length = 0;
    Node* temp = head;
    while(temp != NULL){
        length ++;
        temp = temp->next;
    }

    return length;
}

int main()
{
    /* when there atleast one node in the list.
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    */

//    when there is no node in the list
    Node* head = NULL;
    Node* tail = NULL;

// so we should update the head and tail 
    insertAtTail(tail,head,50);
    insertAtHead(head,tail,20);
    print(head);
    // insertAtHead(head,30);
    // print(head);
    // insertAtHead(head,40);
    // print(head);

    insertAtPosition(head,tail,3,4);
    print(head);
    insertAtPosition(head,tail,1,14);
    print(head);
    insertAtPosition(head,tail,3,7);
    print(head);

    cout<<"head->data "<<head->data<<endl;
    cout<<"tail->data "<<tail->data<<endl;


    return 0;
}