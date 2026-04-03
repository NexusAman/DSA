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
    cout << "Hello Genius!" << endl;
    hello("Aman");
    return 0;
}