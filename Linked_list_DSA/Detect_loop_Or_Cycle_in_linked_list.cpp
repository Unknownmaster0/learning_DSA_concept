#include<iostream>
#include<map>
using namespace std;

/*
Concept -> Detecting the cycle or loop in the linked list.
        Method 1 -> use the map for frequency storage of the number.
                    If the number present in the linked list comes twice on traversing the linked list, 
                    then the loop is present.
*/

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
// Method 1 -> using the hash map
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
        temp = temp ->next; // iterating the whole linked list.

    }

    return false;

}
*/

bool DetectLoop (Node* head)
{
    if(head == NULL) return false;
    if( head -> next == NULL ) return false;

    // using the extra pointer approach. 
    Node* extra = new Node(-1);
    Node* temp = head;
        while( temp != NULL )
        {
            if(temp -> next == extra)
            {
                return true;
            }
            
            else{
                Node* forward = temp -> next;
                temp -> next = extra;
                temp = forward;
            }
        }

    return false;
}





int main()
{
    
    return 0;
}