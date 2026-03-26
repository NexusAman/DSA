#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    int m = matrix.size();    // number of rows
    int n = matrix[0].size(); // number of columns

    // create a new matrix of size (n x m) for rotated result
    vector<vector<int>> rotatedMatrix(n, vector<int>(m));

    // move each element to its rotated position
    // mapping: (i, j) -> (j, m - 1 - i)
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rotatedMatrix[j][m - 1 - i] = matrix[i][j];
        }
    }

    // copy rotated matrix back to original matrix
    matrix = rotatedMatrix;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(matrix);

    // print rotated matrix
    for (auto &row : matrix)
    {
        for (auto &val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}