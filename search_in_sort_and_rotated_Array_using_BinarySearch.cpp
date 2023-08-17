#include <iostream>
using namespace std;

// There is one or two more approach of this question. Try to find that.

// binary search function for searching any element in the array.
int binary_search(int arr[], int start, int end, int key)
{
    int mid;
    while (start <= end)
    {
        mid = start + ((end - start) / 2);

        if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else if (arr[mid] == key)
        {
            return mid;
        }
        else
            start = mid + 1;
    }

    return -1;
}

// find pivot index function
int find_index(int arr[], int n)
{
    cout<<"hello I am find_index function"<<endl;
    int start = 0, end = n - 1, mid;
    while (start < end)
    {
        mid = start + ((end - start)/2);
        if (arr[mid] >= arr[start])
        {
            start = mid + 1;
        }
        else
            end = mid;
    }

    return start;
}

// starting of main function
int main()
{
    int arr[] = {7, 9, 1, 2, 3};
    int arr_size = 5;
    int key = 3;
    int key_index; // the index where key is present in the array.
    int pivot_index = find_index(arr, arr_size);
    cout << pivot_index << endl;
    if (arr[pivot_index] <= key && arr[arr_size - 1] >= key)
    {
        key_index = binary_search(arr, pivot_index, arr_size - 1, key);
    }
    else
        key_index = binary_search(arr, 0, pivot_index - 1, key);

    if (key_index)
    {
        cout << "The index of the key is " << key_index << endl;
    }
    else
        cout << "key is absent in the array." << endl;

    return 0;
}