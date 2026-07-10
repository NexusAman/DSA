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
        ListNode *newNode = new ListNode(arr[i]);
        temp->next = newNode;
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
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == nullptr && list2 == nullptr)
        return nullptr;
    ListNode *temp1 = list1;
    ListNode *temp2 = list2;
    vector<int> arr;

    while (temp1)
    {
        arr.push_back(temp1->val);
        temp1 = temp1->next;
    }

    while (temp2)
    {
        arr.push_back(temp2->val);
        temp2 = temp2->next;
    }

    sort(arr.begin(), arr.end());

    ListNode *newHead = convertArrToLL(arr);
    return newHead;
}
*/

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == nullptr && list2 == nullptr)
        return nullptr;
    ListNode *t1 = list1;
    ListNode *t2 = list2;
    ListNode *dummyNode = new ListNode(-1);
    ListNode *temp = dummyNode;

    while (t1 != nullptr && t2 != nullptr)
    {
        if (t1->val < t2->val)
        {
            temp->next = t1;
            temp = temp->next;
            t1 = t1->next;
        }
        else
        {
            temp->next = t2;
            temp = temp->next;
            t2 = t2->next;
        }
    }

    if (t1)
    {
        temp->next = t1;
    }
    else
    {
        temp->next = t2;
    }
    return dummyNode->next;
}

int main()
{
    vector<int> arr1 = {1, 2, 4};
    ListNode *list1 = convertArrToLL(arr1);
    printList(list1);

    vector<int> arr2 = {1, 3, 4};
    ListNode *list2 = convertArrToLL(arr2);
    printList(list2);

    ListNode *head = mergeTwoLists(list1, list2);
    printList(head);
    return 0;
}