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
// Better approach
bool binarySearch(vector<vector<int>> &matrix, int target, int low, int high, int row)
{
    while (low <= high)
    {

        int mid = low + (high - low) / 2;

        if (matrix[row][mid] == target)
        {
            return true;
        }
        else if (matrix[row][mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
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
        int low = 0, high = n - 1;
        if (binarySearch(matrix, target, low, high, i))
        {
            return true;
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
    int row = 0, col = n - 1;

    while (row < m && col >= 0)
    {
        if (matrix[row][col] == target)
        {
            return true;
        }
        else if (matrix[row][col] < target)
        {
            row++;
        }
        else
        {
            col--;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15},
                                  {2, 5, 8, 12, 19},
                                  {3, 6, 9, 16, 22},
                                  {10, 13, 14, 17, 24},
                                  {18, 21, 23, 26, 30}};
    int target = 5;
    cout << searchMatrix(matrix, target);
}