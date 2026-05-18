#include <bits/stdc++.h>
using namespace std;
/*
//Brute force approach
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
*/

// Better approach
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();

    int n = n1 + n2;

    int ind1 = n / 2;
    int ind2 = n / 2 - 1;

    int ind1el = -1;
    int ind2el = -1;

    int cnt = 0;
    int left = 0, right = 0;

    while (left < n1 && right < n2)
    {
        int currentElement;

        if (nums1[left] <= nums2[right])
        {
            currentElement = nums1[left];
            left++;
        }
        else
        {
            currentElement = nums2[right];
            right++;
        }

        if (cnt == ind1)
            ind1el = currentElement;

        if (cnt == ind2)
            ind2el = currentElement;

        cnt++;
    }

    while (left < n1)
    {
        int currentElement = nums1[left];

        if (cnt == ind1)
            ind1el = currentElement;

        if (cnt == ind2)
            ind2el = currentElement;

        cnt++;
        left++;
    }

    while (right < n2)
    {
        int currentElement = nums2[right];

        if (cnt == ind1)
            ind1el = currentElement;

        if (cnt == ind2)
            ind2el = currentElement;

        cnt++;
        right++;
    }

    if (n % 2 == 1)
        return ind1el;

    return (double)(ind1el + ind2el) / 2;
}

int main()
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    cout << findMedianSortedArrays(nums1, nums2);
    return 0;
}