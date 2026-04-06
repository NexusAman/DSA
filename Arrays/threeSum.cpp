#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int> &nums)
{
    set<vector<int>> st;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
int main()
{
    vector nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);

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