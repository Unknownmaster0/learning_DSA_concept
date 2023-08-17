#include <iostream>
using namespace std;

// question -> check palindrome?
int length(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }

    return i;
}

char lower_case(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return ch;
    else if (ch >= 'A' && ch <= 'Z')
    {
        ch = ch + 32;
        // ch = ch-'A'+'a';
    }

    return ch;
}

// considering the upper and lower case as same:
bool checkPalindrome(char arr[], int n)
{
    int first = 0;
    int last = n -1;
    while (first < last)
    {
        if (lower_case(arr[first]) != lower_case(arr[last]))
        {
            return 0;
        }
        first++;
        last--;
    }
    return 1;
}

int main()
{
    char str[100];
    cout << "enter the word: ";
    cin >> str;

    int len = length(str);
    cout << "the length of your word is -> " << len << endl;

    // cout << lower_case('n');
    int ans = checkPalindrome(str, len);
    cout << "check palindrome or not=> " << ans << endl;

    return 0;
}