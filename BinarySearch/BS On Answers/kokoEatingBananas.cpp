#include <bits/stdc++.h>
using namespace std;
int minEatingSpeed(vector<int> &piles, int h)
{
    /*
    //Brute force approach
    int n = piles.size();
    int maxValue = *max_element(piles.begin(), piles.end());

    for (int i = 1; i <= maxValue; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            double hour = (double)piles[j] / i;
            sum += ceil(hour);

            if (sum > h)
                break;
        }
        if (sum <= h)
        {
            return i;
        }
    }
    return -1;
    */

    // Optimal Approach
    int maxValue = *max_element(piles.begin(), piles.end());
    int n = piles.size();
    int low = 1, high = maxValue;
    int ans = INT_MAX;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        long long total = 0;
        for (int i = 0; i < n; i++)
        {
            double hour = (double)piles[i] / mid;

            total += ceil(hour);
        }

        if (total <= h)
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
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    cout << minEatingSpeed(piles, h);
    return 0;
}