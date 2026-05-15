#include <bits/stdc++.h>
using namespace std;
/*
//Brute force approach
int countPartitions(vector<int> &nums, int maxSum)
{
    int n = nums.size();
    int partitions = 1;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if ((sum + nums[i]) <= maxSum)
        {
            sum += nums[i];
        }
        else
        {
            partitions++;
            sum = nums[i];
        }
    }
    return partitions;
}
int splitArray(vector<int> &nums, int k)
{
    int n = nums.size();
    int low = *max_element(nums.begin(), nums.end());
    long long high = accumulate(nums.begin(), nums.end(), 0);

    for (int i = low; i <= high; i++)
    {
        if (countPartitions(nums, i) <= k)
        {
            return i;
        }
    }
    return -1;
}
*/
int main()
{
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;
    cout << splitArray(nums, k);
    return 0;
}