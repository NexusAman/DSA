#include <bits/stdc++.h>
using namespace std;
vector<int> majorityElement(vector<int> &nums)
{
    /*
    //Brute Force
    int mini = nums.size() / 3;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] == nums[i])
            {
                count++;
            }
        }

        if (count > mini && find(ans.begin(), ans.end(), nums[i]) == ans.end())
        {
            ans.push_back(nums[i]);
        }
    }

    return ans;
    */

    /*
    //Better Approach
    unordered_map<int, int> mpp;
    int n = nums.size() / 3;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        mpp[nums[i]]++;
    }

    for (auto &val : mpp)
    {
        if (val.second > n)
        {
            ans.push_back(val.first);
        }
    }

    return ans;
    */

    // Optimal Approach
}
int main()
{
    vector<int> nums = {3, 2, 1, 3, 2, 2, 3, 2, 3};
    vector<int> result = majorityElement(nums);

    for (auto &val : result)
    {
        cout << val << " ";
    }
    return 0;
}