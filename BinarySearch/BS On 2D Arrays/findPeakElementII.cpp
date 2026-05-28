#include <bits/stdc++.h>
using namespace std;
/*
/ Brute force approach
vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int left = (j > 0) ? mat[i][j - 1] : -1;
            int right = (j < n - 1) ? mat[i][j + 1] : -1;
            int top = (i > 0) ? mat[i - 1][j] : -1;
            int bottom = (i < m - 1) ? mat[i + 1][j] : -1;

            if (mat[i][j] > left && mat[i][j] > right && mat[i][j] > top && mat[i][j] > bottom)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}
*/

// Optimal approach
int maxElement(vector<vector<int>> &mat, int col)
{
    int m = mat.size();
    int maxValue = -1;
    int maxIndex = -1;

    for (int i = 0; i < m; i++)
    {
        if (mat[i][col] > maxValue)
        {
            maxValue = mat[i][col];
            maxIndex = i;
        }
    }
    return maxIndex;
}
vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();

    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int row = maxElement(mat, mid);
        int left = (mid - 1) >= 0 ? mat[row][mid - 1] : -1;
        int right = (mid + 1) < n ? mat[row][mid + 1] : -1;

        if (mat[row][mid] > left && mat[row][mid] > right)
        {
            return {row, mid};
        }
        else if (mat[row][mid] < left)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return {-1, -1};
}
int main()
{
    vector<vector<int>> mat = {{1, 4}, {3, 2}};
    vector<int> result = findPeakGrid(mat);

    for (auto &row : result)
    {
        cout << row << " ";
    }
    return 0;
}