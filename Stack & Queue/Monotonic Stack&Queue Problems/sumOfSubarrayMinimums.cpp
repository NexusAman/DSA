#include <bits/stdc++.h>
using namespace std;

// Naive approach
// int sumSubarrayMins(vector<int> &arr)
// {
//     long long ans = 0;
//     int MOD = 1e9 + 7;

//     for (int i = 0; i < arr.size(); i++)
//     {
//         for (int j = i; j < arr.size(); j++)
//         {
//             int currMin = INT_MAX;
//             for (int k = i; k <= j; k++)
//             {
//                 currMin = min(currMin, arr[k]);
//             }
//             ans = (ans + currMin) % MOD;
//         }
//     }

//     return ans;
// }

// Better approach
// int sumSubarrayMins(vector<int> &arr)
// {
//     long long ans = 0;
//     int MOD = 1e9 + 7;

//     for (int i = 0; i < arr.size(); i++)
//     {
//         int currMin = INT_MAX;
//         for (int j = i; j < arr.size(); j++)
//         {
//             currMin = min(currMin, arr[j]);

//             ans = (ans + currMin) % MOD;
//         }
//     }
//     return ans;
// }

vector<int> nextSmallerElement(vector<int> &arr)
{
    vector<int> ans(arr.size(), arr.size());
    stack<int> st;

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            ans[i] = st.top();
        }

        st.push(i);
    }

    return ans;
}

vector<int> prevSmallerElement(vector<int> &arr)
{
    vector<int> ans(arr.size(), -1);
    stack<int> st;

    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}

int sumSubarrayMins(vector<int> &arr)
{
    vector<int> nse = nextSmallerElement(arr);
    vector<int> pse = prevSmallerElement(arr);
    int MOD = 1e9 + 7;
    long long ans = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int leftChoices = i - pse[i];
        int rightChoices = nse[i] - i;

        long long totalChoices = 1LL * leftChoices * rightChoices;
        long long contribution = 1LL * arr[i] * totalChoices;

        ans = (ans + contribution) % MOD;
    }

    return ans;
}

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    vector<int> nse = nextSmallerElement(arr);
    for (auto val : nse)
    {
        cout << val << " ";
    }
    cout << endl;
    vector<int> pse = prevSmallerElement(arr);
    for (auto val : pse)
    {
        cout << val << " ";
    }
    cout << sumSubarrayMins(arr);
    return 0;
}