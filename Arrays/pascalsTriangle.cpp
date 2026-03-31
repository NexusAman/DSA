#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> result(numRows);
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                result[i].push_back(1);
            }
            else
            {
                int currentSum = result[i - 1][j - 1] + result[i - 1][j];
                result[i].push_back(currentSum);
            }
        }
    }

    return result;
}
int main()
{
    int numRows = 5;
    vector<vector<int>> result = generate(numRows);

    // for (int i = 0; i < result.size(); i++)
    // {
    //     for (int j = 0; j < result[i].size(); j++)
    //     {
    //         cout << result[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (auto row : result)
    {
        for (auto val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}