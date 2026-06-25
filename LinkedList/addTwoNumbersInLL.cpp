#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode()
    {
        val = 0;
        next = nullptr;
    }
    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
    ListNode(int x, ListNode *next)
    {
        val = x;
        next = next;
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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *t1 = l1;
    ListNode *t2 = l2;
    ListNode *dummyNode = new ListNode(-1);
    ListNode *current = dummyNode;
    int carry = 0;

    while (t1 != nullptr || t2 != nullptr)
    {
        int sum = carry;
        if (t1)
        {
            sum += t1->val;
        }
        if (t2)
        {
            sum += t2->val;
        }
        ListNode *newNode = new ListNode(sum % 10);
        carry = sum / 10;

        current->next = newNode;
        current = current->next;

        if (t1)
        {
            t1 = t1->next;
        }
        if (t2)
        {
            t2 = t2->next;
        }
    }
    if (carry)
    {
        ListNode *newNode = new ListNode(carry);
        current->next = newNode;
    }
    return dummyNode->next;
}

int main()
{
    vector<int> arr1 = {2, 4, 3};
    vector<int> arr2 = {5, 6, 4};

    // Arr to linked list conversion
    ListNode *head1 = convertArrToLL(arr1);
    ListNode *head2 = convertArrToLL(arr2);

    printList(head1);
    printList(head2);

    // Add two numbers in linked list
    ListNode *head = addTwoNumbers(head1, head2);
    printList(head);
}