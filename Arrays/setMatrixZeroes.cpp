#include <bits/stdc++.h>
using namespace std;
void setZeroes(vector<vector<int>> &matrix)
{

    /*
    // Brute Force
    int m = matrix.size();    // number of rows
    int n = matrix[0].size(); // number of columns

    // Store positions (i, j) of all zero elements found in the matrix
    vector<vector<int>> zeroPosition;

    // 🔹 First Pass: Traverse the matrix and record positions of zeros
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                zeroPosition.push_back({i, j}); // store zero position
            }
        }
    }

    // 🔹 Second Pass: For each stored zero position, update its entire row and column
    for (auto &pos : zeroPosition) // iterate through all zero positions
    {
        int zeroRow = pos[0];    // row index of zero
        int zeroColumn = pos[1]; // column index of zero

        // Set entire column to zero
        for (int i = 0; i < m; i++)
        {
            matrix[i][zeroColumn] = 0;
        }

        // Set entire row to zero
        for (int j = 0; j < n; j++)
        {
            matrix[zeroRow][j] = 0;
        }
    }
    */

    /*
    // Better Approach
    int m = matrix.size();    // number of rows
    int n = matrix[0].size(); // number of columns

    // Arrays to mark which rows and columns should be set to zero
    vector<int> rows(m, 0); // rows[i] = 1 → entire row i should be zero
    vector<int> cols(n, 0); // cols[j] = 1 → entire column j should be zero

    // 🔹 First Pass: Identify all rows and columns that contain at least one zero
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                rows[i] = 1; // mark this row
                cols[j] = 1; // mark this column
            }
        }
    }

    // 🔹 Second Pass: Update matrix based on marked rows and columns
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // If either the row or column is marked, set the cell to zero
            if (rows[i] == 1 || cols[j] == 1)
            {
                matrix[i][j] = 0;
            }
        }
    }
    */

    // Optimal Approach
    int m = matrix.size();    // number of rows
    int n = matrix[0].size(); // number of columns

    bool firstRowZero = false; // flag for first row
    bool firstColZero = false; // flag for first column

    // 🔹 Step 1: Check if first row has any zero
    for (int j = 0; j < n; j++)
    {
        if (matrix[0][j] == 0)
        {
            firstRowZero = true;
            break;
        }
    }

    // 🔹 Step 2: Check if first column has any zero
    for (int i = 0; i < m; i++)
    {
        if (matrix[i][0] == 0)
        {
            firstColZero = true;
            break;
        }
    }

    // 🔹 Step 3: Use first row and column as markers
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0; // mark row
                matrix[0][j] = 0; // mark column
            }
        }
    }

    // 🔹 Step 4: Apply changes based on markers (excluding first row/col)
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // 🔹 Step 5: Update first row if needed
    if (firstRowZero)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[0][j] = 0;
        }
    }

    // 🔹 Step 6: Update first column if needed
    if (firstColZero)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[i][0] = 0;
        }
    }
}
int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    // vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
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