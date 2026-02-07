#include <bits/stdc++.h>
using namespace std;

/* For interview perspective always follow this sequence:-
    -> Brute Force Approach
    -> Better Approach (if exists)
    -> Optimal Approach (best approach)
*/

// Brute Force Approach
//  TC -> O(n log n)
//  int largestElementFn(int arr[], int n)
//  {
//      sort(arr, arr + n);
//      int largest = arr[n - 1];

//     return largest;
// }

// Optimal Approach
// TC -> O(n)
int largestElementFn(int arr[], int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
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
    int largestElement = largestElementFn(arr, n);
    cout << "Largest Element in the array: " << largestElement << endl;
    return 0;
}