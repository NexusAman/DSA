#include <bits/stdc++.h>
using namespace std;

// Brute Force
/*
int secondLargest(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    return nums[nums.size() - 2];
}
*/

// Better Approach
/*
int secondLargest(vector<int> &nums)
{
    int large = INT_MIN, secLarge = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        large = max(large, nums[i]);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > secLarge && nums[i] != large)
        {
            secLarge = nums[i];
        }
    }
    return secLarge;
}
*/

// Optimal Approach
int secondLargest(vector<int> &nums)
{
    int largest = INT_MIN, secLargest = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > largest)
        {
            secLargest = largest;
            largest = nums[i];
        }

        if (nums[i] > secLargest && nums[i] != largest)
        {
            secLargest = nums[i];
        }
    }
    return secLargest;
}

int main()
{
    vector<int> nums = {1, 2, 32, 4, 5, 356};
    cout << secondLargest(nums);
}