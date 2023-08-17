#include<iostream>
using namespace std;

/*
    concepts going to learn -> 
        1. Row wise and coloumn wise input method in the 2-d array
        2. Row wise sum of the array elements
        2. Row wise sum of the array elements and also find the the row of maximum sum;
        3. Coloumn wise sum of the array elements
*/


// Row wise sum of the array elements -> and also finding the maximum row number of the sum; 
void row_sum(int row,int arr[][3],int col){
    int i = 0,j = 0; // here i is pointing to the row and j is pointing to the coloumn
    int sum = 0;
    int maxsum = 0;
    int maxindex = 0;
    while(i < row){
        if(j < col){
            sum += arr[i][j++];
        }
        else{
            cout<<sum<<"  ";
            if(maxsum < sum){
                maxsum = sum;
                maxindex = i;
            }
            sum = 0;
            j = 0;
            i++;
        }
    }
    cout<<endl;
    cout<<"maximum row sum is -> "<<maxindex<<endl;
    return ;
}

// coloumn wise sum of the array elements -> 
void col_sum(int row,int arr[][3],int col){
    int i = 0,j = 0; // here i is pointing to coloumn and j is row
    int sum = 0;
    while(i < col){
        if(j < row){
            sum += arr[j++][i]; // i ko baad me likhe hai b/c ye coloumn hai
        }
        else{
            cout<<sum<<"  ";
            sum = 0;
            j = 0;
            i++;
        }
    }
    cout<<endl;
    return ;
}


void printArray(int arr[],int n){
    for(int i=0; i<n; i++)
        cout<<arr[i]<<"   ";

    cout<<endl;
}

int main()
{
    int arr[3][3];
    int row_size = 3;
    int col_size = 3;

    // // taking input row-wise i.e pahle row1 me sara element input then row2 me sara element input then ...........
    // for(int row = 0; row < 3; row++){
    //     for(int col = 0; col < 3; col++){
    //         cin>>arr[row][col];
    //     }
    // }

    // taking input col-wise i.e pahle col1 me sara element input then col2 me sara element input then ...........
    for(int col = 0; col < 3; col++){
        for(int row = 0; row < 3; row++){
            cin>>arr[row][col];
        }
    }

    // Output for 2-D array
    for (int row = 0; row < 3; row++)
    {
       for(int col = 0; col < 3; col++)
            cout<<arr[row][col]<<"    ";

        cout<<endl;
    }

    row_sum(row_size,arr,col_size);
    // col_sum(row_size,arr,col_size);
    
    return 0;
}