#include<iostream>
using namespace std;

/*
    Kedane's Algorithm -> used to find the subarray the maximum sum of the sub-array. It has time complexity O(n) where n is length of array.
                        It consists of three major steps:
                        1. considering -> sum = 0; and updating sum += arr[i];
                        2. maximum_sum = arr[0]; maximum_sum is the maximum value of the sum. maximum_sum = max(maximum_sum,sum);
                        3. if(sum < 0) sum = 0; discard that sub-array for which the value of sum < 0.
*/

int maximum_sum_subarray(int arr[],int n){
    int sum = 0,max_sum = arr[0];
    for(int i = 0; i<n; i++){
        sum += arr[i];
        if(max_sum < sum){ // in this we are storing the maximum value max_sum = max(max_sum,sum);
            max_sum = sum;
        }

        if(sum < 0) sum = 0;// discard that sub-array for which the sum < 0;
    }

    return max_sum;
}

int main()
{
    int arr[] = {5,-4,2,9,-5,4};
    int arr_size = 6;

    cout<<"the maximum sum of the sub-array is: "<<maximum_sum_subarray(arr,arr_size)<<endl;
    return 0;
}