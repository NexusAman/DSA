#include <bits/stdc++.h>
using namespace std;
int longestSubarray(vector<int> &nums, int k)
{
    /*
    // Brute Force Approach
    int n = nums.size();
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];

            if (sum == k)
            {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
    */
}
int main()
{
    vector<int> nums = {10, 5, 2, 7, 1, 9};
    int k = 15;
    cout << longestSubarray(nums, k);
}