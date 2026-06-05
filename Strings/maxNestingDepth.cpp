#include <bits/stdc++.h>
using namespace std;
int maxDepth(string s)
{
    int n = s.length();
    int count = 0;
    int maxCount = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            count++;
        }
        else if (s[i] == ')')
        {
            if (count > maxCount)
            {
                maxCount = count;
            }
            count--;
        }
    }
    return maxCount;
}
int main()
{
    string s = "(1+(2*3)+((8)/4))+1";
    cout << maxDepth(s);
    return 0;
}