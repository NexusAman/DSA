#include <iostream>
using namespace std;

int main()
{
    int count = 0;
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int originalNum = num;
    while (num > 0)
    {
        num = num / 10;
        count++;
    }
    cout << "No. of digits in " << originalNum << " is: " << count;
    return 0;
}