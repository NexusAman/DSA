#include <bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int> &nums)
{
    /*
    //Brute Force
    int maxSum = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += nums[k];
            }
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
    */

    /*
    // Better Approach
    int maxSum = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
    */

    // Optimal Approach with follow-up question
    int maxSum = INT_MIN;
    long long sum = 0;
    int start, ansStart, ansEnd;

    for (int i = 0; i < nums.size(); i++)
    {
        if (sum == 0)
        {
            start = i;
        }
        sum += nums[i];

        if (sum > maxSum)
        {
            maxSum = sum;
            ansStart = start;
            ansEnd = i;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    cout << "Starting index of subarray with max Sum: " << ansStart << endl;
    cout << "Ending index of subarray with max Sum: " << ansEnd << endl;
    return maxSum;
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    // vector<int> nums{5, 4, 3};
    cout << maxSubArray(nums);
}