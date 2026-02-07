#include <iostream>
using namespace std;

int Count(int num, int arr[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (num == arr[i])
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int arr[] = {1, 2, 1, 3, 2};
    int num;
    cout << "Enter the item to search in the array: ";
    cin >> num;

    int size = sizeof(arr) / sizeof(arr[0]);
    int count = Count(num, arr, size);

    cout << "The number " << num << " is present in the array " << count << " times." << endl;
    return 0;
}
