#include <iostream>
using namespace std;

// see the more code on code studio   https://bit.ly/3Ioexjh 

// now for total number of occurrence of digit is - (lastIndex-firstIndex)+1;

int firstOccurrence(int arr[], int n, int key)
{
    int start = 0, end = n - 1, mid;
    while (start <= end)
    {
        mid = start + ((end - start) / 2);
        if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else if (arr[start] == key)
        {
            return start;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else if (arr[mid] == key)
        {
            if (arr[mid - 1] == key)
                end = mid;
            else
                return mid;
        }
    }

    return -1;
}

int lastOccurrence(int arr[],int n,int key){

    int start = 0,end = n -1,mid;
    while (start <= end)
    {
        mid = start + ((end - start)/2);

        if(arr[mid] < key)
            start = mid + 1;
        else if(arr[mid] > key){
            end = mid -1;
        }
        else if(arr[end] == key)
            return end;
        else if(arr[mid] == key){
            if(arr[mid+1] > key){
                return mid;
            }
            else
                start = mid;
        }
    }

    return -1;
}

// method 2: of the last occurence function.

// int lastOccurrence(int arr[], int n, int k)
// {
//     int s = 0, e = n - 1, ans = -1;
//     int mid = s + (e - s) / 2;

//     while (s <= e)
//     {
//         if (arr[mid] == k)
//         {
//             ans = mid;
//             s = mid + 1;
//         }
//         else if (arr[mid] < k)
//         {
//             s = mid + 1;
//         }
//         else if (arr[mid] > k)
//         {
//             e = mid - 1;
//         }

//         mid = s + (e - s) / 2;
//     }

//     return ans;
// }

int main()
{
    int arr[8] = {0, 0, 1, 1, 2, 2, 2, 2};
    int key = 2;

    int index = firstOccurrence(arr, 8, key);
    cout << "the first occurence index of the element is : " << index << endl;
    int lastIndex = lastOccurrence(arr, 8, key);
    cout << "the last occurence index of the element is : " << lastIndex << endl;

    return 0;
}