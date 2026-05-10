#include <bits/stdc++.h>
using namespace std;
int findKthPositive(vector<int> &arr, int k)
{
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
}
int main()
{
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout << findKthPositive(arr, k);
    return 0;
}