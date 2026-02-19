#include <bits/stdc++.h>
using namespace std;

// int main()
// {
// vector<int> arr = {2, 2, 1};

// for (int i = 0; i < arr.size(); i++)
// {
//     int count = 0;

//     for (int j = 0; j < arr.size(); j++)
//     {
//         if (arr[i] == arr[j])
//         {
//             count++;
//         }
//     }

//     if (count == 1)
//     {
//         cout << arr[i];
//         break;
//     }
// }

int main()
{
    vector<int> arr = {2, 2, 1, 4, 5, 4, 5};

    int result = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        result = result ^ arr[i];
    }

    cout << "Unique element is: " << result;

    return 0;
}
