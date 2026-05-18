#include <bits/stdc++.h>
using namespace std;
vector<int> merge(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size();
    int n = nums2.size();
    int left = 0;
    int right = 0;
    vector<int> mergedArray;
    while (left < m && right < n)
    {
        if (nums1[left] <= nums2[right])
        {
            mergedArray.push_back(nums1[left]);
            left++;
        }
        else
        {
            mergedArray.push_back(nums2[right]);
            right++;
        }
    }

    while (left < m)
    {
        mergedArray.push_back(nums1[left]);
        left++;
    }

    while (right < n)
    {
        mergedArray.push_back(nums2[right]);
        right++;
    }

    return mergedArray;
}
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> mergedArray = merge(nums1, nums2);
    int n = mergedArray.size();
    double median = 0;

    if (n % 2 == 0)
    {
        median = (double)(mergedArray[n / 2 - 1] + mergedArray[n / 2]) / 2;
    }
    else
    {
        median = mergedArray[n / 2];
    }
    return median;
}
int main()
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    cout << findMedianSortedArrays(nums1, nums2);
    return 0;
}