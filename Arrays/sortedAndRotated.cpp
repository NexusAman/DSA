#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> nums)
{
    int n = nums.size();
    int breakcount = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            breakcount++;
        }
    }
    if (nums[n - 1] > nums[0])
    {
        breakcount++;
    }
    if (breakcount <= 1)
        return true;
    else
        return false;
}
int main()
{
    vector<int> nums = {2, 1, 3, 4};
    cout << check(nums);
    // if (check(nums))
    // {
    //     cout << "Array is sorted & rotated ";
    // }
    // else
    // {
    //     cout << "Array is not sorted & rotated ";
    // }
}