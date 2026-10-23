#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int key)
    {
        data = key;
        left = nullptr;
        right = nullptr;
    }
};

// Preorder traversal
void preOrder(Node *node)
{
    if (node == nullptr)
    {
        return;
    }

    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    preOrder(root);

    return 0;
}