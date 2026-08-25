#include <bits/stdc++.h>
using namespace std;

// Brute force approach
// vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
// {
//     vector<int> ans;
//     bool isGreater = false;

//     for (int i = 0; i < nums1.size(); i++)
//     {
//         for (int j = 0; j < nums2.size(); j++)
//         {
//             if (nums1[i] == nums2[j])
//             {
//                 for (int k = j; k < nums2.size(); k++)
//                 {
//                     if (nums2[k] > nums2[j])
//                     {
//                         ans.push_back(nums2[k]);
//                         isGreater = true;
//                         break;
//                     }
//                 }
//                 if (!isGreater)
//                 {
//                     ans.push_back(-1);
//                 }
//                 else if (isGreater)
//                 {
//                     isGreater = false;
//                 }
//             }
//         }
//     }

//     return ans;
// }

// Optimal approach
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mpp;
        vector<int> ans;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() < nums2[i]) {
                st.pop();
            }

            if (!st.empty()) {
                mpp[nums2[i]] = st.top();
            } else {
                mpp[nums2[i]] = -1;
            }
            st.push(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(mpp[nums1[i]]);
        }

        return ans;
    }

int main()
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> ans = nextGreaterElement(nums1, nums2);

    for (auto val : ans)
    {
        cout << val << " ";
    }

    return 0;
}