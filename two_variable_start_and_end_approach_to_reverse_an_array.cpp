#include <iostream>
using namespace std;
// Two variable approach to reverse the elements of the array,
// where start will indicate the first element and increment at every iteration and
// end will indicate the last element and decrement at every iteration.

// Not the recommended approach

int main()
{
    int n, start, end, i = 0;
    cout << "enter the size of array:";
    cin >> n;
    int *arr = new int[n]; // dynamically allocating the array with new keyword

    // input to the array
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << endl;

    // swapping the array
    start = 0;
    end = n - 1;
    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }

    // printing the array after swap
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}