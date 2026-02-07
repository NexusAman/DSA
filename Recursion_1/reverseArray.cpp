#include <bits\stdc++.h>
using namespace std;
void reverseArray(int arr[], int newArr[], int n, int initialCount, int lastCount)
{
    if (lastCount < 0)
    {
        return;
    }
    newArr[initialCount] = arr[lastCount];
    reverseArray(arr, newArr, n, initialCount + 1, lastCount - 1);
}

int main()
{
    int n;
    cout << "Enter the nth term: ";
    cin >> n;
    int arr[n];
    int lastCount = n - 1;
    int newArr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i + 1 << " number: ";
        cin >> arr[i];
    }
    reverseArray(arr, newArr, n, 0, lastCount);

    cout << "Reverse Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << newArr[i] << " ";
    }

    return 0;
}