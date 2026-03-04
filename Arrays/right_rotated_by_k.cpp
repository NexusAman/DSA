#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Brute Force
// void rotate(vector<int> &nums, int k) {
//   int n = nums.size();
// k = k % n;
//   vector<int> temp;
//   for (int i = n - k; i < n; i++) {
//     temp.push_back(nums[i]);
//   }

//   for (int i = 0; i < n - k; i++) {
//     temp.push_back(nums[i]);
//   }

//   for (auto &val : temp) {
//     cout << val << " ";
//   }
// }

void rotate(vector<int> &nums, int k) {
  k = k % nums.size();
  reverse(nums.begin(), nums.end());
  reverse(nums.begin(), nums.begin() + k);
  reverse(nums.begin() + k, nums.end());
}

int main() {
  vector<int> nums = {1, 2, 3, 4, 5};
  rotate(nums, 2);
  for (auto &val : nums) {
    cout << val << " ";
  }
  return 0;
}