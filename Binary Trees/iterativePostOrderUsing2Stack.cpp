#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

vector<int> postorderTraversal(Node *root)
{
    vector<int> postorder;

    if (root == nullptr)
        return postorder;

    stack<Node *> st1, st2;
    // Node* node = root;
    st1.push(root);

    while (!st1.empty())
    {
        Node* node = st1.top();
        st1.pop();
        st2.push(node);

        if(node->left) st1.push(node->left);
        if(node->right) st2.push(node->right);
    }

    while (!st2.empty())
    {
        Node* node = st2.top();
        st2.pop();
        postorder.push_back(node->val);
    }

    return postorder;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    vector<int> ans = postorderTraversal(root);

    for (auto val : ans)
    {
        cout << val << " ";
    }

    return 0;
}