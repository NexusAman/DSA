#include <bits/stdc++.h>
using namespace std;

/*
// Brute force approach
class StockSpanner
{
    vector<int> nums;

public:
    StockSpanner() { nums = {}; }

    int next(int price)
    {
        nums.push_back(price);
        int cnt = 1;

        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] <= price)
            {
                cnt++;
            }
            else
            {
                break;
            }
        }

        return cnt;
    }
};

 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

class StockSpanner
{
    stack<pair<int, int>> st;
    int ind = -1;

public:
    StockSpanner()
    {
        ind = -1;
    }

    int next(int price)
    {
        ind = ind + 1;
        while (!st.empty() && st.top().first <= price)
        {
            st.pop();
        }

        int ans = ind - (st.empty() ? -1 : st.top().second);
        st.push({price, ind});

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */