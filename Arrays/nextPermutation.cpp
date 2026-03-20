#include <bits/stdc++.h>
using namespace std;
void nextPermutation(vector<int> &nums)
{
    // Brute Force
    //  next_permutation(nums.begin(), nums.end());

    // Optimal Approach
    int n = nums.size();
    int pivot = -1;
    int swapIndex = -1;

    // first find the pivot element
    for (int i = n - 1; i > 0; i--)
    {
        if (nums[i - 1] < nums[i])
        {
            pivot = i - 1;
            break;
        }
    }

    // if array has no next permutation
    if (pivot == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    // find the rightmost element greater than pivot (just greater)
    for (int i = n - 1; i > pivot; i--)
    {
        if (nums[i] > pivot)
        {
            swap(nums[i], nums[pivot]); // swap with pivot element
            break;
        }
    }

    reverse(nums.begin() + pivot + 1, nums.end()); // reverse the portion after pivot
}
int main()
{
    vector<int> nums = {1, 4, 2};
    nextPermutation(nums);

    for (auto &val : nums)
    {
        cout << val << " ";
    }
    return 0;
}