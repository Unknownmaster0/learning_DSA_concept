#include<iostream>
#include<vector>
using namespace std;

// Given that both the arrays are sorted in ascending order or non-decreasing order.
int main()
{
    vector<int> arr1 {1,2,2,2,3,4};
    vector<int> arr2  {2,2,3,3};
    vector<int>ans;// to store the resultant array.

// Bruteforce approach-> having high time complexity.
    // for (int i = 0; i < 6; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         if(arr1[i] < arr2[j])
    //             break;
           
    //         else if(arr1[i] == arr2[j]){
    //             arr2.at(j) = -123;// taking any negative value,because the array contains only positive numbers.
    //             ans.push_back(arr1[i]);
    //             break;
    //         }
    //     }
        
    // }
    // for(int i = 0; i<ans.size(); i++){
    //     cout<<ans.at(i)<<" ";
    // }
    // cout<<endl;
    int i = 0,j = 0;
    while(i<6 && j<4){
        if(arr1[i] < arr2[j]){
            i++;
        }
        else if(arr1[i] == arr2[j]){
            ans.push_back(arr1[i]);
            i++;j++;
        }
        else if(arr1[i] > arr2[j]){
            j++;
        }
    }
    
     for(int i = 0; i<ans.size(); i++){
        cout<<ans.at(i)<<" ";
    }
    cout<<endl;

    return 0;
}