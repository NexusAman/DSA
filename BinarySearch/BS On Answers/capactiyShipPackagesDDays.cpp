#include <bits/stdc++.h>
using namespace std;
int shipWithinDays(vector<int> &weights, int days)
{
    /*
    //Brute force approach
    int n = weights.size();
    long long totalweights = 0;
    int maxWeight = 0;

    for (int i = 0; i < n; i++)
    {
        totalweights += weights[i];
        maxWeight = max(maxWeight, weights[i]);
    }

    for (int capacity = maxWeight; capacity <= totalweights; capacity++)
    {
        int dayUsed = 1;
        long long currentLoad = 0;

        for (int i = 0; i < n; i++)
        {
            if (currentLoad + weights[i] <= capacity)
            {
                currentLoad += weights[i];
            }
            else
            {
                dayUsed++;
                currentLoad = weights[i];
            }
        }
        if (dayUsed <= days)
        {
            return capacity;
        }
    }
    return -1;
    */

    // Optimal approach
    int n = weights.size();
    long long totalweights = 0;
    int maxWeight = 0;

    for (int i = 0; i < n; i++)
    {
        totalweights += weights[i];
        maxWeight = max(maxWeight, weights[i]);
    }

    int low = maxWeight, high = totalweights;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int dayUsed = 1;
        long long currentLoad = 0;

        for (int i = 0; i < n; i++)
        {
            if (currentLoad + weights[i] <= mid)
            {
                currentLoad += weights[i];
            }
            else
            {
                dayUsed++;
                currentLoad = weights[i];
            }
        }
        if (dayUsed <= days)
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
    vector<int> weights = {3, 2, 2, 4, 1, 4};
    int days = 3;
    cout << shipWithinDays(weights, days);
    return 0;
}