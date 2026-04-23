#include <bits/stdc++.h>
using namespace std;
int maxLen(vector<int> &nums)
{
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
}
int main()
{
    vector<int> nums = {2, 10, 4};
    int longest = maxLen(nums);
    cout << format("Longest subarray with sum 0 is of length: {}", longest);
    return 0;
}