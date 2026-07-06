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
ListNode *reverseList(ListNode *head)
{
    ListNode *temp = head;
    stack<int> st;

    while (temp)
    {
        st.push(temp->val);
        temp = temp->next;
    }

    temp = head;
    while (temp)
    {
        temp->val = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}
*/

// Optimal approach (iterative)
ListNode *reverseList(ListNode *head)
{
    ListNode *temp = head;
    ListNode *prev = NULL;

    while (temp)
    {
        ListNode *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

ListNode *reverseListRecursive(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode *newHead = reverseListRecursive(head->next);
    ListNode *front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode *head = convertArrToLL(arr);
    printList(head);

    // linked list reversal
    head = reverseList(head);
    printList(head);

    // linked list reversal using recursion
    head = convertArrToLL(arr);
    head = reverseListRecursive(head);
    printList(head);
    return 0;
}