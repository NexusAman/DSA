#include <iostream>
#include <cmath>
using namespace std;
bool isArmstrong(int n)
{
    if (n < 0)
        return false;
    if (n == 0)
        return true;

    int num = n;
    int count = 0;
    int sum = 0;

    while (num > 0)
    {
        num /= 10;
        count++;
    }

    num = n;

    while (num > 0)
    {
        int lastDigit = num % 10;
        sum += (int)round(pow(lastDigit, count));
        num /= 10;
    }

    return sum == n;
}
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (isArmstrong(n))
    {
        cout << n << " is an armstrong number";
    }
    else
    {
        cout << n << " is not an armstrong number";
    }
}