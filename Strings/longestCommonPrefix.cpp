#include <bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string> &strs)
{
    string res = "";
    for (int i = 0; i < strs[0].length(); i++)
    {
        for (int j = 1; j < strs.size(); j++)
        {
            if (i >= strs[j].length() || strs[j][i] != strs[0][i])
            {
                return res;
            }
        }
        res += strs[0][i];
    }
    return res;
}
int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    string res = longestCommonPrefix(strs);
    cout << res;
    return 0;
}