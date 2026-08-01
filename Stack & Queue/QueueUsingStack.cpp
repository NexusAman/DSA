#include <bits/stdc++.h>
using namespace std;

/*
// Approach 1: if less push operation
class Queue{
    public:
    stack<int> s1, s2;

    void push(int x){
        while (s1.size())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);

        while (s2.size())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop(){
        s1.pop();
    }

    int front(){
        return s1.top();
    }

    int size(){
        return s1.size();
    }
};
*/

// Approach 2: if have more push operations
class Queue
{
public:
    stack<int> s1, s2;

    void push(int x)
    {
        s1.push(x);
    }

    void pop()
    {
        if (!s2.empty())
        {
            s2.pop();
        }
        else
        {
            for (int i = 0; i < s1.size(); i++)
            {
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
        }
    }

    int front()
    {
        if (!s2.empty())
        {
            return s2.top();
        }
        else
        {
            for (int i = 0; i < s1.size(); i++)
            {
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }

    int size()
    {
        return s1.size();
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    cout << q.front() << "\n";
    q.pop();
    cout << q.front() << "\n";
    q.pop();

    return 0;
}