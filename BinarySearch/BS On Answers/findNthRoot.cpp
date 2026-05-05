#include <bits/stdc++.h>
using namespace std;
int NthRoot(int n, int m)
{
    /*
    //Brute Force Approach
    if (m == 0)
        return 0;
    for (int i = 1; i <= m; i++)
    {
        long long val = 1;

        for (int j = 0; j < n; j++)
        {
            val *= i;

            if (val > m)
                break;
        }
        if (val == m)
            return i;
    }
    return -1;
    */

    // Optimal Approach
    if (m == 0)
        return 0;
    int low = 1, high = m;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        long long val = 1;

        for (int i = 0; i < n; i++)
        {
            val *= mid;
            if (val > m)
                break;
        }

        if (val == m)
        {
            return mid;
        }
        else if (val > m)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int n = 3;
    int m = 27;
    cout << NthRoot(n, m);
    return 0;
}