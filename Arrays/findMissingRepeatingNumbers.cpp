#include <bits/stdc++.h>
using namespace std;
vector<int> findMissingRepeatingNumbers(vector<int> &nums)
{
    unordered_map<int, int> mpp;
    int A = -1;
    int B = -1;
    int arrSum = 0;
    int totalSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        mpp[nums[i]]++;
        arrSum += nums[i];
    }

    for (int i = 1; i <= nums.size(); i++)
    {
        totalSum += i;
    }

    for (auto &val : mpp)
    {
        if (val.second == 2)
        {
            A = val.first;
        }
    }

    B = totalSum - (arrSum - A);

    return {A, B};
}
int main()
{
    vector<int> nums = {3, 5, 4, 1, 1};
    vector<int> ans = findMissingRepeatingNumbers(nums);

    for (auto val : ans)
    {
        cout << val << " ";
    }

    return 0;
}