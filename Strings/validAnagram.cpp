#include <bits/stdc++.h>
using namespace std;
/*
// Brute force approach
bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
    {
        return false;
    }

    unordered_map<char, int> mpp;

    for (int i = 0; i < s.length(); i++)
    {
        mpp[s[i]]++;
        mpp[t[i]]--;
    }

    for (auto it : mpp)
    {
        if (it.second != 0)
        {
            return false;
        }
    }
    return true;
}
*/

// Optimal approach
bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
    {
        return false;
    }

    int freq[26] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s = "anagram";
    string t = "nagaram";
    cout << isAnagram(s, t);
    return 0;
}