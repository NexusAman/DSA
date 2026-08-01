#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int capacity;
    vector<int> q;
    int currSize = 0;
    int start = -1;
    int end = -1;

public:
    Queue(int n) : capacity(n), q(n) {};

    void push(int x)
    {
        if (currSize == capacity)
        {
            cout << "Queue capacity exceeded\n";
        }
        if (currSize == 0)
        {
            start++;
            end++;
        }
        else
        {
            end = (end + 1) % capacity;
        }
        q[end] = x;
        currSize++;
    }

    int pop()
    {
        if (currSize == 0)
        {
            cout << "Queue is empty" << endl;
        }
        int el = q[start];
        if (currSize == 1)
        {
            start = end = -1;
        }
        else
        {
            start = (start + 1) % capacity;
        }
        currSize--;
        return el;
    }

    int top()
    {
        if (currSize == 0)
        {
            cout << "Queue is empty";
            return -1;
        }
        return q[start];
    }

    int size()
    {
        return currSize;
    }
};

int main(){
    Queue q(4);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.top();
    q.pop();
    cout << q.top();
    q.pop();
    cout << q.top();
    q.pop();
    cout << q.top();
    return 0;
}