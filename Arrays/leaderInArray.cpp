#include <bits/stdc++.h>
using namespace std;
vector<int> leaderInArray(vector<int> &nums)
{
    /*
    //Brute Force (By Self)
    vector<int> leadersArray;
    int n = nums.size();

    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            leadersArray.push_back(nums[n - 1]);
            continue;
        }

        int leader = nums[i];
        bool flag = true;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (leader < nums[j])
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            leadersArray.push_back(leader);
        }
    }
    return leadersArray;
    */

    /*
    // Brute Force
    vector<int> leadersArray;

    for (int i = 0; i < nums.size(); i++)
    {
        bool leader = true;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] <= nums[j])
            {
                leader = false;
                break;
            }
        }

        if (leader)
        {
            leadersArray.push_back(nums[i]);
        }
    }

    return leadersArray;
    */

    // Optimal Approach (By Self)
    vector<int> leadersArray;
    int n = nums.size();
    int leader = nums[n - 1];
    leadersArray.push_back(leader);

    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] > leader)
        {
            leadersArray.push_back(nums[i]);
            leader = nums[i];
        }
    }

    reverse(leadersArray.begin(), leadersArray.end());

    return leadersArray;
}

int main()
{
    vector<int> nums = {4, 7, 1, 0};
    vector<int> result = leaderInArray(nums);

    for (auto &val : result)
    {
        cout << val << " ";
    }
    return 0;
}