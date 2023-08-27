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

/*
int getLength(Node *head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

void getStored(int* arr, Node* head)
{
    int i = 0;
    while(head != NULL)
    {
        arr[i] = head -> data;
        head = head -> next;
        i++;
    }

    return ;
}

bool check(int* arr,int n)
{
    int start = 0, end = n-1;
    while( start < end)
    {
        if(arr[start] != arr[end])
            return false;

        start++;
        end--;
    }

    return true;
}

// [ T.C = O(n) && S.C = O(n) ]
bool checkPalindrome(Node *head)
{
    int length = getLength(head);
    // creating the new array of size length
    // You can also create the vector in this place. Then you don't need to get the length of the linked list. 
    int *arr = new int[length];

    // storing the elements of the linked list into array
    getStored(arr,head);

    return check(arr,length);
}
*/

Node* reverse(Node* head)
{
    if(head -> next == NULL || head == NULL )
    {
        return head;
    }
    
    Node* prev = NULL;
    Node* curr = head;
    
    while( curr != NULL ){
        
        Node* forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        
    }
    
    return prev;
}


Node* getMid(Node* head)
{
    Node* fast = head -> next;
    Node* slow = head;
    
    while( fast != NULL && fast -> next != NULL)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    
    return slow;
}

bool checkPalindrome(Node* head, Node* mid)
{
    Node* temp = head;
    Node* middle = mid;
    
    while( middle != NULL )
    {
        if(temp -> data != middle -> data)
        {
            return false;
        }
        temp = temp -> next;
        middle = middle -> next;
    }
    
    return true;
}

//Function to check whether the list is palindrome.[ T.C = O(n) && S.C = O(1) ]
bool isPalindrome(Node *head)
{
    if ( head -> next == NULL )
    {
        return true;
    }
    
    // step 1 -> finding the mid
    Node* middle = getMid(head);
    
    // step 2 -> reversing from the (middle -> next) to last
    Node* temp = middle->next;
    middle -> next = reverse(temp);
    
    // step 3 -> comparing and checking palindrome
    bool ans = checkPalindrome(head , middle -> next);
    
    // step 4 -> reverse the earlier reversed linked list to get the original linked list.
    middle -> next = reverse(temp);
    
    // step 5 -> finally return ans;
    return ans;        
}


void print(Node *head)
{
    if (head == NULL)
    {
        cout << "the linked list is empty." << endl;
    }
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    head = new Node(1);
    tail = head;
    tail->next = new Node(2);
    tail = tail->next;
    tail->next = new Node(1);
    tail = tail->next;
    tail->next = new Node(2);
    tail = tail->next;
    tail->next = new Node(1);
    tail = tail->next;
    print(head);

    if(isPalindrome(head))
    {
        cout<<"the linked list is palindrome."<<endl;
    }
    else{
        cout<<"linked list is not palindrome."<<endl;
    }

    return 0;
}