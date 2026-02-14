#include <bits/stdc++.h>
using namespace std;
// int squareRoot(int n)
// {
//     for (int i = 1; i < n; i++)
//     {
//         if (i == (n / i))
//         {
//             return i;
//         }
//         else if (i * (n / i) > n)
//         {
//             return i - 1;
//         }
//     }
// }
int squareRoot(int n)
{
    if (n < 2)
        return n;

    int low = 1, high = n / 2;
    int ans = 0;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;

        if (mid * mid <= n)
        {
            ans = int(mid);
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
    int n;
    cout << "Enter the number to find square root: ";
    cin >> n;
    int x = squareRoot(n);
    cout << "Square root of " << n << ": " << x;
}