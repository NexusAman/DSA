#include <bits/stdc++.h>
using namespace std;
vector<int> rearrangeArray(vector<int> &nums)
{
    /*
    //Brute Force
    vector<int> pos;
    vector<int> neg;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            pos.push_back(nums[i]);
        }
        else
        {
            neg.push_back(nums[i]);
        }
    }

    int pnt1 = 0;
    int pnt2 = 0;

    while (pnt1 < pos.size())
    {
        result.push_back(pos[pnt1++]);
        result.push_back(neg[pnt2++]);
    }
    return result;
    */

    /*
    // Better Approach
    vector<int> pos;
    vector<int> neg;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            pos.push_back(nums[i]);
        }
        else
        {
            neg.push_back(nums[i]);
        }
    }

    for (int i = 0; i < nums.size() / 2; i++)
    {
        nums[2 * i] = pos[i];
        nums[2 * i + 1] = neg[i];
    }

    return nums;
    */

    // Optimal Approach
    vector<int> result(nums.size());
    int posIndex = 0;
    int negIndex = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            result[posIndex] = nums[i];
            posIndex += 2;
        }
        else
        {
            result[negIndex] = nums[i];
            negIndex += 2;
        }
    }
    return result;
}
int main()
{
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    vector<int> result = rearrangeArray(nums);

    for (auto &val : result)
    {
        cout << val << " ";
    }
}