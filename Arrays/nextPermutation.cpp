#include <bits/stdc++.h>
using namespace std;
void nextPermutation(vector<int> &nums)
{
    next_permutation(nums.begin(), nums.end());
}
int main()
{
    vector<int> nums = {1, 1, 2};
    nextPermutation(nums);

    for (auto &val : nums)
    {
        cout << val << " ";
    }
    return 0;
}