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

ListNode *sortList(ListNode *head)
{
    ListNode *temp = head;
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;

    while (temp)
    {
        if (temp->val == 0)
        {
            cnt0++;
        }
        else if (temp->val == 1)
        {
            cnt1++;
        }
        else
        {
            cnt2++;
        }
        temp = temp->next;
    }

    temp = head;
    while (temp)
    {
        if (cnt0)
        {
            temp->val = 0;
            cnt0--;
        }
        else if (cnt1)
        {
            temp->val = 1;
            cnt1--;
        }
        else
        {
            temp->val = 2;
            cnt2--;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {1, 0, 2, 0, 1};

    // Array to LL conversion
    ListNode *head = convertArrToLL(arr);
    ListNode *temp = head;

    printList(head);

    // sort 0s 1s and 2s in linked list
    head = sortList(head);
    printList(head);
    return 0;
}