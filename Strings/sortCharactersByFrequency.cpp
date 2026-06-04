#include <bits/stdc++.h>
using namespace std;
string frequencySort(string s)
{
    unordered_map<char, int> freq;

    for (char ch : s)
    {
        freq[ch]++;
    }

    vector<pair<char, int>> arr(freq.begin(), freq.end());

    sort(arr.begin(), arr.end(),
         [](const pair<char, int> &a, const pair<char, int> &b)
         {
             return a.second > b.second;
         });

    string result;

    for (const auto &p : arr)
    {
        result.append(p.second, p.first);
    }

    return result;
}
int main()
{
    string s = "Aabb";
    cout << frequencySort(s);
    return 0;
}