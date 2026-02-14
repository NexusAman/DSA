#include <bits/stdc++.h>
using namespace std;

// void plusOne(vector<int> &digits)
// {
//     int n = digits.size();

//     digits[n - 1] += 1;
//     if (digits[n - 1] > 9)
//     {
//         int secLast = digits[n - 1] % 10;
//         digits.push_back(secLast);
//         digits[n-1] = digits[n -] / 10;
//     }
// }

// vector<int> plusOne(vector<int> &digits)
// {
//     vector<int> ans(digits);

//     int n = ans.size();
//     int carry;
//     int i = n - 1;

//     while (i >= 0)
//     {
//         if (ans[i] < 9)
//         {
//             ans[i] += 1;
//             carry = 0;
//             break;
//         }
//         if (ans[i] == 9)
//         {
//             ans[i] = 0;
//             carry = 1;
//         }
//         else
//         {
//             ans[i] += carry;
//             carry = 0;
//             break;
//         }
//         i--;
//     }
//     if (carry == 1)
//     {
//         ans.insert(ans.begin(), carry);
//     }
//     return ans;
// }

// correct and optimal approach
vector<int> plusOne(vector<int> &digits)
{
    vector<int> ans(digits);

    int n = ans.size();
    int carry;
    int i = n - 1;

    while (i >= 0)
    {
        if (ans[i] < 9)
        {
            ans[i] += 1;
            carry = 0;
            break;
        }
        if (ans[i] == 9)
        {
            ans[i] = 0;
            carry = 1;
        } // else {
        //     ans[i] += carry;
        //     carry = 0;
        //     break;
        // }
        i--;
    }
    if (carry == 1)
    {
        ans.insert(ans.begin(), carry);
    }
    return ans;
}

int main()
{
    vector<int> digits = {8, 9, 9, 9};
    vector<int> ans = plusOne(digits);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}