#include <bits/stdc++.h>
using namespace std;
int minDays(vector<int> &bloomDay, int m, int k)
{
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
}
int main()
{
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 1;
    cout << minDays(bloomDay, m, k);
    return 0;
}