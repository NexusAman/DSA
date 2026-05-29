#include <bits/stdc++.h>
using namespace std;
string removeOuterParentheses(string s)
{
    int count = 0;
    string result;

    for (char ch : s)
    {
        if (ch == '(')
        {
            if (count > 0)
            {
                result.push_back(ch);
            }
            count++;
        }
        else
        {
            count--;

            if (count > 0)
            {
                result.push_back(ch);
            }
        }
    }

    return result;
}
int main()
{
    string s = "(()())(())";
    string result = removeOuterParentheses(s);
    cout << result;
    return 0;
}