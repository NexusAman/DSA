#include <bits/stdc++.h>
using namespace std;
vector<int> findMissingRepeatingNumbers(vector<int> &nums)
{
    /*
    //By Self
    unordered_map<int, int> mpp;
    int A = -1;
    int B = -1;
    int arrSum = 0;
    int totalSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        mpp[nums[i]]++;
        arrSum += nums[i];
    }

    for (int i = 1; i <= nums.size(); i++)
    {
        totalSum += i;
    }

    for (auto &val : mpp)
    {
        if (val.second == 2)
        {
            A = val.first;
        }
    }

    B = totalSum - (arrSum - A);

    return {A, B};
    */

    /*
    // Brute Force Approach
    int n = nums.size();
    int A = -1, B = -1;

    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[j] == i)
            {
                cnt++;
            }
        }
        if (cnt == 2)
        {
            A = i;
        }
        else if (cnt == 0)
        {
            B = i;
        }

        if (A != -1 && B != -1)
        {
            break;
        }
    }
    return {A, B};
    */

    /*
    // Better Approach
    int n = nums.size();
    int hash[n + 1] = {0};
    int A = -1, B = -1;

    for (int i = 0; i < n; i++)
    {
        hash[nums[i]]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 2)
        {
            A = i;
        }
        else if (hash[i] == 0)
        {
            B = i;
        }
    }

    return {A, B};
    */

    // Optimal Approach
    long long n = nums.size();
    long long S = 0;
    long long SN = (n * (n + 1)) / 2;
    long long S2 = 0;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    for (int i = 0; i < n; i++)
    {
        S += (long long)nums[i];
        S2 += (long long)nums[i] * (long long)nums[i];
    }

    long long val1 = S - SN;   // x - y
    long long val2 = S2 - S2N; // x2 + y2
    val2 = val2 / val1;        // x + y
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}
int main()
{
    vector<int> nums = {3, 5, 4, 1, 1};
    vector<int> ans = findMissingRepeatingNumbers(nums);

    for (auto val : ans)
    {
        cout << val << " ";
    }

    return 0;
}