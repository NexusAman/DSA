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

string infixToPostfix(string s)
{
    int n = s.length();
    int i = 0;
    stack<char> st;
    string ans;

    while (i < n)
    {
        // operands
        if (isalnum(s[i]))
        {
            ans += s[i];
        }
        else if (s[i] == '(') // opening parenthesis
        {
            st.push(s[i]);
        }
        else if (s[i] == ')') // closing parenthesis
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
        else // operator
        {
            while (!st.empty() && st.top() != '(' && (priority(st.top()) > priority(s[i]) || (priority(st.top()) == priority(s[i]) && !isRightAssociative(s[i]))))
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
    return ans;
}

int main()
{
    string expression = "a+b*(c^d-e)";

    // cout << "Enter infix expression to convert it in postfix: ";
    // cin >> expression;

    string ans = infixToPostfix(expression);

    cout << "Infix expression: " << expression << endl;
    cout << "Postfix expression: " << ans;

    return 0;
}