#include <bits/stdc++.h>
using namespace std;

// Brute force approach
//  int main()
//  {
//      int n;
//      cout << "Enter a number: ";
//      cin >> n;
//      for (int i = 1; i <= sqrt(n); i++)
//      {
//          if (n % i == 0)
//          {
//              cout << i << " ";
//              if (n / i != i)
//              {
//                  cout << n / i << " ";
//              }
//          }
//      }

//     return 0;
// }

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int cnt = 0;

    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cnt++;
            if (n / i != i)
            {
                cnt++;
            }
        }
    }

    if (cnt == 2)
    {
        cout << "It is a prime number.";
    }
    else
    {
        cout << "It is not a prime number.";
    }
}