#include <bits/stdc++.h>
using namespace std;

int priority(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    return -1;
}

bool isRightAssociative(char ch)
{
    return ch == '^';
}

string infixToPrefix(string s)
{
    reverse(s.begin(), s.end());

    int i = 0;
    int n = s.length();
    stack<char> st;
    string ans;

    while (i < n)
    {
        if (s[i] == '(')
        {
            s[i] = ')';
        }
        else if (s[i] == ')')
        {
            s[i] = '(';
        }
        i++;
    }

    i = 0;
    while (i < n)
    {
        if (isalnum(s[i]))
        {
            ans += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && st.top() != '(' && (priority(st.top()) > priority(s[i]) || (priority(st.top()) == priority(s[i]) && isRightAssociative(s[i]))))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    string exp = "a*(b+c)/d";

    cout << infixToPrefix(exp);
    return 0;
}