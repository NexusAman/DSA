#include <bits\stdc++.h>
using namespace std;

bool isPalidrome(string str, int low)
{
    if (low >= str.length() - 1 / 2)
        return true;

    if (str[low] != str[str.length() - 1 - low])
        return false;

    return isPalidrome(str, low + 1);
}

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;
    int low = 0;
    bool flag = isPalidrome(str, low);

    if (flag)
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome";
    }
}