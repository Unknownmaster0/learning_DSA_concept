#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str;
    cout<<"enter your name: ";
    cin>>str; // taking the string till the space,tab,and new line is entered.
    getline(cin,str); // taking the string till the new line charcter is entered.It takes spaces,tab also.
    
    
    return 0;
}