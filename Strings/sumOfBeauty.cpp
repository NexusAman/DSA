#include <bits/stdc++.h>
using namespace std;
/*
// Brute force approach
int beautySum(string s)
{
    int n = s.length();
    int beautySum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            unordered_map<char, int> freq;
            int beauty = 0;

            for (int k = i; k <= j; k++)
            {
                freq[s[k]]++;
            }

            int maxFreq = INT_MIN;
            for (auto it : freq)
            {
                maxFreq = max(maxFreq, it.second);
            }

            int minFreq = INT_MAX;
            for (auto it : freq)
            {
                minFreq = min(minFreq, it.second);
            }

            beauty = maxFreq - minFreq;

            if (beauty > 0)
            {
                beautySum += beauty;
            }
        }
    }
    return beautySum;
}
*/

// Optimal approach
int beautySum(string s)
{
    int n = s.length();
    int beautySum = 0;

    for (int i = 0; i < n; i++)
    {
        vector<int> freq(26, 0);
        for (int j = i; j < n; j++)
        {
            freq[s[j] - 'a']++;

            int maxFreq = 0;
            for (int k = 0; k < 26; k++)
            {
                maxFreq = max(maxFreq, freq[k]);
            }

            int minFreq = INT_MAX;
            for (int l = 0; l < 26; l++)
            {
                if (freq[l] != 0)
                {
                    minFreq = min(minFreq, freq[l]);
                }
            }

            int beauty = maxFreq - minFreq;

            beautySum += beauty;
        }
    }
    return beautySum;
}
int main()
{
    string s = "aabcb";
    cout << beautySum(s);
    return 0;
}