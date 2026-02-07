// reverseArray using two variables

#include <iostream>
using namespace std;
void reverseArr(int l, int r, int arr[])
{
    if (l >= r)
        return;
    swap(arr[l], arr[r]);
    reverseArr(l + 1, r - 1, arr);
}
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i + 1 << " value: ";
        cin >> arr[i];
    }

    reverseArr(0, n - 1, arr);
    cout << "Elements of the array are: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}