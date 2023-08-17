#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node() {}
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    // making the destructor.
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"memory is freed for "<<value<<endl;
    }
};

void insertAtPosition(Node *&head, Node *&tail, int pos, int d)
{

    Node *temp = head;
    // insetion at start
    if (pos == 1)
    {
        Node *newNode = new Node(d);
        newNode->next = temp;
        head = newNode;
        return;
    }

    int count = 1;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    Node *newNode = new Node(d); // creating the new node.

    if (temp->next == NULL) // it means we are inserting at last position.
        tail = newNode;

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtHead(Node* &head){
    Node* temp = head;
    head = temp->next; // simply just iterate the head to the next location 
    // memory freeing.
    temp->next = NULL;
    delete temp;
}

/* It is nice way -> but we can delete the last and middle element with the same line of statement
prev->next = current->next;

void deleteAtTail(Node* &head, Node* &tail){

    Node* temp = head;
    while(temp->next != tail)   
        temp = temp->next;

    tail = temp;
    temp->next = NULL;

}
*/

/*
 concept -> while deleting the node we should also free the memory it takes, and also free the pointer for whatever address it is locating.
            To free the memory we use destructor.
*/

void deleteAtPosition(Node* &head,Node* &tail, int pos){

    Node* prev = NULL;
    Node* current = head;

    if(pos == 1){ // deletion at first position.
        Node*temp = head;
        head = temp->next;

        temp->next = NULL;
        delete temp;
        return;
    }

    int count = 1;
    while(count < pos ){
        prev = current;
        current = current->next;
        count++;
    }

// We have also manage the tail of the liked list.
    if(current->next == NULL)
        tail = prev;

    prev->next = current->next;

    current->next = NULL;
    delete current;

}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1; // at start head and tail points to the node1 only.

    insertAtPosition(head, tail, 1, 12);
    insertAtPosition(head, tail, 3, 22);
    insertAtPosition(head, tail, 2, 2);
    print(head);
    /*
    deleteAtHead(head);
    print(head);

    deleteAtTail(head,tail);
    print(head);
    */
    // deleteAtPosition(head,tail,1);
    // print(head);
    // deleteAtPosition(head,tail,2);
    // print(head);
    deleteAtPosition(head,tail,4);
    print(head);
    cout<<"head -> "<<head->data<<endl;
    cout<<"tail -> "<<tail->data<<endl;

    return 0;
}