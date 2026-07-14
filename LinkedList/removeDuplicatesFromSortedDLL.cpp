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
Node *removeDuplicates(Node *headRef)
{
    // code here
    Node *temp = headRef;
    set<int> s;

    while (temp)
    {
        s.insert(temp->data);
        temp = temp->next;
    }

    Node *head = nullptr;
    Node *tail = nullptr;

    for (auto x : s)
    {
        Node *newNode = new Node(x);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = tail->next;
        }
    }
    return head;
}
*/
Node *removeDuplicates(Node *headRef)
{
    if (headRef == nullptr || headRef->next == nullptr)
        return headRef;
    Node *temp = headRef->next;

    while (temp)
    {
        if (temp->prev->data == temp->data)
        {
            Node *frontNode = temp->next;
            Node *prevNode = temp->prev;
            if (frontNode)
            {
                frontNode->prev = prevNode;
            }
            prevNode->next = frontNode;
            delete temp;
            temp = frontNode;
        }
        else
        {
            temp = temp->next;
        }
    }
    return headRef;
}

int main()
{
    vector<int> arr = {1, 1, 1, 2, 3, 4};
    Node *head = convertArrToDLL(arr);
    printList(head);

    // remove duplicates from sorted DLL
    head = removeDuplicates(head);
    printList(head);
    return 0;
}