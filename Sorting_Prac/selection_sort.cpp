#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int min = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
            }
        }
        swap(arr[i], min);
    }
}

int main()
{
    int arr[] = {3, 4, 1, 5, 4, 5, 6, 6, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    selection_sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}