#include <bits/stdc++.h>
using namespace std;
int singleNonDuplicate(vector<int> &nums)
{

    // Brute Force 1
    int n = nums.size();

    // if array contains one element
    if (n == 1)
        return nums[0];

    for (int i = 0; i < n - 1; i += 2)
    {
        // checks the next element is equal or not
        if (nums[i] != nums[i + 1])
        {
            return nums[i];
        }
    }

    return nums[n - 1]; // if last element is unique

    /*
    // Brute Force 2
    int n = nums.size();
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans ^= nums[i];
    }
    return ans;
    */
}
int main()
{
    vector<int> nums = {3, 3, 7, 7, 10, 11, 11};
    cout << singleNonDuplicate(nums);
    return 0;
}