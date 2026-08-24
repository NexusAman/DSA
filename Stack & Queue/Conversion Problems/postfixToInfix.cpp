#include <bits/stdc++.h>
using namespace std;

string postfixToInfix(string s)
{
    int n = s.length();
    int i = 0;
    stack<string> st;

    while (i < n)
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
            string con = "(" + t2 + s[i] + t1 + ")";
            st.push(con);
        }
        i++;
    }
    return st.top();
}

int main()
{
    string exp = "ab*c+";

    cout << postfixToInfix(exp);

    return 0;
}