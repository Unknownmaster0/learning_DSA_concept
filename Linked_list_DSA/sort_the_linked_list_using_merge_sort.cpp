#include <iostream>
using namespace std;

// question -> https://www.codingninjas.com/studio/problems/mergesort-linked-list_630514?leftPanelTab=0%3Fsource%3Dyoutube&campaign=YouTube_CodestudioLovebabbar5thfeb

class node
{
public:
    int data;
    node *next;

    node() {}
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// function to return the middle node.
node *getMid(node *head)
{
    node *slow = head;
    node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// function to merge the two sorted linked list.
node *merge(node *left, node *right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    node *ansHead = new node(-1);
    node *ansTail = ansHead;

    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            ansTail->next = left;
            ansTail = left;
            left = left->next;
        }
        else
        {
            ansTail->next = right;
            ansTail = right;
            right = right->next;
        }
    }

    // if the first half have some extra node then second
    while (left != NULL)
    {
        ansTail->next = left;
        ansTail = left;
        left = left->next;
    }

    // if the second half have some extra node then first.
    while (right != NULL)
    {
        ansTail->next = right;
        ansTail = right;
        right = right->next;
    }

    ansHead = ansHead->next;

    return ansHead;
}

// Time complexity of mergeSort -> O(n* log(n)) [where n is the number of nodes.]
// Space Complexity -> O(log N) [ N -> number of nodes.]
node *mergeSort(node *head)
{

    if (head->next == NULL)
        return head;

    // step 1 -> find the mid of the list.
    node *mid = getMid(head);

    // step 2 -> divide the list in two halves.
    node *left = head;
    node *right = mid->next;
    mid->next = NULL;

    // step 3 -> recursively sort the left and right list.
    left = mergeSort(left);
    right = mergeSort(right);

    // step 4 -> finally merge the sorted linked list.
    node *result = merge(left, right);

    return result;
}

int main()
{

    return 0;
}