#include <iostream>
#include <map>
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

    ~Node()
    {
        cout << "memory freed for " << this->data << endl;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

void insertAfter(Node *&tail, int element, int d)
{

    Node *newNode = new Node(d);
    // when the list is empty,having no elements.
    if (tail == NULL)
    {
        tail = newNode;
        newNode->next = newNode;
        return;
    }

    Node *temp = tail;
    while (temp->data != element)
    {
        temp = temp->next;
    }

    // we assuming that the element is present in the list.
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(Node *&tail, int val)
{

    if (tail == NULL)
    {
        cout << "not able to delete" << endl;
        return;
    }

    Node *prev = tail;
    Node *curr = prev->next;

    while (curr->data != val)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == prev)
    {
        tail = NULL;
        return;
    }

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}


void print(Node *tail)
{

    Node *temp = tail;
    if (tail == NULL)
    {
        cout << "list is empty" << endl;
    }

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    cout << endl;
}

/*

bool isCircular(Node* head){
    // if the list has no node or the list is null -> then the list is circular;
    if(head == NULL){
        return true;
    }

    Node* temp = head->next;
    while(temp != head){
        temp = temp->next;
        if(temp == NULL){
            return false;
        }
    }

    return true;
}

*/

/*

// This function is checking whether the loop is present inside your linked list or not.
bool DetectLoop(Node* head){

// when the list is empty then the loop will oviously not there.
    if(head == NULL){
        return false;
    }

    map<Node*, bool>visited;
    Node* temp = head;

    while(temp != NULL){

        if(visited[temp] == true){ // it means the loop is visited earlier, hence the loop is present in the linked list.
            return true;
        }

        visited[temp] = true;
        temp = temp->next; 

    }

    return false;

}

*/

/*

// This function will detect the loop in the list.
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

// This function will give the first Node of the loop in the linked list.
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

*/

bool DetectLoop(Node *head)
{
    if(head == NULL){
        return false;
    }

    Node *ptr;
    Node *temp = head;
    while (temp->next != ptr)
    {
        Node *forward = temp->next;
        temp->next = ptr;
        temp = forward;

        if (temp == NULL)
        {
            return false;
        }
    }

    return true;
}



int main()
{
    Node *tail = NULL;
    insertAfter(tail, 3, 4);
    print(tail);
    insertAfter(tail, 4, 2);
    print(tail);
    insertAfter(tail, 4, 1);
    print(tail);
    insertAfter(tail, 2, 10);
    print(tail);
    deleteNode(tail, 1);
    print(tail);

/*


    // In case of the circular linked list the first node is the first element in the loop
    Node* temp = first_Node(tail);
    cout<<"temp -> "<<temp->data<<endl;

*/

    /*

    if(isCircular(tail)){
        cout<<"linked list is circular."<<endl;
    }
    else{
        cout<<"linked list is not circular."<<endl;
    }

    */


   
    if(DetectLoop(tail)){
        cout<<"Yes, The loop is present."<<endl;
    }
    else{
        cout<<"No, the loop is not present."<<endl;
    }



    return 0;
}