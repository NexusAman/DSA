#include <bits\stdc++.h>
using namespace std;

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    bool flag = false;
    int low = 0, high = str.length() - 1;
    while (low < high)
    {
        if (str[low] != str[high])
        {
            flag = false;
            break;
        }
        else
        {
            low++;
            high--;
            flag = true;
        }
    }

    if (flag)
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome";
    }
}