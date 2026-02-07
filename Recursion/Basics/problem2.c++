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
        cout << i << endl;
        printNum(i + 1, n);
    }
}
int main()
{
    int n;
    cout << "Enter the nth term: ";
    cin >> n;
    printNum(1, n);
}