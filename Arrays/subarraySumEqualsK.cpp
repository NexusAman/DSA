#include <bits/stdc++.h>
using namespace std;
int subarraySum(vector<int> &nums, int k)
{
    /*
    //Brute Force
    int n = nums.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += nums[k];
            }
            if (sum == k)
            {
                cnt++;
            }
        }
    }
    return cnt;
    */

    /*
    //Better Approach
    int n = nums.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (sum == k)
            {
                cnt++;
            }
        }
    }
    return cnt;
    */

    // Optimal Approach
    unordered_map<int, int> mpp;
}
int main()
{
    vector<int> nums = {1, 2, 3};
    int k = 3;
    cout << subarraySum(nums, k);
}