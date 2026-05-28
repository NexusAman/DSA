#include <bits/stdc++.h>
using namespace std;
/*
// Brute force approach
int findMedian(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> temp;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(matrix[i][j]);
        }
    }

    sort(temp.begin(), temp.end());

    int length = temp.size();

    int median = length / 2;

    return temp[median];
}
*/

// Optimal approach
int countSmallEquals(vector<vector<int>> &matrix, int x)
{
    int count = 0;
    int m = matrix.size();

    for (int i = 0; i < m; i++)
    {
        count += upper_bound(matrix[i].begin(), matrix[i].end(), x) - matrix[i].begin();
    }
    return count;
}
int findMedian(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    int low = INT_MAX, high = INT_MIN;

    for (int i = 0; i < m; i++)
    {
        low = min(matrix[i][0], low);
        high = max(matrix[i][n - 1], high);
    }

    int req = (m * n) / 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        int smallEqual = countSmallEquals(matrix, mid);

        if (smallEqual <= req)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}
int main()
{
    vector<vector<int>> matrix = {{1, 4, 9}, {2, 5, 6}, {3, 7, 8}};
    cout << findMedian(matrix);
    return 0;
}