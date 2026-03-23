#include <iostream>
#include <format>
#include <string>
using namespace std;

void hello(string name)
{
    cout << format("good night {}!", name);
}

int main()
{
    cout << "Hello Composer!" << endl;
    hello("Sidhant");
    return 0;
}