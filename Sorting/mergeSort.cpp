#include <iostream>
// #include<vector>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    int size = high - low + 1;
    int temp[size]; // FIX 1: replace MAX_PATH with a fixed size (simple fix)
    int left = low;
    int right = mid + 1;
    int i = 0; // FIX 2: i must be outside the loop

    while (left <= mid && right <= high)
    {
        if (arr[left] < arr[right])
        {
            temp[i] = arr[left];
            left++;
        }
        else
        {
            temp[i] = arr[right];
            right++;
        }
        i++; // FIX 3: increment i
    }

    while (left <= mid)
    {
        temp[i] = arr[left];
        left++;
        i++;
    }

    while (right <= high)
    {
        temp[i] = arr[right];
        right++;
        i++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    // taking inputs
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << (i + 1) << ": ";
        cin >> arr[i];
    }

    int low = 0;      // FIX 4: low must be index
    int high = n - 1; // FIX 5: high must be index

    mergeSort(arr, low, high);

    // showing output
    cout << "\nSorted array: " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
