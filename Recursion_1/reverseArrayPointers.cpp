#include <bits\stdc++.h>
using namespace std;

void reverseArray(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    swap(arr[low], arr[high]);
    reverseArray(arr, low + 1, high - 1);
}

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    int low = 0;
    int high = n - 1;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i + 1 << " number: ";
        cin >> arr[i];
    }
    reverseArray(arr, low, high);
    cout << "Reverse ARRAY: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}