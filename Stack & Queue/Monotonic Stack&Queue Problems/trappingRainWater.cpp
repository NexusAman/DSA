#include <bits/stdc++.h>
using namespace std;
/*
// Brute force approach
int trap(vector<int> &height)
{
    int res = 0;

    for (int i = 0; i < height.size(); i++)
    {
        int leftMax = INT_MIN;
        int rightMax = INT_MIN;
        for (int j = i; j >= 0; j--)
        {
            if (leftMax < height[j])
            {
                leftMax = height[j];
            }
        }

        for (int k = i; k < height.size(); k++)
        {
            if (rightMax < height[k])
            {
                rightMax = height[k];
            }
        }

        res += min(leftMax, rightMax) - height[i];
    }
    return res;
}
*/

int trap(vector<int> &height)
{
    int ans = 0;
    int i = 0;
    int j = height.size() - 1;

    int leftMax = 0;
    int rightMax = 0;

    while (i < j)
    {
        leftMax = max(leftMax, height[i]);
        rightMax = max(rightMax, height[j]);

        if (leftMax < rightMax)
        {
            ans += leftMax - height[i];
            i++;
        }
        else
        {
            ans += rightMax - height[j];
            j--;
        }
    }

    return ans;
}

int main()
{
    vector<int> height = {4, 2, 0, 3, 2, 5};

    cout << trap(height);

    return 0;
}