#include <iostream>
using namespace std;

// This is pivot element question. We are finding the pivot index as well as pivot element in the sort and rotated array.
// The pivot element is the smallest element in the array.

void input_Array(int arr[],int n){
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    return;
}

int find_pivot_element(int arr[], int n, int &index)
{
    int start = 0, end = n - 1, mid, element;

    // Equal to nhi hua b/c equal to dalne se infinite loop ka case baan sakta hai.
    while (start < end)
    {
        mid = start + ((end - start) / 2);

        // This condition get false when the pivot element is the last element of the Array.b/c mid become the last element 
        // then the mid+1 will exceed the size of array.
        // if (arr[mid] < arr[mid + 1] && arr[mid] < arr[mid - 1])
        //     index = mid;
        //     return arr[mid];
        // }

        if (arr[mid] >= arr[0])// check if arr[0] ke jagah arr[start] likha ja sakta hai? // this condition means mid index is on first line,but pivot lies on second line
        {
            start = mid + 1; // so increase the value of start
        }
        else // when the mid index is not on the first line,then it must be on the second line.
        {
            end = mid;
        }
    }

    index = start; // lastly, start = index of pivot element hoo jayega.
    return arr[start];
}

int main()
{
    // earlier array is = {1,2,3,7,9} then it is rotated along 9
    int n;
    cin>>n;
    // int arr[] = {7, 9, 1, 2, 3};
    int arr[n];
    int Array_size = n;
    input_Array(arr,Array_size);
    int Pivot_index = -1; // initially let the pivot_index be -1.
    int element = find_pivot_element(arr, Array_size, Pivot_index);
    cout << "The pivot index is " << Pivot_index << endl;
    cout << "The pivot element is " << element << endl;
    return 0;
}