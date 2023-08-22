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
Floyd's Loop Detection Algorithm -> Time complexity: O(n)- as the loop is traversed once.
                                    Space complexity: O(1) -> constant space.

Concept -> we make the two pointers (i) Fast (ii) Slow
            Fast -> takes two steps in one walk
            Slow -> takes one step in one walk

            When the "Fast" and "Slow" Pointers meets at a node, we say that the loop is present inside our linked list.
*/


bool FloydsLoopDetection(Node* head){

    if(head == NULL) return false;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){

        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }

        slow = slow -> next;

        if(fast == slow){ // meet at one node, loop exist.
            return true;
        }

    }

    return false;

}


int main()
{
    
    return 0;
}