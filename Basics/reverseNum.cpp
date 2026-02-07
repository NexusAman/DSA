#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int orignialNum = num;
    int revNum = 0;

    while (num != 0)
    {
        revNum = revNum * 10;
        revNum += num % 10;
        num = num / 10;
    }
    cout << "The reverse of " << orignialNum << " is: " << revNum;
    return 0;
}