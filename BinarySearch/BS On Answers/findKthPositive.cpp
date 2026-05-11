#include <bits/stdc++.h>
using namespace std;
int findKthPositive(vector<int> &arr, int k)
{
    /*
    //Brute force approach(self)
    int n = arr.size();
    int pnt = 0;
    vector<int> ans;

    for (int i = 1; i <= 2000; i++)
    {
        if (pnt < n && i == arr[pnt])
        {
            pnt++;
            continue;
        }
        ans.push_back(i);
    }

    return ans[k - 1];
    */

    /*
    // Brute force approach
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
        {
            k++;
        }
        else
        {
            break;
        }
    }
    return k;
    */

    // Optimal Approach
    int n = arr.size();

    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int missing = arr[mid] - (mid + 1);

        if (missing < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high + k + 1;
}
int main()
{
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout << findKthPositive(arr, k);
    return 0;
}