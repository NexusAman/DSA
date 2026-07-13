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

Node *deleteAllOccurOfX(Node *head, int x)
{
    if (head == nullptr)
        return nullptr;

    Node *temp = head;

    while (temp)
    {
        if (temp->data == x)
        {
            if (temp == head)
            {
                head = temp->next;
            }
            Node *prevNode = temp->prev;
            Node *nextNode = temp->next;
            if (prevNode != nullptr)
                prevNode->next = nextNode;
            if (nextNode != nullptr)
                nextNode->prev = prevNode;
            delete temp;
            temp = nextNode;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 1, 4};
    Node *head = convertArrToDLL(arr);
    printList(head);

    // deleting the occurences of key in DLL
    int x = 1;
    head = deleteAllOccurOfX(head, x);
    printList(head);
    return 0;
}
