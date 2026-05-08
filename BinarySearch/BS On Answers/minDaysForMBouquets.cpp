#include <bits/stdc++.h>
using namespace std;
int minDays(vector<int> &bloomDay, int m, int k)
{
    /*
    //Brute force approach
    long long flowersRequired = 1LL * m * k;
    int n = bloomDay.size();

    if (flowersRequired > n)
    {
        return -1;
    }

    int maxDays = *max_element(bloomDay.begin(), bloomDay.end());

    // Try every day
    for (int day = 1; day <= maxDays; day++)
    {
        int bouquets = 0;
        int count = 0;

        // Check flowers bloomed till this day
        for (int i = 0; i < n; i++)
        {
            if (bloomDay[i] <= day)
            {
                count++;
            }
            else
            {
                count = 0;
            }

            // One bouquet formed
            if (count == k)
            {
                bouquets++;
                count = 0; // avoid reuse
            }
        }

        if (bouquets >= m)
        {
            return day;
        }
    }

    return -1;
    */

    // Optimal approach
    int n = bloomDay.size();
    long long flowerRequired = 1LL * m * k;

    if (flowerRequired > n)
    {
        return -1;
    }
    int maxDays = *max_element(bloomDay.begin(), bloomDay.end());

    int low = 1, high = maxDays;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int day = mid;
        int count = 0;
        int bouquets = 0;

        for (int i = 0; i < n; i++)
        {
            if (bloomDay[i] <= day)
            {
                count++;
            }
            else
            {
                count = 0;
            }

            if (count == k)
            {
                bouquets++;
                count = 0;
            }
        }
        if (bouquets >= m)
        {
            ans = day;
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
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 1;
    cout << minDays(bloomDay, m, k);
    return 0;
}