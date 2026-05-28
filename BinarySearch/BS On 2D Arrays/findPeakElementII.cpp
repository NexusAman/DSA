#include <bits/stdc++.h>
using namespace std;
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