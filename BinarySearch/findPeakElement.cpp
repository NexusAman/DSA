#include <bits/stdc++.h>
using namespace std;
int findPeakElement(vector<int> &nums)
{
    /*
    //Brute Force Approach
    int n = nums.size();
    int index = -1;
    if (n == 1)
        return 0;
    if (nums[0] > nums[1])
        return 0;
    if (nums[n - 1] > nums[n - 2])
        return n - 1;

    for (int i = 1; i < n - 1; i++)
    {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
        {
            return i;
        }
    }
    return -1;
    */

    // Optimal Approach
    int n = nums.size();
    if (n == 1)
    {
        return 0;
    }
    if (nums[0] > nums[1])
    {
        return 0;
    }
    if (nums[n - 1] > nums[n - 2])
    {
        return n - 1;
    }

    int low = 1, high = n - 2;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
        {
            return mid;
        }
        else if (nums[mid + 1] > nums[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    cout << findPeakElement(nums);
    return 0;
}