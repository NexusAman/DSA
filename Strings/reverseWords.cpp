#include <bits/stdc++.h>
using namespace std;

/*
//Brute force approach
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
*/

// Optimal approach
string reverseWords(string s)
{
    reverse(s.begin(), s.end());
    int i = 0;
    int l = 0, r = 0;
    int n = s.length();

    while (i < n)
    {
        while (i < n && s[i] != ' ')
        {
            s[r++] = s[i++];
        }

        if (l < r)
        {
            reverse(s.begin() + l, s.begin() + r);
            s[r++] = ' ';
            l = r;
        }
        i++;
    }
    s = s.substr(0, r - 1);
    return s;
}
int main()
{
    string s = "the sky is blue";

    string res = reverseWords(s);
    cout << res;

    return 0;
}