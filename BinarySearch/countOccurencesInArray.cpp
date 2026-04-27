#include <bits/stdc++.h>
using namespace std;
int firstOccurence(vector<int> &nums, int target)
{
    int n = nums.size();
    int first = -1;
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == target)
        {
            first = mid;
            high = mid - 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return first;
}

int lastOccurence(vector<int> &nums, int target)
{
    int n = nums.size();
    int last = -1;
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == target)
        {
            last = mid;
            low = mid + 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return last;
}
int countOccurrences(vector<int> &nums, int target)
{
    int first = firstOccurence(nums, target);
    if (first == -1)
        return 0;
    int last = lastOccurence(nums, target);
    int count = last - first + 1;
    return count;
}
int main()
{
    vector<int> nums = {2, 2, 3, 3, 3, 3, 4};
    int target = 3;
    int count = countOccurrences(nums, target);
    cout << format("No. of occurences of {} in array: {}", target, count);
    return 0;
}