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
    Better Approach
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
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 0};
    int maxProd = maxProduct(nums);
    cout << "Maximum product subarray value : " << maxProd;
    return 0;
}