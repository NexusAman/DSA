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

class Stack
{
public:
    Node *topNode = nullptr;
    int sizeValue = 0;

    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = topNode;
        topNode = temp;
        sizeValue++;
    }

    void pop()
    {
        if (topNode == nullptr)
            return;

        Node *temp = topNode;
        topNode = topNode->next;
        delete temp;
        sizeValue--;
    }

    int top()
    {
        if (topNode == nullptr)
            throw runtime_error("Stack is empty");

        return topNode->val;
    }

    int size()
    {
        return sizeValue;
    }
};

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.pop();

    return 0;
}