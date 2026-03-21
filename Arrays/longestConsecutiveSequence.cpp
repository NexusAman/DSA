#include <bits/stdc++.h>
using namespace std;
int longestConsecutive(vector<int> &nums)
{
    // Better Approach
    int n = nums.size();
    if (n == 0)
        return 0;
    int count = 1;
    int maxSequence = 1;

    sort(nums.begin(), nums.end());

    for (int i = 1; i < n; i++)
    {
        int current = nums[i - 1];
        int next = nums[i];

        if (next == current)
        {
            continue;
        }
        else if (next == current + 1)
        {
            count++;
        }
        else
        {
            count = 1;
        }

        maxSequence = max(maxSequence, count);
    }

    return maxSequence;
}

int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums);
    return 0;
}