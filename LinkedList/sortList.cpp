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
// Brute force approach
ListNode *sortList(ListNode *head)
{
    ListNode *temp = head;
    vector<int> arr;

    while (temp)
    {
        arr.push_back(temp->val);
        temp = temp->next;
    }

    sort(arr.begin(), arr.end());

    temp = head;
    int i = 0;
    while (temp && i < arr.size())
    {
        temp->val = arr[i];
        i++;
        temp = temp->next;
    }
    return head;
}
*/
ListNode *findMiddle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode *mergeList(ListNode *head1, ListNode *head2)
{
    ListNode *dummyNode = new ListNode(-1);
    ListNode *temp = dummyNode;

    while (head1 != nullptr && head2 != nullptr)
    {
        if (head1->val < head2->val)
        {
            temp->next = head1;
            temp = temp->next;
            head1 = head1->next;
        }
        else
        {
            temp->next = head2;
            temp = temp->next;
            head2 = head2->next;
        }
    }

    if (head1)
    {
        temp->next = head1;
    }
    else
    {
        temp->next = head2;
    }
    return dummyNode->next;
}

ListNode *sortList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *middle = findMiddle(head);
    ListNode *leftHead = head;
    ListNode *rightHead = middle->next;
    middle->next = nullptr;
    leftHead = sortList(leftHead);
    rightHead = sortList(rightHead);
    return mergeList(leftHead, rightHead);
}

int main()
{
    vector<int> arr = {4, 2, 1, 3};
    ListNode *head = convertArrToLL(arr);
    printList(head);

    // sorting the linked list
    head = sortList(head);
    printList(head);
    return 0;
}