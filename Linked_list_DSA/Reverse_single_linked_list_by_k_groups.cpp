/*
question -> https://www.codingninjas.com/studio/problems/reverse-list-in-k-groups_983644?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbar_codestudio_26thjan

concept -> we use the iterative approach to solve this question,
            Step 1 -> ek step ham kr denge and baki ka recursion sambhal lega.
                    So, we use iterative approach to solve the 1st k reverse of the linked list.
            Step 2-> then we call the recursion for the next things
            Step 3 -> finally return the prev;
*/
/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

// there is little change in question -> but other concept are same.

int findLength(Node *head)
{
    int length = 0;
    while (head != NULL)
    {
        head = head->next;
        length++;
    }

    return length;
}

Node *kReverse(Node *head, int k)
{

    int length = findLength(head);
    // base case
    if (length < k)
    {
        return head;
    }

    /*
    if(head == NULL) return head; // lecture question ka base case.
    */

    // step 1 ->
    Node *forward = NULL;
    Node *curr = head;
    Node *prev = NULL;
    int count = 0;
    
    while (curr != NULL && count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;

        count++;
    }

    // step 2 -> calling recursion for the further steps:
    if (forward != NULL)
    {
        head->next = kReverse(forward, k);
    }

    // step 3-> return prev;
    return prev;
}