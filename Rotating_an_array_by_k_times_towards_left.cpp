#include <iostream>
using namespace std;

/*
    Rotating an array means -> just shifting an array.
    if it said rotate an array towards left,which means that shift array elements towards left.
    If it said rotate an array towards right 3times, which means that shift array elements towards right 3 times.
    arr =   2 3 4 5 6  rotate this array towards right 2 times.
1st rotate- 6 2 3 4 5
2nd rotate- 5 6 2 3 4
this way you do rotating an array.
*/

// // Brutforce approach to rotate an array.Time complexity O(n^2);
// void rotate_left(int arr[], int n, int K)
// {
//     // here K is number of times you have to rotate.
//     for (int j = K; j > 0; j--)
//     {
//         int i = 0, temp = arr[0];
//         for (; i < n-1; i++)
//         {
//             arr[i] = arr[i + 1];
//         }

//         arr[i] = temp;
//     }

//     return;
// }

// intelligent approach of rotating an array->Time complexity O(n);
// dry run the code to understand more clearly with the steps wise.
void rotate_left(int arr[],int N,int K){
    // step 1-> storing the first K elements in some array
    int temp[K];
    for(int i = 0; i<K; i++){
        temp[i] = arr[i];
    }

    // step 2-> shifting the remaining (N-K) elements K times towards left
    for(int i = K; i<N; i++){
        arr[i-K] = arr[i];// this will do the shifting.
    }

    // step 3-> append both the array i.e. temp and arr.
    for(int i = 0;i<K; i++){
        arr[N-K+i] = temp[i];
    }

    return;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {7, 5, 2, 11, 2, 43, 1, 1};
    int arr_size = 8;
    int K;
    cout << "enter the number of you want to rotate-> ";
    cin >> K;

    rotate_left(arr, arr_size, K);
    printArray(arr, arr_size);

    return 0;
}