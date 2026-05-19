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

/*
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
*/

// Optimal approach
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();

    if (n1 > n2)
        return findMedianSortedArrays(nums2, nums1);

    int low = 0, high = n1;
    int left = (n1 + n2 + 1) / 2;
    int n = n1 + n2;

    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1)
            r1 = nums1[mid1];
        if (mid2 < n2)
            r2 = nums2[mid2];

        if (mid1 - 1 >= 0)
            l1 = nums1[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = nums2[mid2 - 1];
        if (l1 <= r2 && l2 <= r1)
        {
            if (n % 2 == 1)
                return max(l1, l2);
            return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else if (l1 > r2)
        {
            high = mid1 - 1;
        }
        else
        {
            low = mid1 + 1;
        }
    }
    return 0;
}
int main()
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    cout << findMedianSortedArrays(nums1, nums2);
    return 0;
}