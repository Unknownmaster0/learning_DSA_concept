#include <iostream>
using namespace std;

void PrintArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int arr[], int n)
{
    for (int i = 1; i < n; i += 2)
    {
        swap(arr[i], arr[i - 1]);
    }
}

int main()
{
    int arr[] = {2, 3, 4, 5};
    int brr[] = {1, 2, 3, 4, 5};
    swap(arr, 4);
    PrintArray(arr, 4);
    swap(brr, 5);
    PrintArray(brr, 5);
    return 0;
}