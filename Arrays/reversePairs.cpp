#include <bits/stdc++.h>
using namespace std;
int reversePairs(vector<int> &nums)
{
    /*
    Brute Force Approach
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] > 2 * nums[j])
            {
                count++;
            }
        }
    }
    return count;
    */
}
int main()
{
    vector<int> nums = {1, 3, 2, 3, 1};
    int count = reversePairs(nums);
    cout << format("Reverse pairs exists in nums array : {}", count);
    return 0;
}