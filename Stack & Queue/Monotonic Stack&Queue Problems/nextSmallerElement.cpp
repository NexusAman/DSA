#include <bits/stdc++.h>
using namespace std;
/*
// Brute force approach
vector<int> nextSmallerEle(vector<int> &arr)
{
    vector<int> ans;
    bool isSmaller = false;
    //  code here
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[i])
            {
                ans.push_back(arr[j]);
                isSmaller = true;
                break;
            }
        }

        if (!isSmaller)
        {
            ans.push_back(-1);
        }
        else
        {
            isSmaller = false;
        }
    }

    return ans;
}
*/

vector<int> nextSmallerEle(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n,-1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() >= arr[i])
        {
            st.pop();
        }

        if(!st.empty()){
            ans[i] = st.top();
        }
        
        st.push(arr[i]);
    }
    return ans;
}

int main()
{
    vector<int> nums1 = {4, 8, 5, 2, 25};

    vector<int> ans = nextSmallerEle(nums1);

    for (auto val : ans)
    {
        cout << val << " ";
    }

    return 0;
}