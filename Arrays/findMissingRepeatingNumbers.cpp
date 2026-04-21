#include <bits/stdc++.h>
using namespace std;
vector<int> findMissingRepeatingNumbers(vector<int> &nums)
{
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