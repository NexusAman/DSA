#include <bits/stdc++.h>
using namespace std;
vector<int> searchRange(vector<int> &nums, int target)
{
    /*
    //Brute Force Approach
    int n = nums.size();
    vector<int> ans(2, -1);

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == target)
        {
            ans[0] = i;

            for (int j = i; j < n; j++)
            {
                if (j < n - 1 && nums[j] == nums[j + 1])
                {
                    continue;
                }
                ans[1] = j;
                break;
            }
            break;
        }
    }
    return ans;
    */
}
int main()
{
    vector<int> nums = {1};
    int target = 1;
    vector<int> ans = searchRange(nums, target);

    for (auto val : ans)
    {
        cout << val << " ";
    }

    return 0;
}