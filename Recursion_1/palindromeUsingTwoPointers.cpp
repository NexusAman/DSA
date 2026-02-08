#include <bits/stdc++.h>
using namespace std;

// case in-sensitive
bool isPalindrome(const string &str, int low, int high)
{
    while (low < high)
    {
        if (tolower(str[low]) != tolower(str[high]))
            return false;

        low++;
        high--;
    }
    return true;
}

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    int low = 0, high = str.length() - 1;

    if (isPalindrome(str, low, high))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}
