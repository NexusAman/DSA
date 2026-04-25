#include <bits/stdc++.h>
using namespace std;
int subarraysWithXorK(vector<int> &nums, int k)
{
    /*
    //Brute Force Approach
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int xorValue = 0;
        for (int j = i; j < n; j++)
        {
            xorValue ^= nums[j];

            if (xorValue == k)
            {
                count++;
            }
        }
    }
    return count;
    */

    // Optimal Approach
    int n = nums.size();
    int cnt = 0;
    int xr = 0;
    unordered_map<int, int> mpp;
    mpp[xr]++;

    for (int i = 0; i < n; i++)
    {
        xr = xr ^ nums[i];
        int x = xr ^ k;

        cnt += mpp[x];
        mpp[xr]++;
    }
    return cnt;
}
int main()
{
    vector<int> nums = {4, 2, 2, 6, 4};
    int k = 6;
    int count = subarraysWithXorK(nums, k);
    cout << count;
    return 0;
}