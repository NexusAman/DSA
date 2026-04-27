#include <bits/stdc++.h>
using namespace std;
int firstOccurence(vector<int> &nums, int target)
{
    int n = nums.size();
    int first = -1;
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == target)
        {
            first = mid;
            high = mid - 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return first;
}

int lastOccurence(vector<int> &nums, int target)
{
    int n = nums.size();
    int last = -1;
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == target)
        {
            last = mid;
            low = mid + 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return last;
}
vector<int> searchRange(vector<int> &nums, int target)
{
    /*
    //Brute Force Approach by self
    int n = nums.size();
    vector<int> ans(2, -1);

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == target)
        {
            ans[0] = i;

            for (int j = i; j < n; j++)
            {
                if (j < n - 1 && nums[j] == nums[j + 1])
                {
                    continue;
                }
                ans[1] = j;
                break;
            }
            break;
        }
    }
    return ans;
    */

    /*
    // Brute Force Actual
    int n = nums.size();
    int first = -1, last = -1;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == target)
        {
            if (first == -1)
            {
                first = i;
            }
            last = i;
        }
    }
    return {first, last};
    */

    /*
    // Optimal Approach 1
    auto lb = lower_bound(nums.begin(), nums.end(), target);

    if (lb == nums.end() || *lb != target)
    {
        return {-1, -1};
    }

    auto ub = upper_bound(nums.begin(), nums.end(), target);

    return {
        (int)(lb - nums.begin()),
        (int)(ub - nums.begin() - 1)};
    */

    // Optimal For Interview
    int first = firstOccurence(nums, target);
    if (first == -1)
        return {-1, -1};
    int last = lastOccurence(nums, target);
    return {first, last};
}
int main()
{
    vector<int> nums = {1};
    int target = 1;
    vector<int> ans = searchRange(nums, target);

    for (auto val : ans)
    {
        cout << val << " ";
    }

    return 0;
}