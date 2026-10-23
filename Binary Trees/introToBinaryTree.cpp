#include <bits/stdc++.h>
using namespace std;

// Binary Tree structure
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

int main()
{
    // Initilize and allocate memory for tree nodes
    Node *firstNode = new Node(2);
    Node *secondNode = new Node(3);
    Node *thirdNode = new Node(4);
    Node *fourthNode = new Node(5);

    // Connect binary tree nodes
    firstNode->left = secondNode;
    firstNode->right = thirdNode;
    secondNode->left = fourthNode;
    return 0;
}