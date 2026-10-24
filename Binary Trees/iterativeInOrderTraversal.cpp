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

vector<int> inorderTraversal(Node *root)
{
    vector<int> inorder;

    if (root == nullptr)
        return inorder;

    stack<Node *> st;
    Node* node = root;

    while (node != nullptr || !st.empty())
    {
        while (node != nullptr)
        {
            st.push(node);
            node = node->left;
        }

        node = st.top();
        st.pop();

        inorder.push_back(node->val);

        node = node->right;
    }

    return inorder;
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

    vector<int> ans = inorderTraversal(root);

    for (auto val : ans)
    {
        cout << val << " ";
    }

    return 0;
}