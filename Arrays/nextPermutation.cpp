#include <bits/stdc++.h>
using namespace std;
void nextPermutation(vector<int> &nums)
{
    // Brute Force
    //  next_permutation(nums.begin(), nums.end());

    // Optimal Approach
    // first find the pivot element
    int n = nums.size();
    int pivot = -1;
    int swapIndex = -1;

    for (int i = n - 1; i > 0; i--)
    {
        if (nums[i - 1] < nums[i])
        {
            pivot = i - 1;
            cout << pivot << endl;
        }
    }

    // find the rightmost element greater than pivot (just greater)
    for (int i = n - 1; i > 0; i--)
    {
        if (nums[i] > pivot)
        {
            swapIndex = i;
            cout << swapIndex << endl;
            break;
        }
    }

    swap(nums[pivot], nums[swapIndex]);            // swap with pivot element
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