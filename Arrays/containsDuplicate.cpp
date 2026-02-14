#include <bits/stdc++.h>
using namespace std;
// bool containsDuplicate(vector<int> &nums)
// {
//     int n = nums.size();
//     unordered_map<int, int> mpp;

//     for (int i = 0; i < n; i++)
//     {
//         mpp[nums[i]]++;

//         if (mpp[nums[i]] > 1)
//         {
//             return true;
//         }
//     }
//     return false;
// }
bool containsDuplicate(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> nums = {1, 2, 2, 3, 4, 1};
    bool isDuplicate = containsDuplicate(nums);
    if (isDuplicate)
    {
        cout << "It contains duplicate elements." << endl;
    }
    else
    {
        cout << "It doesn't contains duplicate elements." << endl;
    }
}