#include <bits/stdc++.h>
using namespace std;

// Naive approach
// int sumSubarrayMins(vector<int> &arr)
// {
//     long long ans = 0;
//     int MOD = 1e9 + 7;

//     for (int i = 0; i < arr.size(); i++)
//     {
//         for (int j = i; j < arr.size(); j++)
//         {
//             int currMin = INT_MAX;
//             for (int k = i; k <= j; k++)
//             {
//                 currMin = min(currMin, arr[k]);
//             }
//             ans = (ans + currMin) % MOD;
//         }
//     }

//     return ans;
// }

// Better approach
int sumSubarrayMins(vector<int> &arr)
{
    long long ans = 0;
    int MOD = 1e9 + 7;

    for (int i = 0; i < arr.size(); i++)
    {
        int currMin = INT_MAX;
        for (int j = i; j < arr.size(); j++)
        {
            currMin = min(currMin, arr[j]);

            ans = (ans + currMin) % MOD;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    cout << sumSubarrayMins(arr);
    return 0;
}