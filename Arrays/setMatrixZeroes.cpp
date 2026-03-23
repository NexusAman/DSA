#include <bits/stdc++.h>
using namespace std;
void setZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size();            // no. of rows
    int n = matrix[0].size();         // no. of columns
    vector<vector<int>> zeroPosition; // store positions of zeros
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                cout << matrix[i][j] << " in index " << i << j;
                zeroPosition.push_back({i, j});
                cout << endl;
            }
        }
    }

    for (auto &pos : zeroPosition) // itreating through the zeroPosition matrix
    {
        int zeroRow = pos[0];    // zero position row index
        int zeroColumn = pos[1]; // zero position column index

        for (int i = 0; i < m; i++) // converting all column element to 0
        {
            matrix[i][zeroColumn] = 0;
        }

        for (int j = 0; j < n; j++) // converting all row element to 0
        {
            matrix[zeroRow][j] = 0;
        }
    }
}
int main()
{
    // vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    setZeroes(matrix);
    for (auto &row : matrix)
    {
        for (auto &val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}