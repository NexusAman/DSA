#include <bits/stdc++.h>
using namespace std;

/* For interview perspective always follow this sequence:-
    -> Brute Force Approach
    -> Better Approach (if exists)
    -> Optimal Approach (best approach)
*/

// Brute Force Approach
// TC -> O(n log n) + O(n)
// int SecondLargestFn(int arr[], int n)
// {
//     sort(arr, arr + n);

//     int largest = arr[n - 1];
//     int secondLargest = -1;

//     for (int i = n - 2; i >= 0; i--)
//     {
//         if (arr[i] != largest)
//         {
//             secondLargest = arr[i];
//             break;
//         }
//     }
//     return secondLargest;
// }

// Better Approach
// TC -> O(n) + O(n) =  O(2n)
// int SecondLargestFn(int arr[], int n)
// {
//     int largest = arr[0];

//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] > largest)
//         {
//             largest = arr[i];
//         }
//     }

//     int secondLargest = -1;

//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] > secondLargest && arr[i] != largest)
//         {
//             secondLargest = arr[i];
//         }
//     }
//     return secondLargest;
// }

// Optimal Approach
// TC -> O(n)
int SecondLargestFn(int arr[], int n)
{
    int largest = arr[0];
    int secondLargest = INT_MIN;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest)
        {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
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

    int secondLargest = SecondLargestFn(arr, n);
    cout << "Second Largest Element in the array: " << secondLargest << endl;

    delete[] arr;
    return 0;
}
