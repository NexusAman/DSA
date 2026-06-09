#include <bits/stdc++.h>
using namespace std;
int myAtoi(string s)
{
    int i = 0;
    int l = s.length();

    // skiping leading whitespaces
    while (i < l && isspace(s[i]))
    {
        i++;
    }

    if (i == l)
    {
        return 0;
    }

    // check for valid sign
    bool negative = false;

    if (s[i] == '-')
    {
        negative = true;
        i++;
    }
    else if (s[i] == '+')
    {
        i++;
    }
    else if (!isdigit(s[i]))
    {
        return 0;
    }

    if (i == l)
    {
        return 0;
    }

    // skip leading zeros
    while (i < l && s[i] == '0')
    {
        i++;
    }

    if (i == l)
    {
        return 0;
    }

    // extract numbers and return the int value
    int value = 0;
    int max = INT_MAX / 10;
    int min = INT_MIN / 10;

    while (i < l && isdigit(s[i]))
    {
        int digit = s[i] - '0';

        // handling overflow
        if (value > max)
        {
            return INT_MAX;
        }
        else if (value == max && digit > 7)
        {
            return INT_MAX;
        }

        // handling underflow
        if (value < min)
        {
            return INT_MIN;
        }
        else if (value == min && digit > 8)
        {
            return INT_MIN;
        }

        if (negative)
        {
            value = value * 10 + (-digit);
        }
        else
        {
            value = value * 10 + digit;
        }
        i++;
    }
    return value;
}
int main()
{
    string s = " -042";
    cout << myAtoi(s);
    return 0;
}