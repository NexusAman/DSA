#include <bits/stdc++.h>
using namespace std;
int search(vector<int> &nums, int k)
{
    int n = nums.size();
    int ans = -1;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == k)
        {
            ans = i;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int k = 0;
    int result = search(nums, k);
    cout << result;
    return 0;
}