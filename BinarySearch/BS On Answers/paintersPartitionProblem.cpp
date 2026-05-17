#include <bits/stdc++.h>
using namespace std;
/*
//Brute force approach
int countPainters(vector<int> arr, int maxTime)
{
    int n = arr.size();
    int painters = 1;
    int boardsPainted = 0;

    for (int i = 0; i < n; i++)
    {
        if ((boardsPainted + arr[i]) <= maxTime)
        {
            boardsPainted += arr[i];
        }
        else
        {
            painters++;
            boardsPainted = arr[i];
        }
    }
    return painters;
}
int minTime(vector<int> &arr, int k)
{
    int n = arr.size();
    int low = *max_element(arr.begin(), arr.end());
    long long high = accumulate(arr.begin(), arr.end(), 0);

    for (int i = low; i <= high; i++)
    {
        if (countPainters(arr, i) <= k)
        {
            return i;
        }
    }
    return -1;
}
*/

// Optimal Approach
int countPainters(vector<int> arr, int maxTime)
{
    int n = arr.size();
    int painters = 1;
    int boardsPainted = 0;

    for (int i = 0; i < n; i++)
    {
        if ((boardsPainted + arr[i]) <= maxTime)
        {
            boardsPainted += arr[i];
        }
        else
        {
            painters++;
            boardsPainted = arr[i];
        }
    }
    return painters;
}

int minTime(vector<int> &arr, int k)
{
    int n = arr.size();
    int low = *max_element(arr.begin(), arr.end());
    long long high = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (countPainters(arr, mid) <= k)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {10, 20, 30, 40};
    int k = 2;
    cout << minTime(arr, k);
}