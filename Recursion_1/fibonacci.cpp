#include <bits\stdc++.h>
using namespace std;
void fibonacci(int n, int firstTerm, int secondTerm, int count)
{
    if (count > n)
    {
        return;
    }

    if (n < 1)
    {
        cout << "Enter valid input" << endl;
    }

    if (n == 1)
    {
        cout << firstTerm << " ";
        count++;
    }
    else if (n == 2)
    {
        cout << firstTerm + secondTerm << " ";
        count++;
    }
    else
    {
        return fibonacci()
    }

    int main()
    {
        int n;
        cout << "Enter a number: ";
        cin >> n;
        int firstTerm = 0;
        int secondTerm = 1;
        int count = 0;
        fibonacci(n, firstTerm, secondTerm, count);
    }