#include<iostream>
using namespace std;

// Recursive approach of binary search: we not recommend to use recursive approach of the binary search.
/*
    Because when we use recursion then,it creates stacks memory for the number of times recursion is call.
    Example if recursion is called itself 4 times then 4 stack memory is used. Due to which the memory consumption is increased in recursive binary search.
    while in iterative approach we have O(1)->constant space complexity.
    in recursive approach we have O(log(n))-> space complexity. because in worst case recursive call log(n) times chalega and that many times it takes stack memory.
*/
int BinarySEarch(int arr[],int size,int key,int low,int high){
    if(low > high)return -1;

    int mid = (low + high)/2;

    if(arr[mid] == key)return mid;
    if(arr[mid] > key){
        return BinarySEarch(arr,size,key,low,mid-1);
    }
    if(arr[mid] < key){
        return BinarySEarch(arr,size,key,mid+1,high);
    }

}

// // iterative approach of binary search.
// int BinarySEarch(int arr[],int n,int key){
//        int i = 0,j = 6,mid; // j = (n-1) where n is the length of the array.
//         while(i<= j){
//         mid = i + ((j - i)/2);
//         if(arr[mid] == key){
//             return mid;
//         }
//         else if(arr[mid]<key){
//             i = mid + 1;
//         }
//         else if(arr[mid]>key){
//             j = mid - 1;
//         }
//     }
//     return -1;
// }

int main()
{
    // int arr[7] = {3,4,6,7,9,14,23};
    int arr[7] = {5,11,13,17,19,27};
    // the key that you have to find in this array is 9.
    int key = 19;
    // int index = BinarySEarch(arr,7,9); // this is for iterative approach
    int index = BinarySEarch(arr,7,key,0,6);
    cout<<"the index where the key present is : "<<index<<endl;
    return 0;
}