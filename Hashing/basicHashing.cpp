#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // precompute
    int hash[13] = {0}; // taking max input size as 12
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
    }

    int q;
    cout << "Enter the number of query: ";
    cin >> q;
    while (q--)
    {
        int number;
        cout << "Enter the number to search: ";
        cin >> number;
        // fetching
        cout << number << " appears -> " << hash[number] << " times" << endl;
    }
    return 0;
}