#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
    problem statement-> given an array of size n and positive integer k.you need to find the minimum sub-array sum where k is the length of sub-array given.

*/
// brutforce approach. -> Time complexity O(n^2) where n is the size of array.
/*
    Approach->
    1. first loop will take the initial position of the sub-array.
    2. inner loop will iterate the sub-array to k times (as we need k length sub-array) and finding the sum.
*/
// int minimum_sum(int arr[], int n, int k)
// {
//     int min_sum = INT_MAX;
//     int temp = k;
//     for (int i = 0; i < (n - k + 1); i++)
//     {
//         int sum = 0;
//         while (k > 0)
//         {
//             sum += arr[i + k - 1];
//             k--;
//         }
//         k = temp;
//         if (min_sum > sum)
//         {
//             min_sum = sum;
//         }
//     }

//     return min_sum;
// }

// sliding window technique -> time complexity O(n);
/*
Algorithm

step 1-> We store the sum of the first window/subarray of size ‘K’ in ‘minSum’.
step 2-> We initialize ‘Sum’ to ‘minSum’.
step 3-> We now traverse the rest of the array.
step 4-> We compute ‘Sum’ by removing the leftmost element i.e. ARR[i-K] and including the current element i.e. ARR[i].
step 5-> We set ‘minSum’ to the minimum of ‘minSum’ and ‘Sum’.
Finally, we return ‘minSum’ as result.
*/
int minimum_sum(int arr[],int n,int k){
    // step 1->
    int min_sum = 0;
    for(int i = 0; i<k; i++){
       min_sum += arr[i];
    }
    // step 2->
    int sum = min_sum;

    // step 3->
    for(int i = k; i<n; i++){
    // step 4->
        sum = sum - arr[i-k] + arr[i];
    // step 5->
        if(min_sum > sum){
            min_sum = sum;
        }
    }

    return min_sum;
}


int main()
{
    int arr[] = {4,2,-1,6,-2,4};
    int arr_size = 6;
    int k=2;
    // cout << "enter the size of sub-array you need-> ";
    // cin >> k;

    cout<<"the minimum sum of the sub-array is -> "<<minimum_sum(arr,arr_size,k)<<endl;

    return 0;
}