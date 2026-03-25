#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target)
{
    /*
    //Brute Force
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
    */

    /*
    // Better Approach
    int n = nums.size();
    vector<pair<int, int>> originalIndex;

    for (int i = 0; i < nums.size(); i++)
    {
        originalIndex.push_back({nums[i], i});
    }

    sort(originalIndex.begin(), originalIndex.end());

    int i = 0, j = n - 1;

    while (i < j)
    {
        long long sum = originalIndex[i].first + originalIndex[j].first;

        if (sum == target)
        {
            return {originalIndex[i].second, originalIndex[j].second};
        }
        else if (sum > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return {-1, -1};
    */

    // Optimal Approach
    unordered_map<int, int> sum;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int complement = target - nums[i];

        if (sum.find(complement) != sum.end())
        {
            return {sum[complement], i};
        }

        sum[nums[i]] = i;
    }
    return {-1, -1};
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 26;
    vector<int> result = twoSum(nums, target);
    for (auto &val : result)
    {
        cout << val << " ";
    }
    return 0;
}