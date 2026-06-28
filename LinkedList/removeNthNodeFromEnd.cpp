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
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *temp = head;
    int cnt = 0;

    while (temp)
    {
        cnt++;
        temp = temp->next;
    }

    if (cnt == n)
    {
        ListNode *newHead = head->next;
        delete head;
        return newHead;
    }

    int res = cnt - n;
    temp = head;

    while (temp)
    {
        res--;
        if (res == 0)
        {
            break;
        }
        temp = temp->next;
    }

    ListNode *deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;

    return head;
}
*/

ListNode *removeNthFromEnd(ListNode *head, int n){
    ListNode *fast = head;
    ListNode *slow = head;

    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    if(fast == nullptr){
        ListNode* newHead = head->next;
        delete head;
        return newHead;
    }

    while (fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }

    ListNode* deleteNode = slow->next;
    slow->next = slow->next->next;
    delete deleteNode;

    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    // Array to LL conversion
    ListNode *head = convertArrToLL(arr);
    ListNode *temp = head;
    printList(head);

    // remove nth node from end of the linked list
    int n = 2;
    head = removeNthFromEnd(head, n);
    printList(head);
    return 0;
}