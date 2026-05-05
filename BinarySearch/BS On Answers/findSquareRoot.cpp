#include <bits/stdc++.h>
using namespace std;
int floorSqrt(int n)
{
    /*
    //Function based solution
    int result = sqrt(n);
    return result;
    */

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
}
int main()
{
    int n = 36;
    cout << floorSqrt(n);
    return 0;
}