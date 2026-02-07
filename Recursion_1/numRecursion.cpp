#include <bits/stdc++.h>
using namespace std;
int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}
int main()
{
    int n;
    cout << "Enter a number to find its factorial: ";
    cin >> n;
    int factorialOfN = factorial(n);
    cout << "Factorial of given number is: " << factorialOfN;
}