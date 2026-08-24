#include <bits/stdc++.h>
using namespace std;

string postfixToPrefix(string s)
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

            string con = t1 + t2 + string(1, s[i]);
            st.push(con);
        }
        i--;
    }
    return st.top();
}

int main()
{
    string exp = "+*abc";

    cout << postfixToPrefix(exp);

    return 0;
}