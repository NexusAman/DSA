#include <bits/stdc++.h>
using namespace std;

string addStrings(string num1, string num2)
{
    int i = num1.length() - 1;
    int j = num2.length() - 1;

    int carry = 0;
    string result = "";
    while (i >= 0 || j >= 0 || carry)
    {
        int digit1 = 0, digit2 = 0;
        if (i >= 0)
        {
            digit1 = num1[i] - '0';
            i--;
        }

        if (j >= 0)
        {
            digit2 = num2[j] - '0';
            j--;
        }

        int sum = digit1 + digit2 + carry;
        int newDigit = sum % 10;
        int carry = sum / 10;

        result += (newDigit + '0');
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string num1 = "20";
    string num2 = "20";
    cout << addStrings(num1, num2);
}