#include <bits/stdc++.h>
using namespace std;
int smallestDivisor(vector<int> &nums, int threshold)
{
    /*
    //Brute force approach
    int n = nums.size();
    int maxDivisor = *max_element(nums.begin(), nums.end());

    for (int i = 1; i <= maxDivisor; i++)
    {
        long long sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += ceil((double)nums[j] / i);
        }
        if (sum <= threshold)
        {
            return i;
        }
    }
    return -1;
    */

    // Optimal approach
    int n = nums.size();
    int maxDivisor = *max_element(nums.begin(), nums.end());
    int ans = -1;

    int low = 1, high = maxDivisor;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += ceil((double)nums[i] / mid);
        }
        if (sum <= threshold)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;
    cout << smallestDivisor(nums, threshold);
    return 0;
}