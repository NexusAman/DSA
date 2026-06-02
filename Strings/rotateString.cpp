#include <bits/stdc++.h>
using namespace std;
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
int main()
{
    string s = "abcde";
    string goal = "cdeab";
    cout << rotateString(s, goal);
    return 0;
}