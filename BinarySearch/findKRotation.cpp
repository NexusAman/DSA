#include <bits/stdc++.h>
using namespace std;
int findKRotation(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            return i + 1;
        }
    }
    return 0;
}
int main()
{
    vector<int> nums = {3, 4, 5, 1, 2};
    cout << findKRotation(nums);
    return 0;
}