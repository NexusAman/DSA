#include <bits/stdc++.h>
using namespace std;
/*
//Brute force approach
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}
*/

/*
// Better approach(by self)
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++)
    {
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (matrix[i][mid] == target)
            {
                return true;
            }
            else if (matrix[i][mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    return false;
}
*/

/*
// Better approach
bool binarySearch(vector<vector<int>> &matrix, int low, int high, int target, int row)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (matrix[row][mid] == target)
        {
            return true;
        }
        else if (matrix[row][mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return false;
}
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++)
    {
        if (matrix[i][0] <= target && target <= matrix[i][n - 1])
        {
            return binarySearch(matrix, 0, n - 1, target, i);
        }
    }
    return false;
}
*/

// Optimal approach
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();

    int low = 0, high = m * n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int row = mid / n, col = mid % n;

        if (matrix[row][col] == target)
        {
            return true;
        }
        else if (matrix[row][col] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;
    cout << searchMatrix(matrix, target);
    return 0;
}