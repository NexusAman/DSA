#include <bits/stdc++.h>
using namespace std;
int findKRotation(vector<int> &nums)
{
    /*
    // Brute Force Approach
    int n = nums.size();
    int min = INT_MAX;
    int index = -1;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] < min)
        {
            min = nums[i];
            index = i;
        }
    }
    return index;
    */

    /*
    //Better Approach
    int n = nums.size();

    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            return i + 1;
        }
    }
    return 0;
    */

    // Optimal Approach
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = INT_MAX;
    int index = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[low] <= nums[mid])
        {
            if (nums[low] < ans)
            {
                ans = nums[low];
                index = low;
            }
            low = mid + 1;
        }
        else
        {
            if (nums[mid] < ans)
            {
                ans = nums[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }
    return index;
}
int main()
{
    vector<int> nums = {3, 4, 5, 1, 2};
    cout << findKRotation(nums);
    return 0;
}