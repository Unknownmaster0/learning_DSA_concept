#include<iostream>
using namespace std;

long long fast_power(int base,int power){
    long long result = 1;
    while(power > 0){
        if(power & 1)
            result *= base;
        base *= base;
        power >>= 1;
    }

    return result;
}

int main()
{
    int base,degree;
    cout<<"enter base-> ";
    cin>>base;
    cout<<endl;
    cout<<"enter degree-> ";
    cin>>degree;
    cout<<endl;

    cout<<"ans -> "<<fast_power(base,degree)<<endl;

    return 0;
}