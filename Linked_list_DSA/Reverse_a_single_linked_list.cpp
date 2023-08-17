#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    // constructor
    Node(){}
    Node(int d){
        this->data = d;
        this->next = NULL;
    }

    // Destructor
    ~Node(){
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
    }
};

void insert(Node* &head,Node* &tail, int position,int d){

    Node* newNode = new Node(d);

    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    if(position == 1){
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    int count = 1;
    while(count < position-1){
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL){
        temp->next = newNode;
        tail = newNode;
        return;
    }

    // insert at position in between head and tail
    newNode->next = temp->next;
    temp->next = newNode;

}

void reverse_list(Node*& head){

    Node* curr = head;
    Node* prev = NULL;

    while(curr != NULL){
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    head = prev;

}

void print(Node* head){

    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insert(head,tail,1,5);
    print(head);
    insert(head,tail,2,4);
    print(head);
    insert(head,tail,1,6);
    print(head);
    insert(head,tail,4,7);
    print(head);
    insert(head,tail,3,1);
    print(head);
    reverse_list(head);
    print(head);


    return 0;
}