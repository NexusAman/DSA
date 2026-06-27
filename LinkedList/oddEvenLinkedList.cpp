#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

ListNode *convertArrToLL(vector<int> &arr)
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
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

/*
// Brute force approach
ListNode *oddEvenList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *temp = head;
    vector<int> arr;

    while (temp != nullptr && temp->next != nullptr)
    {
        arr.push_back(temp->val);
        temp = temp->next->next;
    }
    if (temp)
    {
        arr.push_back(temp->val);
    }

    temp = head->next;
    while (temp != nullptr && temp->next != nullptr)
    {
        arr.push_back(temp->val);
        temp = temp->next->next;
    }
    if (temp)
        arr.push_back(temp->val);

    int i = 0;
    temp = head;

    while (temp)
    {
        temp->val = arr[i];
        i++;
        temp = temp->next;
    }
    return head;
}
*/

ListNode *oddEvenList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenHead = head->next;

    while (even != nullptr && even->next != nullptr)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    // Array to LL conversion
    ListNode *head = convertArrToLL(arr);
    ListNode *temp = head;

    printList(head);

    // Odd Even List generation
    head = oddEvenList(head);
    printList(head);
    return 0;
}