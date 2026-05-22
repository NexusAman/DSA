#include <bits/stdc++.h>
using namespace std;
/*
//Brute force approach
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
*/

// Optimal approach
int rowWithMax1s(vector<vector<int>> &mat)
{
    int cnt_max = 0;
    int index = -1;
    int n = mat.size();
    int m = mat[0].size();
    for (int i = 0; i < n; i++)
    {
        int first_one_index = lower_bound(mat[i].begin(), mat[i].end(), 1) - mat[i].begin();
        int cnt_ones = m - first_one_index;
        if (cnt_ones > cnt_max)
        {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}
int main()
{
    vector<vector<int>> mat = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    cout << rowWithMax1s(mat);
    return 0;
}