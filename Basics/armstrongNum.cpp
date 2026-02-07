#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (num < 0)
        return 0;

    int originalNum = num;
    int lastDigit = 0;
    int sum = 0;
    int power = to_string(num).length();
    while (num > 0)
    {
        lastDigit = num % 10;
        sum += pow(lastDigit, power);
        num /= 10;
    }
    if (sum == originalNum)
    {
        cout << "It is an Armstrong number. " << endl;
    }
    else
    {
        cout << "It is not an Armstrong number." << endl;
    }
    return 0;
}