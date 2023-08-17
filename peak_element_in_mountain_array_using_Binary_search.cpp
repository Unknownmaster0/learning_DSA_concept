#include<iostream>
using namespace std;

int find_peak(int arr[],int n){
    int start = 0,end = n-1,mid;
    while (start <= end)
    {
        mid = start + ((end - start)/2);
        if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1])
            return mid;
        else if(arr[mid] > arr[mid+ 1])
            end = mid;
        else 
            start = mid;

    }

        return -1;
}

int main()
{
    int arr[3] = {0,1,0};
    cout<<"the index of the peak element is : "<<find_peak(arr,3)<<endl;
    return 0;
}