#include <bits/stdc++.h>
using namespace std;
// total count of substrings having <= k distinct elements
int atMostKDistinct(string s, int k)
{
    unordered_map<char, int> mpp;
    int n = s.length();
    int i = 0;
    int j = 0;

    int count = 0;

    while (j < n)
    {
        mpp[s[j]]++;

        while (mpp.size() > k)
        {
            // shrink window
            mpp[s[i]]--;
            if (mpp[s[i]] == 0)
            {
                mpp.erase(s[i]);
            }
            i++;
        }
        count += (j - i) + 1; // substrings ending at j
        j++;
    }
    return count;
}
int countSubstrings(string s, int k)
{
    return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
}
int main()
{
    string s = "pqpqs";
    int k = 2;
    cout << countSubstrings(s, k);
}