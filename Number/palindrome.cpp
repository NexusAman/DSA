#include <iostream>
using namespace std;
bool isPalindrome(int n)
{
    int originalNum = n;
    long long revNum = 0;
    if (n < 0)
        return false;

    while (n > 0)
    {
        int lastDigit = n % 10;
        revNum = revNum * 10 + lastDigit;
        n = n / 10;
    }
    if (originalNum == revNum)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (isPalindrome(n))
    {
        cout << n << " is a Palindrome" << endl;
    }
    else
    {
        cout << n << " is not a Palindrome" << endl;
    }
}