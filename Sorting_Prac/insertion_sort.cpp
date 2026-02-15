#include <bits/stdc++.h>
using namespace std;
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];

        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > key)
            {
                int temp = arr[j];
                arr[j] = key;
                key = temp;
            }
        }
    }
}
int main()
{
    int arr[] = {3, 2, 4, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}