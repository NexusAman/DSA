#include <bits/stdc++.h>
using namespace std;
int longestSubarray(vector<int> &nums, int k)
{
    /*
    //Brute force approach
    int maxLen = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
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

    /*
    // Better Approach
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];

        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }

        int rem = sum - k;

        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }
    return maxLen;
    */

    // Optimal Approach
    int n = nums.size();
    int left = 0, right = 0;
    int maxLen = 0;
    int sum = nums[0];

    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= nums[left];
            left++;
        }

        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if (right < n)
            sum += nums[right];
    }
    return maxLen;
}
int main()
{
    vector<int> nums = {10, 5, 2, 7, 1, 9};
    int k = 15;
    int longestLength = longestSubarray(nums, k);
    cout << "Longest subarray length : " << longestLength;
    return 0;
}