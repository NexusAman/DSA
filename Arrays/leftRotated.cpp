#include <bits/stdc++.h>
using namespace std;
void leftRotatedArray(vector<int> &nums)
{
    // Brute force
    /*
    vector<int> temp;
    for (int i = 1; i < nums.size(); i++)
    {
        temp.push_back(nums[i]);
    }
    temp.push_back(nums[0]);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << temp[i] << " ";
    }
    */

    // Optimal
    int temp = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        nums[i - 1] = nums[i];
    }
    nums[nums.size() - 1] = temp;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    leftRotatedArray(nums);
    return 0;
}