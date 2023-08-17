#include<iostream>
using namespace std;

int main()
{
    int num,sum = 0;
    cout<<"enter the digit: ";
    cin>>num;
    while(num != 0){
        sum = sum ^ (num%2);
        num = num /2;
    }
    if(sum == 1){
        printf("digit is in form of 2^i");
    }
    else{
        printf("NOT 2 ^ i");
    }
    return 0;
}