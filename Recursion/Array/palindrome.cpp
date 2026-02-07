#include <iostream>
#include <cctype> // for tolower
using namespace std;

bool isPalindrome(int i, int n, string &s)
{
    if (i >= n / 2)
    {
        return true;
    }

    // compare after converting both sides to lowercase
    if (tolower((unsigned char)s[i]) != tolower((unsigned char)s[n - i - 1]))
        return false;

    return isPalindrome(i + 1, n, s);
}

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int n = s.size();
    if (isPalindrome(0, n, s))
    {
        cout << s << " is Palindrome";
    }
    else
    {
        cout << s << " is not a Palindrome";
    }
}
