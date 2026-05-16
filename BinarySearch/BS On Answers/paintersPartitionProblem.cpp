#include <bits/stdc++.h>
using namespace std;
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
int main()
{
    vector<int> arr = {10, 20, 30, 40};
    int k = 2;
    cout << minTime(arr, k);
    return 0;
}