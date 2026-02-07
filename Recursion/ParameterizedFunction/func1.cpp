#include <iostream>
using namespace std;
void printSum(int i, int sum)
{
    if (i < 1)
    {
        cout << sum;
        return;
    }
    else
    {
        printSum(i - 1, sum + i);
    }
}
int main()
{
    int n;
    cout << "Enter the nth term: ";
    cin >> n;
    printSum(n, 0);
}