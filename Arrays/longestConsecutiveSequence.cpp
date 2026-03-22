#include <bits/stdc++.h>
using namespace std;

bool linearSearch(int element, vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == element)
        {
            return true;
        }
    }
    return false;
}

int longestConsecutive(vector<int> &nums)
{
    /*
    // Brute Force
    if(nums.empty()) return 0;
    int maxSequence = 1;
    int element;

    for (int i = 0; i < nums.size(); i++)
    {
        element = nums[i];
        int count = 1;

        while (linearSearch(element + 1, nums))
        {
            element += 1;
            count++;
        }
        maxSequence = max(maxSequence, count);
    }

    return maxSequence;
    */

    /*
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
    */

    // Optimal Approach
    if (nums.empty())
        return 0;
    unordered_set<int> st(nums.begin(), nums.end()); // O(n)
    int maxSequence = 1;

    for (const auto &num : st) // O(n)
    {
        // inner loop O(n) because it skips element if it is not the first element of the sequence
        if (st.find(num - 1) == st.end())
        {
            int current = num;
            int count = 1;

            while (st.find(current + 1) != st.end()) // O(n)
            {
                count++;
                current++;
            }
            maxSequence = max(maxSequence, count);
        }
    }

    return maxSequence;
}

int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2, 5};
    cout << longestConsecutive(nums);
    return 0;
}