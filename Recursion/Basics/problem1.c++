#include <iostream>
using namespace std;

void printName(int n, string name, int count = 0)
{
    if (count == n)
    {
        return;
    }
    else
    {
        cout << name << endl;
        printName(n, name, count + 1);
    }
}

int main()
{
    int n;
    string name;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter the nth term: ";
    cin >> n;
    printName(n, name);
    return 0;
}