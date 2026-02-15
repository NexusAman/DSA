#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int arr[], int n)
{
    int count = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                count++;
            }
        }

        if (count == 0)
        {
            break;
        }
    }
}

int main()
{
    int arr[] = {3, 1, 2, 6, 7, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}