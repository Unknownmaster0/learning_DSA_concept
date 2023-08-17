#include<iostream>
using namespace std;

/*
    insertion sort-> Having rounds number = size of array - 1;
    Algorithm -> 0th element consider to be sorted. compare the next element with the previous elements and get the position of the element.
                You need to shift the previous for making space for the next element.
*/


void insertion_sort(int arr[],int n){

    int i = 1;// i is from 1 because we consider the 0th element sorted.
    while(i<n){
        int temp = arr[i];
        int j = i - 1;
        while(j >= 0){
            if( temp < arr[j]){
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
            j--;
        }

        arr[j+1] = temp;
        i++;
    }

    return;
}

void printArray(int arr[],int n){
    for(int i = 0; i<n ;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[] = {10,1,7,4,8,2,11};
    int arr_size = 7;

    insertion_sort(arr,arr_size);
    printArray(arr,arr_size);

    return 0;
}