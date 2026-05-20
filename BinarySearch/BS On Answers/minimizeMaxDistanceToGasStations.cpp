#include <bits/stdc++.h>
using namespace std;
/*
//Brute force approach
double minMaxDist(vector<int> &stations, int k)
{
    int n = stations.size();
    vector<int> howMany(n - 1, 0);

    for (int gasStations = 1; gasStations <= k; gasStations++)
    {
        long double maxSection = -1;
        int maxInd = -1;

        for (int i = 0; i < n - 1; i++)
        {
            long double diff = (stations[i + 1] - stations[i]);
            long double sectionLength = diff / (long double)(howMany[i] + 1);
            if (sectionLength > maxSection)
            {
                maxSection = sectionLength;
                maxInd = i;
            }
        }
        howMany[maxInd]++;
    }

    long double maxAns = -1;
    for (int i = 0; i < n - 1; i++)
    {
        long double diff = (stations[i + 1] - stations[i]);
        long double sectionLength = diff / (long double)(howMany[i] + 1);
        maxAns = max(maxAns, sectionLength);
    }
    return maxAns;
}
*/

/*
// Better approach
double minMaxDist(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> howMany(n - 1, 0);
    priority_queue<pair<long double, int>> pq;

    for (int i = 0; i < n - 1; i++)
    {
        pq.push({arr[i + 1] - arr[i], i});
    }

    for (int gasStations = 1; gasStations <= k; gasStations++)
    {
        auto tp = pq.top();
        pq.pop();
        int secInd = tp.second;
        howMany[secInd]++;

        long double iniDiff = arr[secInd + 1] - arr[secInd];
        long double newSecLen = iniDiff / (long double)(howMany[secInd] + 1);
        pq.push({newSecLen, secInd});
    }
    return pq.top().first;
}
*/

// Optimal approach
int numberOfGasStationsRequired(long double dist, vector<int> &arr)
{
    int cnt = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if (arr[i] - arr[i - 1] / dist == numberInBetween * dist)
        {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}
double minMaxDist(vector<int> &arr, int k)
{
    int n = arr.size();
    long double low = 0;
    long double high = 0;
    for (int i = 0; i < n - 1; i++)
    {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    long double diff = 1e-6;
    while (high - low > diff)
    {
        long double mid = (low + high) / 2.0;
        int cnt = numberOfGasStationsRequired(mid, arr);
        if (cnt > k)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    return high;
}
int main()
{
    vector<int> stations = {1, 2, 3, 4, 5};
    int k = 2;
    cout << minMaxDist(stations, k);
    return 0;
}