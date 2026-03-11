#include <bits/stdc++.h>
using namespace std;

// Brute Force
/*
void unionOfSortedArrays(vector<int> nums1, vector<int> nums2)
{
    set<int> unionSet;

    for (int i = 0; i < nums1.size(); i++)
    {
        unionSet.insert(nums1[i]);
    }
    for (int i = 0; i < nums2.size(); i++)
    {
        unionSet.insert(nums2[i]);
    }

    for (auto &val : unionSet)
    {
        cout << val << " ";
    }
}
*/

// Optimal Approach
vector<int> unionOfSortedArrays(vector<int> nums1, vector<int> nums2)
{
    int n = nums1.size();
    int m = nums2.size();

    // 1,2,3,4,5
    // 2,3,4,4,5
    // 1 2 3 4 5
    int i = 0, j = 0;
    vector<int> result;
    while (i < n && j < m)
    {
        if (nums1[i] <= nums2[j])
        {
            if (result.empty() || result.back() != nums1[i])
            {
                result.push_back(nums1[i]);
            }
            i++;
        }
        else
        {
            if (result.empty() || result.back() != nums2[j])
            {
                result.push_back(nums2[j]);
            }
            j++;
        }
    }

    while (i < n)
    {
        if (result.empty() || result.back() != nums1[i])
        {
            result.push_back(nums1[i]);
        }
        i++;
    }

    while (j < m)
    {
        if (result.empty() || result.back() != nums2[j])
        {
            result.push_back(nums2[j]);
        }
        j++;
    }

    return result;
}
int main()
{
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {2, 3, 4, 4, 5};
    vector<int> result = unionOfSortedArrays(nums1, nums2);

    for (auto &val : result)
    {
        cout << val << " ";
    }
    return 0;
}