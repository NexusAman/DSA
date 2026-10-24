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

vector<int> preorderTraversal(Node* root){
    vector<int> preorder;

    if(root == nullptr) return preorder;

    stack<Node*> st;
    st.push(root);

    while (!st.empty())
    {
        Node* node = st.top();
        st.pop();
        preorder.push_back(node->val);

        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);
    }
    
    return preorder;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(6);

    vector<int> ans = preorderTraversal(root);

    for(auto val : ans){
        cout << val << " ";
    }

    return 0;
}