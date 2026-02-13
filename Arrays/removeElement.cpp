#include <bits/stdc++.h>
using namespace std;
int removeElement(vector<int> &nums, int val)
{
    int n = nums.size();
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != val)
        {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

int main()
{
    vector<int> nums = {3, 2, 3, 1, 4, 5, 6};
    int val;
    cout << "Enter a value to remove from array: ";
    cin >> val;
    int originalSize = nums.size();
    int k = removeElement(nums, val);

    if (k == originalSize)
    {
        cout << "Value is not present in the array!";
    }
    else
    {
        cout << "Updated array: " << " ";
        for (int i = 0; i < k; i++)
        {
            cout << nums[i] << " ";
        }
    }
}