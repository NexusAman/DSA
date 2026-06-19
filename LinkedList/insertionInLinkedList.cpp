#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode(int val)
    {
        data = val;
        next = nullptr;
    }
};

ListNode *convertArrToALL(vector<int> &arr)
{
    ListNode *head = new ListNode(arr[0]);
    ListNode *temp = head;

    for (int i = 1; i < arr.size(); i++)
    {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

void printList(ListNode *head)
{
    ListNode *temp = head;

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteList(ListNode *head)
{

    while (head)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
}

ListNode *insertHead(ListNode *head, int val)
{
    ListNode *temp = new ListNode(val);
    temp->next = head;
    return temp;
}

ListNode *insertTail(ListNode *head, int val)
{
    if (head == nullptr)
        return new ListNode(val);

    ListNode *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    ListNode *tail = new ListNode(val);
    temp->next = tail;
    return head;
}

ListNode *insertK(ListNode *head, int el, int k)
{
    if (k == 1)
    {
        ListNode *newNode = new ListNode(el);
        newNode->next = head;
        return newNode;
    }

    int cnt = 0;
    ListNode *temp = head;

    while (temp)
    {
        cnt++;
        if (cnt == k - 1)
        {
            ListNode *newNode = new ListNode(el);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

ListNode *insertBeforeValue(ListNode *head, int el, int val)
{
    if (head == nullptr)
        return nullptr;

    if (head->data == val)
    {
        ListNode *newNode = new ListNode(el);
        newNode->next = head;
        return newNode;
    }

    ListNode *temp = head;

    while (temp->next)
    {
        if (temp->next->data == val)
        {
            ListNode *newNode = new ListNode(el);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {10, 20, 30, 40};
    ListNode *head = convertArrToALL(arr);

    // print elements of the linkedlist
    printList(head);

    // insert node before head in the linkedlist
    int val = 5;
    head = insertHead(head, val);
    printList(head);

    // insert node after tail in the linkedlist
    val = 50;
    insertTail(head, val);
    printList(head);

    // insert node at kth position in the linkedlist
    int el = 35;
    head = insertK(head, el, 5);
    printList(head);

    // insert node before given value in the linkedlist
    el = 45;
    val = 50;
    head = insertBeforeValue(head, el, val);
    printList(head);

    // delete elements of the linkedlist
    deleteList(head);
    return 0;
}