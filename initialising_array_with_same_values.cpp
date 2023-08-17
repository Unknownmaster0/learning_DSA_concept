#include<iostream>
using namespace std;

int main()
{
    // int arr[10] = {[0 ... 9] = 1}; // wrong in vs code 
    int a = 1;
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = a;
    }
    for (int i = 0; i < 10; i++)
    {
       cout<<arr[i]<<' ';
    }
    
    return 0;
}