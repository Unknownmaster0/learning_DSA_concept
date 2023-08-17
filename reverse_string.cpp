#include<iostream>
#include<string>
using namespace std;

int compare(int arr[],int brr[]){
    for(int i = 0; i<26; i++){
        if(arr[i] != brr[i])
            return 0;
    }
    return 1;
}

int main()
{
    string s1 = "ab";
    string s2 = "eidbaooo";

// storing the frequency of s1 in arr;
    int arr[26] = {0};
    for(int i = 0; i<26; i++){
        int temp = s1[i] - 'a';
        arr[temp] = 1;
    }

// storing the first window frequency in the brr;
    int brr[26] = {0};
    int window = s1.length();
    for(int i = 0; i<window; i++){
        int temp = s1[i] - 'a';
        brr[temp] = 1;
    }

// Now iterating the window till the size of the s2 string.
    for (int i = window; i < s2.length(); i++)
    {
        int cmpr = compare(arr,brr);
        if(cmpr == 1){
            cout<<"Win"<<endl;
            exit(0);
        }
        else{
            // first element of the stored index ke frequency ko decrease krna hai.
            int temp = s2[i-window]-'a';
            brr[temp] = 0;
            // new element ko add krke uska frequency increase krna hai.
            temp = s2[i] - 'a';
            brr[temp] = 1;
        }
    }
    



    cout<<"lose"<<endl;
    return 0;
}