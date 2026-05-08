#include <bits/stdc++.h>
using namespace std;
int smallestDivisor(vector<int> &nums, int threshold)
{
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
}
int main()
{
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;
    cout << smallestDivisor(nums, threshold);
    return 0;
}