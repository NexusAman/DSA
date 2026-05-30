#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    vector<string> words;
    string temp = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            temp.push_back(s[i]);
        }
        else
        {
            // Push only if temp is not empty
            if (!temp.empty())
            {
                words.push_back(temp);
                temp = "";
            }
        }
    }

    // Handle last word
    if (!temp.empty())
    {
        words.push_back(temp);
    }

    string result = "";
    int n = words.size();

    // Traverse from back
    for (int i = n - 1; i >= 0; i--)
    {
        result += words[i];

        // Add space except after last word
        if (i != 0)
        {
            result += ' ';
        }
    }

    return result;
}

int main()
{
    string s = "  hello   world  ";

    string res = reverseWords(s);
    cout << res;

    return 0;
}