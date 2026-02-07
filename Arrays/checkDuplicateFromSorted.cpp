#include <bits/stdc++.h>
using namespace std;

/* For interview perspective always follow this sequence:-
    -> Brute Force Approach
    -> Better Approach (if exists)
    -> Optimal Approach (best approach)
*/

// Brute Force approach
// TC -> O(n log n)  SC -> O(n)
//  int removeDuplicates(int arr[], int n)
//  {
//      set<int> s;
//      int index = 0;

//     for (int i = 0; i < n; i++)
//     {
//         if (s.insert(arr[i]).second)
//         {
//             arr[index++] = arr[i];
//         }
//     }
//     return index; // count of unique elements
// }

// Optimal Approach
//  TC -> O(n) & SC -> O(1)
int removeDuplicates(int arr[], int n)
{
    int i = 0;

    for (int j = 0; j < n; j++)
    {
        if (arr[j] != arr[i])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }

    return i + 1;
}

int main()
{
    int arr[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = removeDuplicates(arr, n);

    cout << "k = " << k << "\nArray after removing duplicates: ";
    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }
}
