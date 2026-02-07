#include <iostream>
using namespace std;

void printNum(int i, int n)
{
    if (i > n)
    {
        return;
    }
    else
    {
        cout << n << endl;
        printNum(i, n - 1);
    }
}
int main()
{
    int n;
    cout << "Enter the nth term: ";
    cin >> n;
    printNum(1, n);
}