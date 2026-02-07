#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Time Complexity: O(log n) in all cases (i.e best,avg and worst)
    // that's why first always prefer unordered map then ordered map

    // precompute
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    // for (auto it : mpp)
    // {
    //     cout << it.first << "->" << it.second << endl;
    // }
    int q;
    cin >> q;
    while (q--)
    {
        int number;
        cin >> number;
        // fetch
        cout << mpp[number] << endl;
    }
    return 0;
}