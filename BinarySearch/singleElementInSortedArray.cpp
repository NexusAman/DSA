#include <bits/stdc++.h>
using namespace std;
int singleNonDuplicate(vector<int> &nums)
{
    /*
    // Brute Force 1
    int n = nums.size();

    // if array contains one element
    if (n == 1)
        return nums[0];

    for (int i = 0; i < n - 1; i += 2)
    {
        // checks the next element is equal or not
        if (nums[i] != nums[i + 1])
        {
            return nums[i];
        }
    }

    return nums[n - 1]; // if last element is unique
    */

    /*
    // Brute Force 2
    int n = nums.size();
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans ^= nums[i];
    }
    return ans;
    */

    // Optimal Approach
    int n = nums.size();

    if (n == 1)
        return nums[0];

    if (nums[0] != nums[1])
        return nums[0];

    if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];

    int low = 1, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
        {
            return nums[mid];
        }

        if (((mid % 2 == 1) && nums[mid] == nums[mid - 1]) || ((mid % 2 == 0) && nums[mid] == nums[mid + 1]))
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
    vector<int> nums = {3, 3, 7, 7, 10, 11, 11};
    cout << singleNonDuplicate(nums);
    return 0;
}