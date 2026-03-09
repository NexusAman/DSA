#include <bits/stdc++.h>
using namespace std;
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    int maxi = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            count++;
            maxi = max(count, maxi);
        }
        else
        {
            count = 0;
        }
    }
    return maxi;
}
int main()
{
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    cout << findMaxConsecutiveOnes(nums);
}