#include <bits/stdc++.h>
using namespace std;
bool search(vector<int> &nums, int target)
{
    /*
    //Brute Force Approach
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == target)
        {
            return true;
        }
    }
    return false;
    */

    // Optimal Approach
    int n = nums.size();
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return true;

        // 🔥 HANDLE DUPLICATES
        if (nums[low] == nums[mid] && nums[mid] == nums[high])
        {
            low++;
            high--;
        }

        // Left sorted
        else if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target && target < nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        // Right sorted
        else
        {
            if (nums[mid] < target && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return false;
}
int main()
{
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 3;
    cout << search(nums, target);
    return 0;
}