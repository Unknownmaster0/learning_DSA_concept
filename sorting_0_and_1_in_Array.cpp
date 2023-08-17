#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


/*
    visit this link to see the sorting 0,1,2 in an array using various approach.
    https://www.codingninjas.com/studio/problems/sort-0-1-2_631055?source=youtube&campaign=LoveBabbar_Codestudiovideo1&leftPanelTab=1
*/

void printArray(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return;
}

void sorting(int arr[],int n){
    int left = 0,right = n-1;// left and right are the index of the array leftmost element and array rightmost element.
    while (left < right)
    {
        if(arr[left] == 0){
            left++;
        }
        else if (arr[right] == 1)
        {
            right--;
        }
        else if(arr[left] == 1 && arr[right] == 0){
            swap(arr[left] , arr[right]);
        }
        
    }
    return;
}


int main()
{
    int arr[5] = {1,0,0,1,0};
    sorting(arr,5);
    printArray(arr,5);
    return 0;
}