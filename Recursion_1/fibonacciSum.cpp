#include <iostream>
using namespace std;
int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main()
{
    int n;
    cout << "Enter the nth term: ";
    cin >> n;
    int fibonacciSum = fibonacci(n);
    cout << "Fibonacci Sum till " << n << " term: " << fibonacciSum;
}