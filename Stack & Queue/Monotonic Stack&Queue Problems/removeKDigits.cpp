#include <bits/stdc++.h>
using namespace std;
string removeKdigits(string num, int k)
{
    int n = num.length();

    if (k == n)
        return "0";

    stack<char> st;

    for (int i = 0; i < n; i++)
    {

        while (!st.empty() && k > 0 && st.top() > num[i])
        {
            st.pop();
            k--;
        }

        st.push(num[i]);
    }

    // If k is still remaining
    while (!st.empty() && k > 0)
    {
        st.pop();
        k--;
    }

    string ans = "";

    // Stack gives reverse order
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    // Remove leading zeros
    int i = 0;
    while (i < ans.length() && ans[i] == '0')
    {
        i++;
    }

    ans = ans.substr(i);

    return ans.empty() ? "0" : ans;
}

int main()
{
    string num = "1432219";
    int k = 3;
    cout << removeKdigits(num, k);
    return 0;
}