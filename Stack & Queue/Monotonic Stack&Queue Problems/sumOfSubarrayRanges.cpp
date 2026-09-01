#include <bits/stdc++.h>
using namespace std;
/*
// Naive approach
long long subArrayRanges(vector<int> &nums)
{
    long long sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            long long largest = LLONG_MIN;
            long long smallest = LLONG_MAX;
            for (int k = i; k <= j; k++)
            {
                if(largest <= nums[k]){
                    largest = nums[k];
                }

                if(smallest >= nums[k]){
                    smallest = nums[k];
                }
            }
            long long range = largest - smallest;
            sum += range;
        }
    }
    return sum;
}
*/

/*
// Better approach
long long subArrayRanges(vector<int> &nums)
{
    long long sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        long long largest = LLONG_MIN;
        long long smallest = LLONG_MAX;
        for (int j = i; j < nums.size(); j++)
        {
            if (largest < nums[j])
            {
                largest = nums[j];
            }

            if (smallest > nums[j])
            {
                smallest = nums[j];
            }

            long long range = largest - smallest;
            sum += range;
        }
    }
    return sum;
}
*/

vector<int> nextGreaterElement(vector<int> &nums)
{
    int n = nums.size();
    vector<int> nge(n, n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[st.top()] < nums[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            nge[i] = st.top();
        }
        st.push(i);
    }
    return nge;
}

vector<int> previousGreaterElement(vector<int> &nums)
{
    int n = nums.size();
    vector<int> pge(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && nums[st.top()] <= nums[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            pge[i] = st.top();
        }
        st.push(i);
    }
    return pge;
}

long long sumSubarrayMaxs(vector<int> &nums)
{
    vector<int> nge = nextGreaterElement(nums);
    vector<int> pge = previousGreaterElement(nums);
    long long sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        int leftChoices = i - pge[i];
        int rightChoices = nge[i] - i;
        long long totalChoices = 1LL * leftChoices * rightChoices;
        long long contribution = 1LL * nums[i] * totalChoices;

        sum += contribution;
    }
    return sum;
}

vector<int> nextSmallerElement(vector<int> &nums)
{
    int n = nums.size();
    vector<int> nse(n, n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[st.top()] > nums[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            nse[i] = st.top();
        }

        st.push(i);
    }
    return nse;
}

vector<int> previousSmallerElement(vector<int> &nums)
{
    int n = nums.size();
    vector<int> pse(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && nums[st.top()] >= nums[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            pse[i] = st.top();
        }

        st.push(i);
    }
    return pse;
}

long long sumSubarrayMins(vector<int> &nums)
{
    vector<int> nse = nextSmallerElement(nums);
    vector<int> pse = previousSmallerElement(nums);
    long long sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        int leftChoices = i - pse[i];
        int rightChoices = nse[i] - i;
        long long totalChoices = 1LL * leftChoices * rightChoices;
        long long contribution = 1LL * nums[i] * totalChoices;
        sum += contribution;
    }
    return sum;
}

long long subArrayRanges(vector<int> &nums)
{
    return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
}

int main()
{
    vector<int> nums = {1, 2, 3};
    cout << subArrayRanges(nums);
    return 0;
}