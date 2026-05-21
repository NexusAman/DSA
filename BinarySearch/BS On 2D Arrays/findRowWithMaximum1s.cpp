#include <bits/stdc++.h>
using namespace std;
int rowWithMax1s(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    int maxCount = 0;
    int maxInd = -1;

    for (int i = 0; i < m; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1)
            {
                count++;
            }
        }
        if (count > maxCount)
        {
            maxCount = count;
            maxInd = i;
        }
    }
    return maxInd;
}
int main()
{
    vector<vector<int>> mat = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    cout << rowWithMax1s(mat);
    return 0;
}