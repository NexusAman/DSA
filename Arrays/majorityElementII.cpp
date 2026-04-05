#include <bits/stdc++.h>
using namespace std;
vector<int> majorityElement(vector<int> &nums)
{
    /*
    //Brute Force Approach
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
    int n = nums.size();
    int candidate1 = -1;
    int candidate2 = -1;
    int count1 = 0;
    int count2 = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == candidate1)
        {
            count1++;
        }
        else if (nums[i] == candidate2)
        {
            count2++;
        }
        else if (count1 == 0)
        {
            candidate1 = nums[i];
            count1 = 1;
        }
        else if (count2 == 0)
        {
            candidate2 = nums[i];
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    // verification step
    int countV1 = 0;
    int countV2 = 0;
    vector<int> ans;

    for (int num : nums)
    {
        if (num == candidate1)
            countV1++;
        else if (num == candidate2)
            countV2++;
    }

    if (countV1 > n / 3)
    {
        ans.push_back(candidate1);
    }
    if (countV2 > n / 3)
    {
        ans.push_back(candidate2);
    }

    return ans;
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