#include <iostream>
using namespace std;
int printSum(int n)
{
    if (n == 0)
        return 0;
    else
        return n + printSum(n - 1);
}
int main()
{
    int n;
    cout << "Enter the nth term: ";
    cin >> n;
    cout << printSum(n);
}