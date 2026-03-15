#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> &nums)
{
    /*
    //Brute Force
    for (int i = 0; i < nums.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
            {
                count++;
            }
        }

        if (count > nums.size() / 2)
        {
            return nums[i];
        }
    }

    return -1;
    */

    /*
    // Better Approach
    unordered_map<int, int> mpp;

    for (int i = 0; i < nums.size(); i++)
    {
        mpp[nums[i]]++;
    }

    for (auto &it : mpp)
    {
        if (it.second > nums.size() / 2)
        {
            return it.first;
        }
    }

    return -1;
    */

    // Optimal Approach
    int candidate;
    int count = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
        {
            candidate = nums[i];
        }

        if (nums[i] == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == candidate)
        {
            count++;
        }
    }

    if (count > nums.size() / 2)
    {
        return candidate;
    }

    return -1;
}

int main()
{
    vector<int> nums = {3, 3, 4, 4};
    cout << majorityElement(nums);
}