#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && (arr[j - 1] > arr[j]))
        {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
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

    // calling the insertionSort fn
    insertionSort(arr, n);

    // showing output
    cout << "\nSorted array: " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}