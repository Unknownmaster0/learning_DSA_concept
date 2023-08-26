#include <iostream>
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

void deleteNode(Node *del)
{
    Node *temp = del->next->next;
    del->data = del->next->data;
    del->next = temp;
}

int main()
{

    return 0;
}