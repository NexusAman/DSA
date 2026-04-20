#include <bits/stdc++.h>
using namespace std;
int maxProduct(vector<int> &nums)
{
    /*
    //Brute Force
    int n = nums.size();
    int maxProductValue = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int product = 1;
            for (int k = i; k <= j; k++)
            {
                product = product * nums[k];
            }
            maxProductValue = max(maxProductValue, product);
        }
    }
    return maxProductValue;
    */

    /*
    // Better Approach
    int n = nums.size();
    int maxProd = nums[0];

    for (int i = 0; i < n; i++)
    {
        int prod = 1;
        for (int j = i; j < n; j++)
        {
            prod *= nums[j];
            maxProd = max(maxProd, prod);
        }
    }
    return maxProd;
    */

    // Optimal Approach
    int n = nums.size();

    int pre = 1, suff = 1;
    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (pre == 0)
            pre = 1;
        if (suff == 0)
            suff = 1;

        pre *= nums[i];
        suff *= nums[n - i - 1];

        ans = max(ans, max(pre, suff));
    }

    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 0};
    int maxProd = maxProduct(nums);
    cout << "Maximum product subarray value : " << maxProd;
    return 0;
}