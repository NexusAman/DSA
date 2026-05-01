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
}
int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << findMin(nums);
}