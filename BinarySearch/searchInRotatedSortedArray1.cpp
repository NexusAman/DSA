#include <bits/stdc++.h>
using namespace std;
int search(vector<int> &nums, int target)
{
    /*
    //Brute Force Approach
    int n = nums.size();
    int ans = -1;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == k)
        {
            ans = i;
        }
    }
    return ans;
    */

    // Optimal Approach
    int n = nums.size();
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;

        if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target && target <= nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        else
        {
            if (nums[mid] <= target && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}
int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int result = search(nums, target);
    cout << result;
    return 0;
}