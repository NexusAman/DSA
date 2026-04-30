#include <bits/stdc++.h>
using namespace std;
bool search(vector<int> &nums, int target)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == target)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;
    cout << search(nums, target);
    return 0;
}