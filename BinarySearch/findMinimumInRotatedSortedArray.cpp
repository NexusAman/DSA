#include <bits/stdc++.h>
using namespace std;
int findMin(vector<int> &nums)
{
    /*
    Brute Force Approach
    int n = nums.size();
    int min = nums[0];

    for (int i = 0; i < n; i++)
    {
        if (min > nums[i])
        {
            min = nums[i];
        }
    }
    return min;
    */

    // Optimal Approach
    int n = nums.size();
    int low = 0, high = n - 1;
    int minValue = INT_MAX;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[low] <= nums[mid])
        {
            minValue = min(minValue, nums[low]);
            low = mid + 1;
        }
        else
        {
            minValue = min(minValue, nums[mid]);
            high = mid - 1;
        }
    }

    return minValue;
}
int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << findMin(nums);
}