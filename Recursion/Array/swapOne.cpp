// reverseArray using one variable
#include <iostream>
using namespace std;
void reverseArr(int i, int n, int arr[])
{
    if (i >= (n - i - 1))
        return;
    swap(arr[i], arr[n - i - 1]);
    reverseArr(i + 1, n, arr);
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
    reverseArr(0, n, arr);
    cout << "Elements of the array are: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}