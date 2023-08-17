#include<iostream>
using namespace std;

void sorting(int arr[],int n){

    for(int i = 0;i<=n-2; i++){
        for(int j = i+1; j<n; j++){
            if(arr[i] > arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }

    return;
}

void printArray(int arr[],int n){

    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    return;
}

int main()
{
    int arr[] = {4,2,8,3,7,5,6};
    // we need to sort the array in ascending order first.
    int arr_size = 7;
    sorting(arr,arr_size);
    printArray(arr,arr_size);
    
    return 0;
}