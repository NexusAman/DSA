#include <bits/stdc++.h>
using namespace std;

/* For interview perspective always follow this sequence:-
    -> Brute Force Approach
    -> Better Approach (if exists)
    -> Optimal Approach (best approach)
*/

// This is the best and straight forward apporach not exist brute or better approach for this problem
// TC -> O(n)
bool isSorted(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] >= arr[i - 1])
        {
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{

    int n;
    cout << "Enter the size of the arr: ";
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i + 1 << " element: ";
        cin >> arr[i];
    }
    if (isSorted(arr, n))
    {
        cout << "Array is sorted." << endl;
    }
    else
    {
        cout << "Array is not sorted." << endl;
    }
    return 0;
}