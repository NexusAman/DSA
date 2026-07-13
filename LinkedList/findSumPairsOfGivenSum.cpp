#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int x)
    {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

Node *convertArrToDLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = nullptr;
        temp = temp->next;
    }
    return head;
}

void printList(Node *head)
{
    Node *temp = head;

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

/*
// Brute force approach
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    vector<pair<int, int>> sumPairs;
    Node *temp1 = head;
    while (temp1)
    {
        Node *temp2 = temp1->next;
        while (temp2 != nullptr && temp1->data + temp2->data <= target)
        {
            if (temp1->data + temp2->data == target)
            {
                sumPairs.push_back({temp1->data, temp2->data});
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return sumPairs;
}
*/
Node *findTail(Node *head)
{
    Node *tail = head;

    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    return tail;
}

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    Node *left = head;
    Node *right = findTail(head);
    vector<pair<int, int>> sumPairs;

    while (left->data < right->data)
    {
        if (left->data + right->data == target)
        {
            sumPairs.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if (left->data + right->data < target)
        {
            left = left->next;
        }
        else
        {
            right = right->prev;
        }
    }
    return sumPairs;
}

int main()
{
    vector<int> arr = {1, 2, 4, 5, 6, 8, 9};
    Node *head = convertArrToDLL(arr);
    printList(head);

    // finding sum pairs of given sum
    int target = 7;
    vector<pair<int, int>> sumPairs = findPairsWithGivenSum(head, target);
    for (auto val : sumPairs)
    {
        cout << val.first << "," << val.second << endl;
    }
    return 0;
}