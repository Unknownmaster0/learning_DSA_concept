/*
Question -> This question says -> you have given an array containing elements 0,1,2.
            You need to sort the array without using predefined sorting algorithm.

Answer -> we are going to use The Dutch National Flag Algorithm. In which we are using three variables low,mid and high.
        Low -> belongs to 0 , Mid -> belongs to 1 , High -> belongs to 2;
*/
#include<iostream>
#include<vector>
using namespace std;

// NOTE : If we pass the vector to the function and do some modification inside function then it doesn't reflects inside the main function of the program.

void sorting(int a[],int size){
    // Dutch National Flag Algorithm
    int low = 0, mid = 0 , high = size-1;

    while(mid <= high){
        if(a[mid] == 0){
            swap(a[mid],a[low]);
            low ++;
            mid ++;
        }
        else if(a[mid] == 2){
            swap(a[mid],a[high]);
            high--;
        }
        else{
            // in this case a[mid] == 1, then it is at correct place.So, not need to swap, only increment the mid.
            mid++;
        }
    }

    return;
}

void printArray(int a[],int size){
    for(int i = 0; i<size; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}


int main()
{
    int array[] = {1,2,0,1,2,1,1,1,2,2,2,0,0,0,1};
    int size = 15;
    sorting(array,size);
    printArray(array,size);
    
    return 0;
}