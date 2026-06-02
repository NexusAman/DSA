#include <bits/stdc++.h>
using namespace std;
/*
// Brute force approach
bool rotateString(string s, string goal)
{
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        rotate(s.begin(), s.begin() + 1, s.end());
        if (s == goal)
        {
            return true;
        }
    }
    return false;
}
*/

// Optimal approach
bool rotateString(string s, string goal)
{
    if (goal.length() != s.length())
    {
        return false;
    }

    string concatString = s + s;

    if (concatString.find(goal) != string::npos)
    {
        return true;
    }
    return false;
}
int main()
{
    string s = "abcde";
    string goal = "cdeab";
    cout << rotateString(s, goal);
    return 0;
}