#include<iostream>
using namespace std;

/*
    Bubble sort-> It is done in various rounds.In every rounds we iteratke the loop with condition i<= n-2; where n is size of array.
                    In every rounds,the (number of round)th largest element is placed in its correct place.
                    example -> in round 1 = the 1st largest element is set to its correct place.
                    and we use the condition that if ( arr[i] > arr[i+1] ) then swap(arr[i],arr[i+1]);
                    the code can be more optimized i.e. when in any round the number of swaps is 0 then the array is sorted.
                    return from there only.

*/

void bubble_sort(int arr[], int n){

    int i = 0,j;
    int swapped_number = 0;
    bool swapping;
    while (i<n)
    {   swapping = 0;
        j = 0;
        while(j <= n-i-2){
            if(arr[j] > arr[j + 1]){
                swapped_number++;
                swapping = 1;
                swap(arr[j],arr[j+1]);
            }
            
            j++;
        }
        if(swapping == 0){
            break;
        }
        i++;
    }

    cout<<"the number of swapping done to sort this array is: "<<swapped_number<<endl;
    

    return ;
}

void printArray(int arr[],int n){
    for(int i = 0; i<n ;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[] = {8, 22, 7, 9, 31, 5, 13};
    int arr_size = 7;
    bubble_sort(arr,arr_size);
    printArray(arr,arr_size);

    return 0;
}