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
        temp->back = prev;
        prev->next = temp;
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

ListNode *removeHead(ListNode *head)
{
    if (head == nullptr)
        return nullptr;

    if (head->next == nullptr)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    ListNode *prev = head;
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;

    delete prev;
    return head;
}

ListNode *removeTail(ListNode *head)
{
    if (head == nullptr)
        return nullptr;

    if (head->next == nullptr)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    ListNode *tail = head;

    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    ListNode *newTail = tail->back;

    newTail->next = nullptr;
    tail->back = nullptr;

    delete tail;
    return head;
}

ListNode *removeKthElement(ListNode *head, int k)
{
    if (head == nullptr)
        return nullptr;

    ListNode *temp = head;
    int cnt = 0;

    while (temp)
    {
        cnt++;
        if (cnt == k)
            break;
        temp = temp->next;
    }

    ListNode *prev = temp->back;
    ListNode *front = temp->next;

    if (prev == nullptr && front == nullptr)
    {
        delete temp;
        return nullptr;
    }
    else if (prev == nullptr)
    {
        return removeHead(head);
    }
    else if (front == nullptr)
    {
        return removeTail(head);
    }
    else
    {
        prev->next = front;
        front->back = prev;

        temp->next = nullptr;
        temp->back = nullptr;
        delete temp;
    }
    return head;
}

void removeNode(ListNode *temp)
{
    ListNode *prev = temp->back;
    ListNode *front = temp->next;

    if (front == nullptr)
    {
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return;
    }
    prev->next = front;
    front->back = prev;

    temp->next = nullptr;
    temp->back = nullptr;

    delete temp;
}

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50};

    // Array to DLL conversion
    ListNode *head = convertArrToDLL(arr);

    // print the elements of doubly linkedlist
    printList(head);

    // remove head of the doubly linkedlist
    head = removeHead(head);
    printList(head);

    // remove tail of the doubly linkedlist
    head = removeTail(head);
    printList(head);

    // remove kth element from the doubly linkedlist
    int k = 2;
    head = removeKthElement(head, k);
    printList(head);

    // remove given node from the doubly linkedlist
    removeNode(head->next);
    printList(head);

    return 0;
}