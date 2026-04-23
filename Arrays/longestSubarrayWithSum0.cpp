#include <bits/stdc++.h>
using namespace std;
int maxLen(vector<int> &nums)
{
    /*
    //Brute Force Approach
    int n = nums.size();
    int maxCount = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = 0, count = 0;
            for (int k = i; k <= j; k++)
            {
                sum += nums[k];
                count++;
            }

            if (sum == 0)
            {
                maxCount = max(maxCount, count);
            }
        }
    }
    return maxCount;
    */

    // Optimal Approach
    int n = nums.size();
    unordered_map<int, int> mpp;
    int maxi = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];

        if (sum == 0)
        {
            maxi = max(maxi, i + 1);
        }
        else
        {
            if (mpp.find(sum) != mpp.end())
            {
                maxi = max(maxi, i - mpp[sum]);
            }
            else
            {
                mpp[sum] = i;
            }
        }
    }
    return maxi;
}
int main()
{
    vector<int> nums = {-2, -10, 2, 10};
    int longest = maxLen(nums);
    cout << format("Longest subarray with sum 0 is of length: {}", longest);
    return 0;
}