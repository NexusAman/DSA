#include <bits/stdc++.h>
using namespace std;

// vector<int> maxSlidingWindow(vector<int> &nums, int k)
// {
//     int i = 0;
//     int j = i+k-1;
//     int maxElement = INT_MIN;
//     vector<int> ans;

//     while (j < nums.size())
//     {
//         maxElement = *max_element(nums.begin() + i, nums.begin() + j+1);
//         ans.push_back(maxElement);
//         i++;
//         j++;
//     }
//     return ans;
// }

/*
// Brute force approach
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int i = 0;
    int j = i + k - 1;
    vector<int> ans;

    while (j < nums.size())
    {
        int maxElement = INT_MIN;
        for (int k = i; k <= j; k++)
        {
            if (maxElement < nums[k])
            {
                maxElement = nums[k];
            }
        }

        ans.push_back(maxElement);
        i++;
        j++;
    }
    return ans;
}
*/

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();
    deque<int> deq;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        while (!deq.empty() && deq.front() <= i - k)
        {
            deq.pop_front();
        }

        while (!deq.empty() && nums[i] > nums[deq.back()])
        {
            deq.pop_back();
        }

        deq.push_back(i);

        if (i >= k - 1)
        {
            ans.push_back(nums[deq.front()]);
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(nums, k);

    for (auto val : ans)
    {
        cout << val << " ";
    }

    return 0;
}