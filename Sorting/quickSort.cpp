#include <iostream>
#include <algorithm>
using namespace std;

// FUNCTION DECLARATION
int partitionIdx(int arr[], int low, int high);

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pIdx = partitionIdx(arr, low, high);
        quickSort(arr, low, pIdx - 1);
        quickSort(arr, pIdx + 1, high);
    }
}

int partitionIdx(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i < high)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i < j)
            swap(arr[i], arr[j]);
    }

    // CORRECT SWAP
    swap(arr[low], arr[j]);
    return j;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "\nSorted array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    delete[] arr;
    return 0;
}
