#include <bits/stdc++.h>
using namespace std;
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{ /*
     set<int> mySet;

     for (int i = 0; i < nums1.size(); i++)
     {
         for (int j = 0; j < nums2.size(); j++)
         {
             if (nums1[i] == nums2[j])
             {
                 mySet.insert(nums1[i]);
             }
         }
     }

     vector<int> temp(mySet.begin(), mySet.end());

     return temp;
     */

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    vector<int> temp;
    for (int i = 0; i < nums1.size(); i++)
    {
        if (nums1[i] == nums1[i + 1])
        {
            continue;
        }
        int low = 0, high = nums2.size() - 1;
        cout << "Entering for loop" << endl;
        while (low <= high)
        {
            cout << "Entering while" << endl;
            int mid = low + (high - low) / 2;
            if (nums2[mid] == nums1[i])
            {
                cout << "mid " << mid << endl;
                temp.push_back(nums2[mid]);
                break;
            }
            else if (nums2[mid] < nums1[i])
            {
                cout << "else if: " << low << endl;
                low = mid + 1;
                cout << "else if: " << low << endl;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return temp;
}
int main()
{
    vector<int> arr1 = {4, 9, 5};
    vector<int> arr2 = {9, 4, 9, 8, 4};
    vector<int> result = intersection(arr1, arr2);
    for (const auto &val : result)
    {
        cout << val << " ";
    }

    // cout << arr1.size();
    // cout << arr1.capacity();
}