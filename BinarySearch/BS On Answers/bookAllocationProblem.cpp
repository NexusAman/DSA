#include <bits/stdc++.h>
using namespace std;
/*
//Brute force apporach
int countStudents(vector<int> &nums, int pages)
{
    int n = nums.size();
    int students = 1;
    int pagesStudent = 0;

    for (int i = 0; i < n; i++)
    {
        if ((pagesStudent + nums[i]) <= pages)
        {
            pagesStudent += nums[i];
        }
        else
        {
            students++;
            pagesStudent = nums[i];
        }
    }
    return students;
}
int findPages(vector<int> &nums, int m)
{
    int n = nums.size();
    if (m > n)
    {
        return -1;
    }

    int low = *max_element(nums.begin(), nums.end());
    long long high = accumulate(nums.begin(), nums.end(), 0);

    for (int i = low; i <= high; i++)
    {
        if (countStudents(nums, i) <= m)
        {
            return i;
        }
    }
    return -1;
}
*/

// Optimal Approach
int countStudents(vector<int> &nums, int pages)
{
    int n = nums.size();
    int students = 1;
    int pagesCount = 0;

    for (int i = 0; i < n; i++)
    {
        if ((pagesCount + nums[i]) <= pages)
        {
            pagesCount += nums[i];
        }
        else
        {
            students++;
            pagesCount = nums[i];
        }
    }
    return students;
}
int findPages(vector<int> &nums, int m)
{
    int n = nums.size();
    if (m > n)
    {
        return -1;
    }

    int low = *max_element(nums.begin(), nums.end());
    long long high = accumulate(nums.begin(), nums.end(), 0);
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (countStudents(nums, mid) <= m)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {12, 34, 67, 90};
    int m = 2;
    cout << findPages(nums, m);
    return 0;
}