#include <bits/stdc++.h>
using namespace std;


string prefixToInfix(string s)
{
    int n = s.length();
    int i = n - 1;
    stack<string> st;

    while (i >= 0)
    {
        if (isalnum(s[i]))
        {
            st.push(string(1, s[i]));
        }
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string con = "(" + t1 + s[i] + t2 + ")";
            st.push(con);
        }
        i--;
    }
    return st.top();
}

int main()
{
    string exp = "+A*BC";

    cout << prefixToInfix(exp);

    return 0;
}