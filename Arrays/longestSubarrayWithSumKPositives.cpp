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

    // Optimal Approach
}
int main()
{
    vector<int> nums = {10, 5, 2, 7, 1, 9};
    int k = 15;
    int longestLength = longestSubarray(nums, k);
    cout << "Longest subarray length : " << longestLength;
    return 0;
}