#include <iostream>
using namespace std;

void printName(string name, int n, int count)
{
    if (count == n)
    {
        return;
    }

    cout << name << "\n";
    printName(name, n, count + 1);
}

int main()
{
    int n;
    string name;
    cout << "Enter the name: ";
    cin >> name;
    cout << "Enter the value of n: ";
    cin >> n;
    printName(name, n, 0);

    return 0;
}