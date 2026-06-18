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

ListNode *convertArrToAll(vector<int> &arr)
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

ListNode *removeHead(ListNode *head)
{
    if (head == nullptr)
        return nullptr;
    ListNode *temp = head;
    head = head->next;
    delete temp;
    return head;
}

ListNode *removeTail(ListNode *head)
{
    if (head == nullptr)
        return nullptr;
    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    ListNode *temp = head;

    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

ListNode *deleteK(ListNode *head, int k)
{
    if (head == nullptr)
        return nullptr;

    if (k == 1)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int cnt = 0;
    ListNode *temp = head;
    ListNode *prev = nullptr;

    while (temp)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

ListNode *removeElement(ListNode *head, int el)
{
    if (head == nullptr)
        return nullptr;

    if (head->data == el)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    ListNode *temp = head;
    ListNode *prev = nullptr;
    while (temp)
    {
        if (temp->data == el)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50};
    ListNode *head = convertArrToAll(arr);

    // print the elements of linkedlist
    printList(head);

    // remove head of the linkedlist
    head = removeHead(head);
    printList(head);

    // remove tail of the linkedlist
    head = removeTail(head);
    printList(head);

    // remove kth element from the linkedlist
    int k = 2;
    head = deleteK(head, k);
    printList(head);

    // remove element node from the linkedlist
    int el = 40;
    head = removeElement(head, el);
    printList(head);

    // delete the elements of the linkedlist
    deleteList(head);
    return 0;
}