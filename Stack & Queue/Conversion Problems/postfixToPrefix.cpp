#include <bits/stdc++.h>
using namespace std;

string postfixToPrefix(string s)
{
    int i = 0;
    int n = s.length();
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

            string con = string(1, s[i]) + t2 + t1;
            st.push(con);
        }
        i++;
    }
    return st.top();
}

int main()
{
    string exp = "ab*c+";

    cout << postfixToPrefix(exp);

    return 0;
}