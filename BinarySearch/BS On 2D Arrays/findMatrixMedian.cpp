#include <bits/stdc++.h>
using namespace std;
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
int main()
{
    vector<vector<int>> matrix = {{1, 4, 9}, {2, 5, 6}, {3, 7, 8}};
    cout << findMedian(matrix);
    return 0;
}