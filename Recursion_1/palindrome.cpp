#include <bits\stdc++.h>
using namespace std;

int main()
{
    // Brute force approach
    string name;
    cout << "Enter a string: ";
    cin >> name;

    int length = name.length();

    string name1;
    cout << name[0];

    for (int i = 0; i < length; i++)
    {
        name1[i] = name[length - i - 1];
    }

    if (name == name1)
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome";
    }
}