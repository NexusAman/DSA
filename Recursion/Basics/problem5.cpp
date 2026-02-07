#include <iostream>
using namespace std;
void printNumDecreasing(int i, int n)
{
    if (i > n)
    {
        return;
    }
    else
    {
        printNumDecreasing(i + 1, n);
        cout << i << endl;
    }
}
int main()
{
    int n;
    cout << "Enter the nth term: ";
    cin >> n;
    printNumDecreasing(1, n);
}