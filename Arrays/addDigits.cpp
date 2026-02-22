#include <bits/stdc++.h>
using namespace std;
int addDigits(int n)
{
    if (n >= 0 && n <= 9)
        return n;
    int sum = 0;

    while (n > 0)
    {
        int lastDigit = n % 10;
        sum = sum + lastDigit;
        n /= 10;
    }
    return addDigits(sum);
}
int main()
{
    int n = 38;
    cout << addDigits(n);
}