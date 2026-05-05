#include <bits/stdc++.h>
using namespace std;
int floorSqrt(int n)
{
    /*
    //Function based solution
    int result = sqrt(n);
    return result;
    */

    /*
    // Brute force approach
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if ((long long)i * i <= n)
        {
            ans = i;
        }
        else
        {
            break;
        }
    }
    return ans;
    */

    // Optimal Approach
    int ans = 0;
    int low = 1, high = n;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if ((long long)mid * mid == n)
        {
            return mid;
        }
        else if ((long long)mid * mid < n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int n = 36;
    cout << floorSqrt(n);
    return 0;
}