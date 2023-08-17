#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next; // this store the next address of the node.

    // making the constructor for this class.
    Node() {} // default constructor.
    // parametrised constructor.
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

int main()
{

    // one single node is also created in this way, showing for root understanding
    Node *head = new Node();
    head = NULL;
    Node *node1 = new Node(5); // this way we created the object of the class Node dynamically
    head = node1;

    // printing the data of the nodes ->
    cout << head->data << endl;
    cout << head->next << endl;
    cout << node1->data << endl;
    cout << node1->next << endl;

    return 0;
}