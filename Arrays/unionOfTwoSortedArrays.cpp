#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b)
{
    /*
    // Using map
    unordered_map<int, int> mpp;
    vector<int> ans;

    for (int i = 0; i < a.size(); i++)
    {
        mpp[a[i]]++;
    }

    for (int i = 0; i < b.size(); i++)
    {
        mpp[b[i]]++;
    }

    for (auto val : mpp)
    {
        ans.push_back(val.first);
    }

    sort(ans.begin(), ans.end());

    return ans;
    */

    /*
    //Using Set
    unordered_set<int> st;

    for (int i = 0; i < a.size(); i++)
    {
        st.insert(a[i]);
    }

    for (int i = 0; i < b.size(); i++)
    {
        st.insert(b[i]);
    }

    vector<int> ans(st.begin(), st.end());
    sort(ans.begin(), ans.end());

    return ans;
    */

    // Two Pointers
    int i = 0;
    int j = 0;
    vector<int> ans;

    while (i < a.size() && j < b.size())
    {
        if (a[i] <= b[j])
        {
            if (ans.empty() || ans.back() != a[i])
            {
                ans.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if (ans.empty() || ans.back() != b[j])
            {
                ans.push_back(b[j]);
            }
            j++;
        }
    }

    while (i < a.size())
    {
        if (ans.empty() || ans.back() != a[i])
        {
            ans.push_back(a[i]);
        }
        i++;
    }

    while (j < b.size())
    {
        if (ans.empty() || ans.back() != b[j])
        {
            ans.push_back(b[j]);
        }
        j++;
    }

    return ans;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {1, 1, 2, 3, 4};
    vector<int> result = findUnion(a, b);

    for (auto val : result)
    {
        cout << val << " ";
    }

    return 0;
}