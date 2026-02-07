#include <bits/stdc++.h>
using namespace std;
void sumOfN(int n, int count, int sum)
{
    if (count > n)
    {
        cout << sum;
        return;
    }
    sum += count;
    sumOfN(n, count + 1, sum);
}
int main()
{
    int n;
    int sum = 0;
    cout << "Enter the value of n: ";
    cin >> n;
    sumOfN(n, 0, sum);
    return 0;
}