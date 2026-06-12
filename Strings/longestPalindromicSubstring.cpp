#include <bits/stdc++.h>
using namespace std;
/*
string longestPalindrome(string s)
{
    //Brute force approach
    int l = s.length();
    string longestSubstring = "";
    int longestSubstringLength = 0;

    for (int i = 0; i < l; i++)
    {
        for (int j = i; j < l; j++)
        {
            string substring = "";
            for (int k = i; k <= j; k++)
            {
                substring += s[k];
            }

            int substringLength = substring.length();
            if (substringLength > longestSubstringLength)
            {
                string reversedSubstring = "";

                for (int i = substringLength - 1; i >= 0; i--)
                {
                    reversedSubstring += substring[i];
                }

                if (substring == reversedSubstring && substringLength > longestSubstringLength)
                {
                    longestSubstring = substring;
                    longestSubstringLength = substringLength;
                }
            }
        }
    }
    return longestSubstring;
}
*/

/*
// Better approach
bool isPalindrome(int left, int right, string &s)
{
    while (left < right)
    {
        if (s[left] == s[right])
        {
            left++;
            right--;
        }
        else
        {
            return false;
        }
    }
    return true;
}
string longestPalindrome(string s)
{
    int l = s.length();
    int longestSubstringLength = 0;
    int startIndex = -1;
    string longestSubstring = "";

    for (int i = 0; i < l; i++)
    {
        for (int j = i; j < l; j++)
        {
            if (isPalindrome(i, j, s))
            {
                int substringLength = j - i + 1;
                if (substringLength > longestSubstringLength)
                {
                    longestSubstringLength = substringLength;
                    startIndex = i;
                }
            }
        }
    }

    longestSubstring = s.substr(startIndex, longestSubstringLength);
    return longestSubstring;
}
*/

// Optimal approach
string longestPalindrome(string s)
{
    string LPS = s.substr(0, 1);

    for (int i = 1; i < s.length(); i++)
    {
        // consider odd length
        int low = i;
        int high = i;

        // checking palindrome
        while (low >= 0 && high < s.length() && s[low] == s[high])
        {
            low--;
            high++;
        }

        // extracting substring
        string palindrome = s.substr(low + 1, high - low - 1);
        if (palindrome.length() > LPS.length())
        {
            LPS = palindrome;
        }

        // consider even length
        low = i - 1;
        high = i;

        while (low >= 0 && high < s.length() && s[low] == s[high])
        {
            low--;
            high++;
        }

        palindrome = s.substr(low + 1, high - low - 1);
        if (palindrome.length() > LPS.length())
        {
            LPS = palindrome;
        }
    }
    return LPS;
}
int main()
{
    string s = "babad";
    cout << longestPalindrome(s);
}