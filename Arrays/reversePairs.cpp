#include <bits/stdc++.h>
using namespace std;
/*
int reversePairs(vector<int> &nums)
{
    Brute Force Approach
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] > 2 * nums[j])
            {
                count++;
            }
        }
    }
    return count;
}
*/

// Optimal Approach
void merge(vector<int> &nums, int low, int mid, int high)
{
    vector<int> temp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (nums[left] <= nums[right])
        {
            temp.push_back(nums[left]);
            left++;
        }
        else
        {
            temp.push_back(nums[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(nums[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(nums[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        nums[i] = temp[i - low];
    }
}
int countPairs(vector<int> &nums, int low, int mid, int high)
{
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && nums[i] > 2 * nums[right])
            right++;
        cnt = cnt + (right - (mid + 1));
    }
    return cnt;
}
int mergeSort(vector<int> &nums, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort(nums, low, mid);
    cnt += mergeSort(nums, mid + 1, high);
    cnt += countPairs(nums, low, mid, high);
    merge(nums, low, mid, high);
    return cnt;
}
int reversePairs(vector<int> &nums)
{
    int n = nums.size();
    int count = mergeSort(nums, 0, n - 1);
    return count;
}
int main()
{
    vector<int> nums = {1, 3, 2, 3, 1};
    int n = nums.size();
    int count = reversePairs(nums);
    cout << format("Reverse pairs exists in nums array : {}", count);
}