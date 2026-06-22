#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode *back;

    ListNode(int val)
    {
        data = val;
        next = nullptr;
        back = nullptr;
    }
};

ListNode *convertArrToDLL(vector<int> &arr)
{
    ListNode *head = new ListNode(arr[0]);
    ListNode *prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *temp = new ListNode(arr[i]);
        prev->next = temp;
        temp->back = prev;
        prev = temp;
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

ListNode *insertBeforeHead(ListNode *head, int val)
{
    ListNode *newHead = new ListNode(val);
    newHead->next = head;
    head->back = newHead;
    return newHead;
}

ListNode *insertBeforeTail(ListNode *head, int val)
{
    if (head->next == nullptr)
    {
        return insertBeforeHead(head, val);
    }
    ListNode *tail = head;

    while (tail->next)
    {
        tail = tail->next;
    }

    ListNode *prev = tail->back;
    ListNode *newNode = new ListNode(val);
    newNode->back = prev;
    newNode->next = tail;
    prev->next = newNode;
    tail->back = newNode;
    return head;
}

ListNode *insertBeforeKthElement(ListNode *head, int val, int k)
{
    if (k == 1)
    {
        return insertBeforeHead(head, val);
    }

    ListNode *temp = head;
    int cnt = 0;

    while (temp)
    {
        cnt++;
        if (k == cnt)
            break;
        temp = temp->next;
    }

    ListNode *prev = temp->back;
    ListNode *newNode = new ListNode(val);
    newNode->back = prev;
    newNode->next = temp;
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

void insertBeforeNode(ListNode *node, int val)
{
    ListNode *prev = node->back;
    ListNode *newNode = new ListNode(val);
    newNode->back = prev;
    newNode->next = node;
    prev->next = newNode;
    node->back = newNode;
}
int main()
{
    vector<int> arr = {10, 20, 30, 40, 50};

    // Array to DLL conversion
    ListNode *head = convertArrToDLL(arr);

    // print the elements of doubly linkedlist
    printList(head);

    // insert newHead in the doubly linkedlist
    head = insertBeforeHead(head, 5);
    printList(head);

    // insert newNode before tail in the doubly linkedlist
    head = insertBeforeTail(head, 45);
    printList(head);

    // insert newNode before the kth element in the doubly linkedlist
    head = insertBeforeKthElement(head, 35, 5);
    printList(head);

    // insert element before given node on the doubly linkedlist
    insertBeforeNode(head->next->next->next,25);
    printList(head);
    return 0;
}