#include <bits/stdc++.h>
using namespace std;

vector<int> previousSmallerElement(vector<int> &heights)
{
    int n = heights.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}

vector<int> nextSmallerElement(vector<int> &heights)
{
    int n = heights.size();
    vector<int> ans(n, n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> pse = previousSmallerElement(heights);
    vector<int> nse = nextSmallerElement(heights);
    int maxArea = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int width = nse[i] - pse[i] - 1;

        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea(heights);
    return 0;
}