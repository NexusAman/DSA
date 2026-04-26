#include <bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> &nums, int x)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] >= x)
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
    vector<int> nums = {1, 2, 2, 3};
    int x = 2;
    cout << lowerBound(nums, x);
    return 0;
}