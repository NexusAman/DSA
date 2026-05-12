#include <bits/stdc++.h>
using namespace std;
/*
//Brute force approach
bool canWePlace(vector<int> &stalls, int k, int d)
{
    int n = stalls.size();
    int cntCows = 1, lastCow = stalls[0];

    for (int i = 1; i < n; i++)
    {
        if ((stalls[i] - lastCow) >= d)
        {
            cntCows++;
            lastCow = stalls[i];
        }
    }
    if (cntCows >= k)
    {
        return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int min = stalls[0];
    int max = stalls[n - 1];

    for (int i = 1; i <= (max - min); i++)
    {
        if (canWePlace(stalls, k, i))
        {
            continue;
        }
        else
        {
            return (i - 1);
        }
    }
    return (max - min);
}
*/
bool canWePlace(vector<int> &stalls, int k, int dist)
{
    int n = stalls.size();
    int cntCows = 1, lastCow = stalls[0];

    for (int i = 1; i < n; i++)
    {
        if ((stalls[i] - lastCow) >= dist)
        {
            cntCows++;
            lastCow = stalls[i];
        }
    }
    if (cntCows >= k)
    {
        return true;
    }
    return false;
}

// Optimal approach
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();

    int low = 1, high = stalls[n - 1] - stalls[0];

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canWePlace(stalls, k, mid))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}

int main()
{
    vector<int> stalls = {1, 2, 4, 8, 9};
    int k = 3;
    cout << aggressiveCows(stalls, k);
    return 0;
}