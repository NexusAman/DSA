#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int writeIndex = m + n - 1;
    int i = m - 1;
    int j = n - 1;

    while (j >= 0)
    {
        if (i >= 0 && nums1[i] > nums2[j])
        {
            nums1[writeIndex] = nums1[i];
            writeIndex--;
            i--;
        }
        else
        {
            nums1[writeIndex] = nums2[j];
            writeIndex--;
            j--;
        }
    }
}
int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    merge(nums1, 3, nums2, 3);

    for (auto val : nums1)
    {
        cout << val << " ";
    }
    return 0;
}