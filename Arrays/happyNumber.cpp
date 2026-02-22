#include <bits/stdc++.h>
using namespace std;

bool isHappy(int n)
{
    if (n == 1)
        return true;
    if (n == 4)
        return false;
    int sum = 0;
    // 2^31 - 1 = 2147483647
    // for (int i = n; i != 0; i/=10)
    // {
    //     sum = sum + pow((i % 10), 2);
    // }
    int powDigit;
    while (n > 0)
    {
        powDigit = pow((n % 10), 2);
        sum = sum + powDigit;
        n /= 10;
    }
    return isHappy(sum);
}

int main()
{
    int num;
    cout << "Enter a number to check it's happy or not: ";
    cin >> num;
    if (isHappy(num))
    {
        cout << "It is a Happy number";
    }
    else
    {
        cout << "It is not a Happy number";
    }
}