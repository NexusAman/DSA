#include <bits/stdc++.h>
using namespace std;
int getFloor(vector<int> nums, int x)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] <= x)
        {
            ans = nums[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
int getCeil(vector<int> nums, int x)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] >= x)
        {
            ans = nums[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
vector<int> getFloorAndCeil(vector<int> nums, int x)
{
    return {getFloor(nums, x), getCeil(nums, x)};
}
int main()
{
    vector<int> nums = {3, 4, 4, 7, 8, 10};
    int x = 5;
    vector<int> ans = getFloorAndCeil(nums, x);

    for (auto val : ans)
    {
        cout << val << " ";
    }
    return 0;
}