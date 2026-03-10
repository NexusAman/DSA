#include <bits/stdc++.h>
using namespace std;
int missingNum(vector<int> nums)
{
    int n = nums.size();
    int arrSum = 0;
    for (int i = 0; i < n; i++)
    {
        arrSum += nums[i];
    }

    int realNum = n + 1;
    int sum = realNum * (realNum + 1) / 2;
    return sum - arrSum;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 7, 8};
    cout << missingNum(nums);
}