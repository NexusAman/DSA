#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;

    Node(int x)
    {
        val = x;
        next = nullptr;
    }
};

class Queue
{
public:
    Node *start = nullptr;
    Node *end = nullptr;
    int sizeValue = 0;

    void push(int x)
    {
        Node *newNode = new Node(x);
        if (start == nullptr)
        {
            start = newNode;
            end = newNode;
        }
        else
        {
            end->next = newNode;
            end = newNode;
        }
        sizeValue++;
    }

    void pop()
    {
        if (start == nullptr)
        {
            throw runtime_error("Queue is empty");
        }
        Node *temp = start;
        start = start->next;
        delete temp;
        sizeValue--;
    }

    int top()
    {
        if (start == nullptr)
        {
            throw runtime_error("Queue is empty");
        }
        return start->val;
    }

    int size()
    {
        return sizeValue;
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.top() << "\n";
    q.pop();
    cout << q.top() << "\n";
    q.pop();
    cout << q.top() << "\n";
    q.pop();
    return 0;
}