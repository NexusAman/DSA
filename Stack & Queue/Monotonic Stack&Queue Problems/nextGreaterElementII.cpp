#include <bits/stdc++.h>
using namespace std;

/*
// Brute force approach
vector<int> nextGreaterElements(vector<int> &nums)
{
    vector<int> ans;
    bool isGreater = false;

    for (int i = 0; i < nums.size(); i++)
    {
        int j = i + 1;
        while (j != i)
        {
            if (j >= nums.size())
            {
                j = j % nums.size();
            }

            if (nums[j] > nums[i])
            {
                ans.push_back(nums[j]);
                isGreater = true;
                break;
            }
            j++;
        }
        if (!isGreater)
        {
            ans.push_back(-1);
        }
        else if (isGreater)
        {
            isGreater = false;
        }
    }
    return ans;
}
*/

vector<int> nextGreaterElements(vector<int> &nums)
{
    stack<int> st;
    int n = nums.size();
    vector<int> ans(n, 0);

    for (int i = (2 * n - 1); i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i % n])
        {
            st.pop();
        }

        if (i < n)
        {
            ans[i] = st.empty() ? -1 : st.top();
        }

        st.push(nums[i % n]);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 1};

    vector<int> ans = nextGreaterElements(nums);

    for (auto val : ans)
    {
        cout << val << " ";
    }

    return 0;
}
