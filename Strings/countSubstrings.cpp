#include <bits/stdc++.h>
using namespace std;
int countSubstrings(string s, int k)
{
    int n = s.length();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            string substring = "";
            for (int k = i; k <= j; k++)
            {
                substring += s[k];
            }
        }
    }
    return count;
}
int main()
{
    string s = "pqpqs";
    int k = 2;
    cout << countSubstrings(s, k);
}