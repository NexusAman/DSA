#include <bits/stdc++.h>
using namespace std;
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> spiralOrders;

    int top = 0;
    int bottom = m - 1;
    int left = 0;
    int right = n - 1;

    while (top <= bottom && left <= right)
    {
        // Top row
        for (int i = left; i <= right; i++)
        {
            spiralOrders.push_back(matrix[top][i]);
        }
        top++;

        // Right Column
        for (int i = top; i <= bottom; i++)
        {
            spiralOrders.push_back(matrix[i][right]);
        }
        right--;

        // Bottom row
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                spiralOrders.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // Left Column
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                spiralOrders.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return spiralOrders;
}
int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> result = spiralOrder(matrix);

    for (auto &val : result)
    {
        cout << val << " ";
    }
}