#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int topIndex = -1;
    int capacity;
    vector<int> st;

public:
    Stack(int n) : capacity(n), st(n) {}

    void push(int x)
    {
        if (topIndex >= capacity - 1)
        {
            cout << "Stack size exceeded";
            return;
        }

        topIndex++;
        st[topIndex] = x;
    }

    int top()
    {
        if (topIndex == -1)
        {
            cout << "Stack is empty";
            return -1;
        }

        return st[topIndex];
    }

    void pop()
    {
        if (topIndex == -1)
        {
            cout << "Stack is empty";
        }
        topIndex--;
    }

    int size()
    {
        return topIndex + 1;
    }
};

int main()
{
    Stack st(10);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    cout << st.top() << endl;
    st.pop();
    st.pop();
    cout << st.size();
    return 0;
}