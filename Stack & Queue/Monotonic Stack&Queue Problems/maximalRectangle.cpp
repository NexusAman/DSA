#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmallerElement(vector<int> &heights)
{
    int n = heights.size();
    vector<int> pse(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            pse[i] = st.top();
        }

        st.push(i);
    }
    return pse;
}

vector<int> nextSmallerElement(vector<int> &heights)
{
    int n = heights.size();
    vector<int> nse(n, n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            nse[i] = st.top();
        }

        st.push(i);
    }
    return nse;
}

int largestRectangleArea(vector<int> &heights)
{
    vector<int> nse = nextSmallerElement(heights);
    vector<int> pse = prevSmallerElement(heights);
    int maxArea = INT_MIN;

    for (int i = 0; i < heights.size(); i++)
    {
        int width = nse[i] - pse[i] - 1;
        int area = heights[i] * width;
        maxArea = max(area, maxArea);
    }
    return maxArea;
}

vector<vector<int>> prefixSumMatrix(vector<vector<char>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> preSum(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == '1')
            {
                if (i == 0)
                {
                    preSum[i][j] = 1;
                }
                else
                {
                    preSum[i][j] = preSum[i - 1][j] + 1;
                }
            }
            else
            {
                preSum[i][j] = 0;
            }
        }
    }
    return preSum;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    int m = matrix.size();
    int maxArea = INT_MIN;
    vector<vector<int>> preSum = prefixSumMatrix(matrix);

    for (int i = 0; i < m; i++)
    {
        int area = largestRectangleArea(preSum[i]);
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main()
{
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    cout << maximalRectangle(matrix);
    return 0;
}