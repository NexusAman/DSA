#include <iostream>
using namespace std;
void printNum(int i, int n)
{
    if (i < 1)
    {
        return;
    }
    else
    {
        printNum(i - 1, n);
        cout << i << endl;
    }
}
int main()
{
    int n;
    cout << "Enter the nth term: ";
    cin >> n;
    printNum(n, n);
}